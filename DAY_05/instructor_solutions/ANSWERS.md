# Day 5 Exam — Model Answers

Use these after you have finished the exam. An answer earns the mark if it contains the **key point** in bold.

## Part A — Coding
See `combined_total` in `solutions.cpp`. Each thread increments a variable that only it touches, and the function reads both only after `join()`, which synchronises with the thread's completion. No mutex or atomic is needed. Full marks need both joins before the return, and no shared non-atomic counter.

## Part B — Debugging
**The mutex exists but is never locked.** `count++` is a read-modify-write. Concurrent unsynchronised writes are a data race, which is undefined behaviour, and in practice increments are lost.

Smallest correct change:
```cpp
void increment() {
    std::lock_guard<std::mutex> lock(mutex);
    count++;
}
```
Declaring `std::atomic<int> count{0};` is also correct for a lone counter.

## Part C — Technical questions
1. **It is a cast to an rvalue reference, which lets move operations be selected.** It does not move any data by itself.
2. **Exclusive ownership**: it is non-copyable but movable, and it deletes the object when the owning pointer is destroyed or reset.
3. **Two threads access the same memory location concurrently without synchronisation, and at least one access is a write.** It is undefined behaviour.
4. **Mutual exclusion**: only one thread at a time runs the critical section. Unlocking and then locking also makes one thread's writes visible to the next.
5. **The mutex is unlocked when the guard leaves scope on every path**, including early returns and exceptions.
6. **Destroying a joinable `std::thread` calls `std::terminate`.** `join` waits for the thread to finish. `detach` gives up any way to know when it ends, and it may outlive data it references.
7. **To block a thread until another thread signals that a condition on shared, mutex-protected state may have changed**, without busy-waiting.
8. **`wait` returns without a matching notify** (or another thread consumed the condition first), so you must re-check the predicate. `cv.wait(lock, predicate)` does this for you.
9. Any one of: **two threads locking two mutexes in opposite order**; locking the same non-recursive mutex twice; waiting or joining while holding a lock another thread needs.
10. **While the lock is held every other thread that needs it is blocked**, so long critical sections add latency and contention. Never do I/O or other blocking calls under a lock.
