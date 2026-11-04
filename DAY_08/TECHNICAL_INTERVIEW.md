# Technical Interview Question Bank

Use these as oral prompts. Do not memorise scripts; answer with concise definitions and a concrete example.

## C++ language and design
1. Difference between pointer and reference.
2. `const T*`, `T* const`, and `const T* const`.
3. Stack versus heap/dynamic storage.
4. Constructor, destructor, copy constructor, move constructor.
5. RAII and Rule of Zero.
6. Shallow copy versus deep copy.
7. `unique_ptr` versus `shared_ptr` versus `weak_ptr`.
8. Virtual function and virtual destructor.
9. Object slicing.
10. Why prefer composition over inheritance in many designs?

## STL and algorithms
1. Vector versus list versus deque.
2. Map versus unordered_map.
3. Iterator invalidation in vector.
4. Complexity of sorting, binary search, and hash lookup.
5. When to use a queue, stack, set, or priority queue?

## Concurrency
1. What is a race condition/data race?
2. Mutex versus atomic.
3. Lock guard versus unique lock.
4. Condition-variable predicate and spurious wakeups.
5. Deadlock causes and prevention.
6. How do you shut down worker threads safely?

## ROS 2
1. Node, topic, service, and action.
2. Executor and callback group.
3. QoS reliability and durability.
4. What happens when a callback blocks?
5. When would you use a multi-threaded executor?
6. How do you keep callbacks responsive?

## Robotics software engineering
1. How do you design a sensor-to-control data pipeline?
2. How do you handle stale sensor data?
3. How do you diagnose CPU saturation?
4. How do you reduce memory copies?
5. How do you make a component fault-tolerant?
6. How do you measure end-to-end latency?
7. How would you profile an embedded target with limited tools?

## Behavioural/project discussion
Prepare two project examples:
- one technically difficult problem you diagnosed;
- one architecture or implementation decision with a clear trade-off.

For each, explain context, constraints, your contribution, evidence, outcome, and what you would improve.
