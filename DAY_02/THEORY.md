# Day 2 Theory — Classes and Resource Ownership

Legend: **CORE** is required today. **OPTIONAL** is for later review.

## 1. Class and object — CORE

A class defines a type; an object is an instance of that type.

```cpp
class Motor {
public:
    void set_speed(double speed) {
        speed_ = speed;
    }

    double speed() const {
        return speed_;
    }

private:
    double speed_{0.0};
};
```

- `public` members form the interface.
- `private` members hide implementation details.
- The trailing `const` on `speed()` promises not to modify the object.

Encapsulation means callers use the public interface instead of changing internal state directly.

## 2. Constructors and destructors — CORE

A constructor establishes the object's initial state. A destructor runs when the object's lifetime ends.

```cpp
class Sensor {
public:
    explicit Sensor(std::string name) : name_(std::move(name)) {}

    ~Sensor() {
        // Cleanup if this class owns a resource.
    }

private:
    std::string name_;
};
```

Member initialiser lists initialise members directly. Prefer them to assigning members in the constructor body.

For ordinary members such as `std::string` and `std::vector`, C++ already manages their resources. You normally do not need to write a destructor.

## 3. Stack and dynamic storage — CORE

```cpp
Sensor local_sensor{"front_lidar"};
auto managed_sensor = std::make_unique<Sensor>("rear_lidar");
```

The local object is destroyed automatically when its scope ends. The object managed by `unique_ptr` is destroyed when the owning pointer is destroyed or reset.

Avoid using raw `new` and `delete` in ordinary application code. They make ownership and cleanup harder to reason about.

## 4. RAII — CORE

RAII (Resource Acquisition Is Initialization) ties a resource's lifetime to an object's lifetime. When the owner is destroyed, its resource is released automatically.

Examples:
- `std::string` owns its character storage.
- `std::vector` owns its element storage.
- `std::unique_ptr<T>` owns one dynamically allocated `T`.

RAII makes early returns and exceptions safer because cleanup is automatic.

## 5. Smart pointers — CORE

### `std::unique_ptr`
One exclusive owner. It cannot be copied; ownership can be transferred with `std::move`.

```cpp
auto sensor = std::make_unique<Sensor>("front");
auto new_owner = std::move(sensor);
// sensor is now empty; new_owner owns the object.
```

### `std::shared_ptr`
Shared ownership through a reference count. Use only when multiple independent parts genuinely need to co-own an object.

### Raw pointer
Usually a non-owning observer in modern application code. A raw pointer does not express ownership by itself.

## 6. Copying and shallow-copy hazards — CORE

If a class contains a raw pointer that owns memory, the compiler-generated copy copies only the pointer value, not the pointed-to resource. Two objects may then believe they own the same allocation, causing double deletion or use-after-free.

The best beginner-level fix is usually to use a standard owning type (`std::vector`, `std::string`, `std::unique_ptr`) rather than writing manual memory-management code.

## 7. Inheritance and virtual destructors — CORE

If an object may be deleted through a base-class pointer, the base class should have a virtual destructor.

```cpp
class SensorBase {
public:
    virtual ~SensorBase() = default;
    virtual double read() const = 0;
};
```

The `virtual` destructor ensures the derived object's destructor also runs when destruction happens through a base pointer.

## 8. Rule of Three/Five/Zero — OPTIONAL overview

- Rule of Three: if a class manually manages a resource and needs a destructor, copy constructor, or copy assignment operator, it may need all three.
- Rule of Five adds move constructor and move assignment operator.
- Rule of Zero: prefer member types that manage their own resources, so your class needs none of these special functions.

For most application-level robotics code, aim for the Rule of Zero.

## 9. What not to implement today — REFERENCE

Do not build a custom smart pointer, allocator, reference-counting system, or a full Rule-of-Five buffer class. Understand the ownership problem and use standard RAII types.
