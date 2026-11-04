# Day 8 Mandatory Challenges

These are the final two interview drills. Treat each as an independent timed exercise.

## Challenge 1 — LRU cache design (35 minutes)
Design and implement an LRU cache for integer keys and values with `get(key)` and `put(key, value)`. Target average O(1) operations. You may use `std::list` and `std::unordered_map`.

**Concept.** An LRU (least recently used) cache holds at most `capacity` entries. When it is full and a new key arrives, it evicts the entry that has gone longest without being read or written. Robotics example: keeping the most recently used map tiles in memory. Two jobs must both be O(1):
- *find a key*: a hash map from key to entry;
- *track recency*: a doubly linked list ordered from most to least recent. Moving an entry to the front, or removing the entry at the back, is O(1) once you hold its position.

Combining them, so the map can tell you an entry's position in the list, is the core of the design. `std::list::splice` moves an element within a list without copying it.

Acceptance:
- Capacity is positive.
- `get` returns -1 for a missing key.
- Accessing a key makes it most recently used.
- Inserting beyond capacity evicts the least recently used key.
- Explain why the map stores list iterators.

## Challenge 2 — Explain a concurrency design (25 minutes)
Given a sensor callback that receives frames at 30 Hz and a perception worker that processes at 10 Hz, propose a bounded-buffer strategy.

Acceptance:
- State whether to block, drop oldest, or drop newest and justify it.
- Explain how you prevent unbounded memory growth.
- Explain ownership of a frame while queued and processed.
- Explain how shutdown is coordinated.
