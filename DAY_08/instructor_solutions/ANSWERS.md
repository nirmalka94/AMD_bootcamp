# Day 8 — Reference Solutions and Exam Model Answers

Code for the mock coding round, the LRU cache and the exam is in `mock_coding_solution.cpp`.

## Challenge 1 — LRU cache
`std::list` holds `(key, value)` pairs in recency order, and `std::unordered_map` maps each key to its list iterator.
- `get`: look up the key in the map in average O(1), then `splice` the node to the front in O(1).
- `put`: update and splice if the key is present. Otherwise, if the cache is full, erase `back()` from both containers, then `emplace_front` and store the iterator.

**Why the map stores list iterators:** without them, finding the node to move or erase means an O(n) list search. `std::list` iterators stay valid when other elements are inserted, erased or spliced, so the stored iterators never dangle. A `std::vector` does not give that guarantee.

## Challenge 2 — 30 Hz camera, 10 Hz perception (model answer)
- **Policy: drop oldest, with a small capacity (1–2 frames).** Perception should work on the freshest frame. Blocking would stall the sensor callback and the executor behind it, and dropping the newest frame keeps stale data. About two of every three frames are dropped; count them as a metric.
- **Bounded memory:** the buffer has a fixed capacity, and pushing into a full buffer evicts the oldest frame. Memory use is therefore at most `capacity × frame size`, whatever the rate mismatch.
- **Ownership:** the callback wraps the frame in `std::unique_ptr<Frame>` and moves it into the queue. In ROS, keeping the message's `ConstSharedPtr` avoids a copy. The worker moves the frame out when it pops, and owns it exclusively while processing. An evicted frame is destroyed by the queue. No frame is ever mutated by two threads.
- **Shutdown:** stop the subscription first. Then call `close()`, which sets a flag under the mutex and calls `notify_all`. The worker's wait predicate includes the flag, so it wakes, finishes or discards the remaining frames, and exits. `join()` the worker before destroying the queue. `push` after `close` returns false.
- **Extra credit:** also stamp each frame and skip any older than a latency budget; measure queue depth and frame age.

## Exam Part A — Coding
Count with `unordered_map`, copy the `(value, count)` pairs into a vector, and sort by count descending, then value ascending. Take the first `k`. Time is O(n + m log m) and space is O(m), where m is the number of distinct values. A heap of size k gives O(n + m log k), which is worth mentioning but not required.

## Exam Part B — Debugging/design
**The local variable is destroyed when the function returns, so the returned reference dangles.** Using it is undefined behaviour, even if it appears to work.
- If the caller needs its own copy, **return by value**. Copy elision and move semantics make this cheap.
- If the caller only needs to look, **return a reference, pointer or `std::string_view` to something that outlives the call**, such as a member or an object passed in by the caller, and document that lifetime.
- If the value may be absent, return `std::optional<T>`.

## Part C — Technical questions
1. **A resource's lifetime is tied to an object's lifetime**: it is acquired in the constructor and released in the destructor, so cleanup happens on every exit path.
2. **When derived objects may be deleted through a base-class pointer.**
3. **A vector is contiguous, with O(1) index access and the best iteration speed; an unordered_map gives average O(1) lookup by key**, with no ordering and more memory per element.
4. For example **maximum sum over k consecutive sensor samples, or the longest substring without repeats**: update the window incrementally instead of recomputing it.
5. **Unsynchronised concurrent access to the same memory location, where at least one access is a write.** It is undefined behaviour.
6. **It waits for ready work and dispatches subscription, timer and service callbacks** on its thread or threads.
7. **Throughput is items per unit time; latency is the time per item end to end.**
8. **Measure before guessing**: per-stage timing, per-thread CPU, queue depth and frame age, memory bandwidth. Then form a hypothesis, isolate it with an experiment, and confirm it.
9. **While it blocks, the executor thread cannot run other callbacks**, so timers slip, messages are dropped and service calls time out.
10. Personal answer. Full marks need **context, the decision, the alternative considered, the trade-off, and the evidence or outcome**.
