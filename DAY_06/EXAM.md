# Day 6 Cumulative Exam

**Time limit:** 50 minutes. **Total:** 30 marks.

## Part A — Coding (15 marks, 25 minutes)
Write a class outline for a ROS 2 node that subscribes to `geometry_msgs/msg/Twist` on `/cmd_vel` and stores the latest linear-x and angular-z values. Include the constructor, subscription member, and callback signature/body. You may write a compilable code fragment rather than a full package. The provided package does not depend on `geometry_msgs`; state the lines you would add to `package.xml` and `CMakeLists.txt`.

## Part B — Debugging (5 marks, 10 minutes)
A subscription callback performs a blocking 5-second operation before returning. Explain how this can affect other callbacks when using a single-threaded executor. Give one design improvement.

## Part C — Technical questions (10 marks, 15 minutes)
1. What is a ROS 2 node?
2. What is the difference between a topic and a service?
3. What is the role of a publisher?
4. What is the role of a subscription callback?
5. What does a timer do?
6. What is an executor?
7. What is the main difference between single- and multi-threaded executors?
8. Why can shared state need a mutex with concurrent callbacks?
9. What does QoS control at a high level?
10. When would an action be more appropriate than a service?
