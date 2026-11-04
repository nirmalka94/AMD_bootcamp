# Day 5 Mandatory Challenges

## Challenge 1 — Thread-safe counter (25 minutes)
Implement a class with `increment()` and `value() const`, callable from multiple threads. Protect the shared counter correctly.

Acceptance:
- Launch four threads, each incrementing 25,000 times.
- After joining, result must be 100,000.
- Explain why the unsynchronised version is a data race.

## Challenge 2 — Move-only ownership (25 minutes)
Create a function that accepts `std::unique_ptr<int>` by value and returns it. In `main`, transfer ownership into the function and verify the original pointer is empty afterward.

Acceptance:
- Use `std::move`.
- No raw `new`/`delete`.
- Explain why copying the unique pointer is rejected by the compiler.

## Optional
Replace the single mutex design with separate producer/consumer locks only if you can explain why the extra complexity is justified. It is not required.
