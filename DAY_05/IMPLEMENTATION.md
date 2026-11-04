# Day 5 Implementation — Bounded Sensor Queue

## Goal
Complete `starter/sensor_queue.cpp`.

## Step 1 — Queue contract
Implement a queue with:
- fixed positive capacity;
- `push(value)` that waits while full;
- `pop(value)` that waits while empty;
- `close()` that wakes waiting threads and allows the consumer to exit once the queue is drained.

## Step 2 — Synchronise state
Protect the queue, closed flag, and all checks/updates with one mutex. Use two condition variables: one for data availability and one for free capacity.

## Step 3 — Implement `push`
Wait until the queue has space or is closed. If closed, return false. Otherwise enqueue and notify a consumer.

## Step 4 — Implement `pop`
Wait until the queue has data or is closed. If the queue is empty after closure, return false. Otherwise copy/pop one item and notify a producer.

## Step 5 — Run producer and consumer
The supplied main launches one producer and one consumer. Ensure the producer calls `close()` when it has finished. Join both threads.

## Build
```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -pthread sensor_queue.cpp -o sensor_queue
./sensor_queue
```

## Acceptance criteria
- Every produced sample is consumed exactly once.
- No busy-wait loop.
- No data race on queue state.
- The program exits even after the queue is closed.
- No detached threads.
- The final line reads `Day 5 sensor queue: 5/5 checks passed`.
- A ThreadSanitizer build reports no data race:
  ```bash
  g++ -std=c++17 -g -O1 -fsanitize=thread -pthread sensor_queue.cpp -o sensor_queue_tsan
  ./sensor_queue_tsan    # if it fails with "unexpected memory mapping": setarch "$(uname -m)" -R ./sensor_queue_tsan
  ```

## Explain aloud
What would happen if the queue were accessed without a mutex? Why does the condition-variable wait use a predicate?
