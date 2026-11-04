# Day 5 Cumulative Exam

**Time limit:** 50 minutes. **Total:** 30 marks.

## Part A — Coding (15 marks, 25 minutes)
Implement a function that launches two threads. Each thread increments its own local counter 10,000 times, then the function returns the combined total. Join both threads before returning.

Expected result: 20,000. Use a safe design; do not share a non-atomic counter between threads without synchronisation.

## Part B — Debugging (5 marks, 10 minutes)
Explain the issue:
```cpp
std::mutex mutex;
int count = 0;

void increment() {
    count++;
}
```
Several threads call `increment()` concurrently. Show the smallest correct locking change.

## Part C — Technical questions (10 marks, 15 minutes)
1. What does `std::move` do?
2. What is the ownership model of `unique_ptr`?
3. What is a data race?
4. Why use a mutex?
5. What does `lock_guard` guarantee?
6. Why must a joinable thread be joined or detached?
7. What is a condition variable used for?
8. What is a spurious wakeup?
9. Name one common cause of deadlock.
10. Why should critical sections be short?
