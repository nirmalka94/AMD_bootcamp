# Day 2 Exam — Model Answers

Use these after you have finished the exam. An answer earns the mark if it contains the **key point** in bold.

## Part A — Coding
See `Motor` in `solutions.cpp`. Full marks need: private members, an `explicit` constructor that sets speed to `0.0`, validation that leaves the old speed unchanged on rejection, and `const` accessors.

## Part B — Debugging
**`Base` has a non-virtual destructor, so `delete object` through a `Base*` is undefined behaviour.** In practice `~Derived()` does not run, and the resource it releases leaks.

Smallest fix:
```cpp
class Base {
public:
    virtual ~Base() = default;
};
```
Better still, own the object with `std::unique_ptr<Base>` so no manual `delete` is needed. The virtual destructor is still required.

## Part C — Technical questions
1. **A class is a type (the blueprint); an object is an instance of it** that occupies memory and has its own state.
2. **To establish a valid initial state**, meaning the class invariants, by initialising members and acquiring any resources the object owns.
3. **When execution leaves its enclosing scope**, including by `return` or an exception. Locals are destroyed in reverse order of construction.
4. **A resource's lifetime is tied to an object's lifetime**: acquire it in the constructor and release it in the destructor, so cleanup happens automatically on every exit path.
5. **Exactly one owner.** The managed object is deleted when that `unique_ptr` is destroyed or reset. With the default deleter it costs no more than a raw pointer.
6. **A copy would create two owners and a double delete**, so its copy constructor and copy assignment are deleted. Ownership is transferred with a move instead.
7. **It casts its argument to an rvalue reference, so a move constructor or move assignment can be selected.** It does not move anything by itself.
8. **Two objects both believe they own the allocation**, which leads to a double delete, use-after-free once one of them deletes it, or a leak when nobody knows who should free it.
9. **When a derived object may be deleted through a pointer to the base class**, which is typical for any class with virtual functions that is used polymorphically.
10. **Design classes so they declare no destructor, copy, or move operations**, and let members that manage their own resources (`std::string`, `std::vector`, `std::unique_ptr`) make the compiler-generated versions correct.
