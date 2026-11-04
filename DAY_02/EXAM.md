# Day 2 Cumulative Exam

**Time limit:** 50 minutes. **Total:** 30 marks. Do not open instructor solutions.

## Part A — Coding (15 marks, 25 minutes)

Implement a `Motor` class with:
- private `name_` and `speed_` members;
- constructor accepting a name and setting speed to zero;
- `bool set_speed(double value)` accepting only values in `[-1.0, 1.0]`;
- `double speed() const`;
- `std::string name() const`.

Invalid updates must leave the previous speed unchanged. Demonstrate the class in `main`.

## Part B — Debugging (5 marks, 10 minutes)

Consider:

```cpp
class Base {
public:
    ~Base() = default;
};

class Derived : public Base {
public:
    ~Derived() {
        // imagine this releases a resource
    }
};

Base* object = new Derived();
delete object;
```

Explain the problem and show the smallest appropriate correction. You may assume polymorphic deletion through `Base*` is intended.

## Part C — Technical questions (10 marks, 15 minutes)

Answer briefly:
1. What is the difference between a class and an object?
2. What is the purpose of a constructor?
3. When does a local stack object get destroyed?
4. Explain RAII in one or two sentences.
5. What does `std::unique_ptr` guarantee?
6. Why can't a `unique_ptr` be copied?
7. What does `std::move` do at a high level?
8. What is the risk of copying a raw owning pointer?
9. When is a virtual destructor needed?
10. What is the Rule of Zero?

## Self-grading
- Coding: encapsulation, validation, correct interface, compiles.
- Debugging: identifies non-virtual base destructor and fixes it.
- Questions: one mark per accurate answer.
