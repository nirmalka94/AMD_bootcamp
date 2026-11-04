# Day 5 Theory — Modern C++ and Concurrency

Legend: **CORE** required; **OPTIONAL** later review.

## 1. Modern C++ habits — CORE
Use `auto` when the type is obvious from the expression. Prefer range-based loops for simple traversal. Use lambdas for short local operations passed to algorithms.

## 2. Move semantics — CORE
`std::move` is a cast that allows move operations to be selected; it does not itself move data. Moving can transfer resources from one object to another. After moving, an object remains valid but its value is unspecified unless the type documents more.

## 3. Ownership recap — CORE
- `unique_ptr`: one owner; move to transfer ownership.
- `shared_ptr`: shared ownership; reference-counted.
- `weak_ptr`: non-owning observer of a shared object.
Prefer value types and `unique_ptr`; do not introduce shared ownership without a real need.

## 4. Threads — CORE
```cpp
std::thread worker([] {
    // work
});
worker.join();
```
A joinable thread must be joined or detached before its `std::thread` object is destroyed. In this course, always join. C++20 `std::jthread` is useful but not required for the C++17 baseline.

## 5. Mutex and lock guard — CORE
A data race occurs when unsynchronised concurrent operations access the same memory and at least one is a write. Protect shared state with a mutex.

```cpp
{
    std::lock_guard<std::mutex> lock(mutex);
    shared_count++;
}
```
RAII releases the lock when the guard leaves scope, including on exceptions.

## 6. Condition variable — CORE
A condition variable lets a thread sleep until a condition may have changed. Always wait with a predicate because wakeups can be spurious.

```cpp
cv.wait(lock, [&] { return !queue.empty() || stopped; });
```

## 7. Deadlock — CORE
A deadlock can occur when threads wait indefinitely for locks held by one another. Keep critical sections short, use a consistent lock order, and avoid calling unknown code while holding a lock.

## 8. Atomics and advanced concurrency — OPTIONAL
Know that `std::atomic` supports atomic operations on suitable types. Memory ordering, lock-free algorithms, thread pools, futures, and work-stealing are REFERENCE topics for later study, not today's implementation requirements.
