# Day 5 — Modern C++ and Basic Concurrency

**Theme:** Build a bounded producer-consumer sensor pipeline and reason about ownership and synchronisation.

## Learning outcomes
- Use `auto`, range-based loops, lambdas, and move semantics appropriately.
- Distinguish `unique_ptr` and `shared_ptr` ownership.
- Launch and join a `std::thread`.
- Protect shared state with `std::mutex` and `std::lock_guard`.
- Use `std::condition_variable` for a simple blocking queue.
- Identify a data race and explain a deadlock risk.

## Main assignment
Complete a bounded, thread-safe queue and run a producer and consumer over sensor samples. Keep the design intentionally small: one producer, one consumer, fixed capacity, clean shutdown.

## Schedule (about 5.5 focused hours)
| Block | Duration | Activity |
|---|---:|---|
| 1 | 60 min | CORE theory |
| 2 | 25 min | Thread and mutex walkthrough |
| 3 | 110 min | Main assignment |
| 4 | 15 min | Break |
| 5 | 55 min | Two challenges |
| 6 | 50 min | Cumulative exam |
| 7 | 15 min | Review |

## Safety rule
Do not run detached threads. Every thread started in the assignment must be joined before shared state is destroyed.
