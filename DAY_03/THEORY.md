# Day 3 Theory — STL Containers and Algorithms

Legend: **CORE** required; **OPTIONAL** for later review.

## 1. Why the STL — CORE
The C++ Standard Template Library provides reusable containers, algorithms, and iterators. Prefer these tested abstractions over hand-written data structures for ordinary application code.

## 2. `std::vector` — CORE
A contiguous, dynamically sized sequence.
- Fast indexed access: O(1).
- Appending is amortised O(1).
- Inserting/removing in the middle is O(n).
- Reallocation may invalidate pointers, references, and iterators to its elements.

Use it when order matters and iteration is common.

## 3. `std::unordered_map` — CORE
A hash table mapping keys to values.
- Average lookup/insert/erase: O(1).
- Worst case: O(n).
- Iteration order is not a stable sorting order.

Use it for ID-to-record lookup. Use `.find()` when you need to check whether a key exists without inserting a default value.

## 4. `std::map` and `std::set` — OPTIONAL
Tree-based ordered containers. Lookup, insertion, and removal are O(log n). Use them when key order is part of the requirement.

## 5. Iterators and range-based loops — CORE
```cpp
for (const auto& robot : robots) {
    // read robot
}
```
Use `const auto&` when reading larger objects without copying. An iterator represents a position in a container and is used by many STL algorithms.

## 6. Pointer and iterator invalidation — CORE
A pointer, reference, or iterator to a vector element refers to a location inside the vector's storage. It becomes **invalid** (dangling) when that storage changes:
- `push_back`, `emplace_back`, `insert`, `resize`, or `reserve` that exceeds `capacity()` reallocates, and **every** pointer, reference, and iterator into the vector is invalidated;
- even without reallocation, `insert` and `erase` invalidate everything at or after the changed position, because elements shift;
- `clear()` invalidates everything.

This matters for today's `find_robot`, which returns a pointer into `robots_`:
```cpp
const RobotState* mapper = fleet.find_robot("R-01");
fleet.add_robot({"R-04", "Lifter", 90, true});   // may reallocate robots_
std::cout << mapper->battery_percent;            // undefined behaviour if it did
```
Using a dangling pointer is undefined behaviour. It often appears to work, which is why AddressSanitizer (Day 7) is needed to catch it.

Rules for a pointer you return from a container:
- Treat it as a short-lived view: use it immediately, and **do not keep it across any call that can modify the container**.
- Document that lifetime in the function's contract.
- If the caller needs the data later, return a copy, or look it up again by ID.
- An index is not a safe substitute: it survives reallocation but shifts after an `erase`.

Node-based containers behave differently. In `std::unordered_map` and `std::map`, pointers and references to an element stay valid until that element is erased (an `unordered_map` rehash invalidates iterators, not references). Choose the container with that in mind when other code must hold on to elements.

## 7. Standard algorithms — CORE
```cpp
std::sort(values.begin(), values.end());
auto it = std::find_if(values.begin(), values.end(),
                       [](const Robot& r) { return r.battery < 20; });
```
Know the intent and iterator range of `sort`, `find`, `find_if`, `count_if`, and `remove_if`. The erase-remove idiom is useful for removing matching vector elements.

## 8. Complexity intuition — CORE
- O(1): work does not grow with input size (idealised).
- O(log n): repeated halving/tree search.
- O(n): scan all elements.
- O(n log n): typical comparison sort.
- O(n²): nested scan over the same input.

You do not need formal proofs today. Be able to justify a container choice and identify an accidental nested loop.

## 9. Optional topics — OPTIONAL
- `std::deque`, `std::list`, `std::priority_queue`.
- Custom hash functions.
- Iterator invalidation rules for other containers beyond section 6.
- Allocators and container internals are REFERENCE only.
