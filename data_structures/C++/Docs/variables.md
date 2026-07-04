# C++ Notes

A combined reference covering **Variable Scoping** and other increment operators, ternary operator, data types, and short-circuit evaluation.

---

## Table of Contents

1. [Variable Scoping in C++](#variable-scoping-in-c)
2. [Important Things to Know](#important-things-to-know)
   - [Pre-Increment and Post-Increment](#1-pre-increment-and-post-increment)
   - [Ternary Operator](#2-ternary-operator-)
   - [`int` vs `long long`](#3-int-vs-long-long)
   - [Short-Circuit Evaluation](#4-short-circuit-evaluation-logical-operators)
3. [MCQs](#mcqs)
4. [Summary](#summary)

---

# Variable Scoping in C++

## What is a Variable?

A **variable** is a named memory location used to store data.

```cpp
int x = 10;
```

- `x` → variable name
- `10` → value
- `int` → data type

Where a variable can be used is decided by its **scope**.

## What is Scope?

**Scope** defines where a variable is accessible in the program.

- If a variable is accessed outside its scope, it does not exist for the compiler.

## Why Do We Need Scope?

1. Avoid name conflicts
2. Reduce memory usage
3. Improve code readability
4. Control variable lifetime

## Types of Scope in C++

### 1. Local Scope

A variable declared inside a function is **local** to that function.

```cpp
#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    cout << x << endl;
}
```

`x` is accessible only inside `main`.

**Outside the function:**

```cpp
int main()
{
    int x = 10;
}

cout << x;   // Error
```

The variable `x` does not exist outside `main`.

### 2. Block Scope (if / loops)

Any variable declared inside `{}` belongs only to that block.

**if block:**

```cpp
int main()
{
    if (true)
    {
        int a = 5;
        cout << a << endl;
    }
    cout << a;   // Error
}
```

**Loop block:**

```cpp
for (int i = 1; i <= 5; i++)
{
    cout << i << " ";
}
cout << i;  // Error
```

`i` exists only inside the loop.

### 3. Function Scope

Variables declared inside a function cannot be accessed outside it.

```cpp
void fun()
{
    int x = 100;
    cout << x << endl;
}

int main()
{
    fun();
    cout << x;   // Error
}
```

### 4. Global Scope

A variable declared outside all functions is a **global variable**.

```cpp
#include <iostream>
using namespace std;

int x = 50;

void fun()
{
    cout << x << endl;
}

int main()
{
    cout << x << endl;
    fun();
}
```

**Output:**

```
50
50
```

Global variables are accessible everywhere in the program.

**Caution with global variables:**

- Can be modified from anywhere
- Makes debugging harder
- Should be used sparingly

### 5. Local vs Global Variable (Same Name)

```cpp
int x = 10;

int main()
{
    int x = 20;
    cout << x << endl;
}
```

**Output:**

```
20
```

The local variable takes precedence over the global variable.

**Accessing the global variable explicitly:**

```cpp
int x = 10;

int main()
{
    int x = 20;
    cout << ::x << endl;
}
```

**Output:**

```
10
```

`::` is called the **scope resolution operator**.


- we cannot declare same variable in same scope like inside main

```cpp
int main()
{
    int x = 20;
    int x = 5; // error
    cout << x << endl;
}
```

- garbage value

```cpp
int main()
{
    int x; 
    cout << x << endl; // garbage value
    x = 5;
}
```

### 6. Nested Block Scope

```cpp
int main()
{
    int x = 10;

    {
        int y = 20;
        cout << x << " " << y << endl;
    }

    cout << x << endl;
    cout << y;   // Error
}
```

- Inner blocks can access outer variables
- Outer blocks cannot access inner variables

### 7. Variable Shadowing

When a variable in an inner scope has the same name as one in an outer scope.

```cpp
int main()
{
    int x = 5;

    if (true)
    {
        int x = 10;
        cout << x << endl;
    }

    cout << x << endl;
}
```

**Output:**

```
10
5
```

The inner `x` temporarily hides the outer `x`.

### 8. Scope vs Lifetime

| Term     | Meaning                          |
| -------- | -------------------------------- |
| Scope    | Where a variable can be accessed |
| Lifetime | How long it exists in memory     |

```cpp
void fun()
{
    int x = 10;
}
```

- **Scope:** inside `fun()`
- **Lifetime:** only while `fun()` executes

## Common Beginner Mistakes

**1. Using a variable before declaration:**

```cpp
cout << x;
int x = 10;   // Compilation error
```

**2. Assuming the loop variable exists outside:**

```cpp
for (int i = 0; i < 5; i++) {}
cout << i;   // Error
```

**3. Accidentally modifying global variables:**

```cpp
int count = 0;

void fun()
{
    count++;   // Hard to track in large programs
}
```

## Worked Examples

**Example 1:**

```cpp
int x = 10;

void fun()
{
    int x = 20;
    cout << x << endl;
}

int main()
{
    cout << x << endl;
    fun();
    cout << x << endl;
}
```

**Output:**

```
10
20
10
```

**Example 2:**

```cpp
int main()
{
    int x = 5;
    if (x > 0)
    {
        int y = 10;
    }
    cout << y;
}
```

**Answer:** Compilation error (`y` is out of scope).

## Best Practices

1. Prefer local variables over global
2. Keep variable scope as small as possible
3. Avoid reusing variable names
4. Use meaningful names
5. Avoid unnecessary globals

---

# Important Things to Know

## 1. Pre-Increment and Post-Increment

### What is Increment?

Increment means **increase the value of a variable by 1**.

```cpp
x = x + 1;
```

C++ provides shortcuts:

- `++x` → **Pre-increment**
- `x++` → **Post-increment**

### Pre-Increment (`++x`)

**Definition:**

- First **increase the value**
- Then **use the value**

**Example:**

```cpp
int x = 5;
int y = ++x;

cout << x << endl;
cout << y << endl;
```

**Step-by-step:**

1. `x` becomes 6
2. `y` gets 6

**Output:**

```
6
6
```

### Post-Increment (`x++`)

**Definition:**

- First **use the value**
- Then **increase the value**

**Example:**

```cpp
int x = 5;
int y = x++;

cout << x << endl;
cout << y << endl;
```

**Step-by-step:**

1. `y` gets 5
2. `x` becomes 6

**Output:**

```
6
5
```

### Side-by-Side Comparison

| Expression | Meaning                   |
| ---------- | ------------------------- |
| `++x`      | Increment first, then use |
| `x++`      | Use first, then increment |

### Tricky Example

```cpp
int x = 10;
cout << x++ << endl;
cout << ++x << endl;
```

**Dry run:**

- First line prints `10`, `x` becomes `11`
- Second line increments to `12`, prints `12`

**Output:**

```
10
12
```

> ⚠️ **Important Rule:** Avoid using `++` multiple times in one statement.
>
> ```cpp
> int x = 5;
> int y = x++ + ++x;   // Confusing (undefined behavior)
> ```

---

## 2. Ternary Operator (`?:`)

### What is the Ternary Operator?

A **short form of if–else** that works in a single line.

**Syntax:**

```cpp
condition ? value_if_true : value_if_false;
```

### Example Using if–else

```cpp
int a = 10;
int b = 20;

int max;
if (a > b)
{
    max = a;
}
else
{
    max = b;
}
```

### Same Example Using the Ternary Operator

```cpp
int max = (a > b) ? a : b;
```

Shorter, cleaner, same logic.

### Another Example: Even or Odd

```cpp
int n = 7;

cout << ((n % 2 == 0) ? "Even" : "Odd") << endl;
```

**Output:**

```
Odd
```

### When to Use the Ternary Operator

- Simple conditions
- Single decision
- Avoid nested ternary operators

---

## 3. `int` vs `long long`

### Why Do We Need Different Data Types?

Because **numbers have limits**.

### `int`

- **Size:** 4 bytes
- **Range:** `-2,147,483,648` to  (2^31 - 1)`2,147,483,647` (≈ 2 × 10⁹)

```cpp
int x = 1000000000;
```

### `long long`

- **Size:** 8 bytes
- **Range:** up to ≈ 9 × 10¹⁸

```cpp
long long x = 1000000000000;
```

### What Happens if `int` Overflows?

```cpp
int x = 2000000000; // 2 * 10^9
x = x + 1000000000;

cout << x << endl;  // Wrong output due to overflow (integer overflow get garbage value)
```

### Use `long long` When:

- Multiplying large numbers
- Constraints mention `10^9`, `10^12`, `10^18`
- Competitive programming problems

### `#define int long long` Hack

**What is this?** A **preprocessor trick** used in competitive programming.

```cpp
#define int long long
```

After this line, every `int` becomes `long long`.

**Example:**

```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long

int main()
{
    int x = 1000000000000;
    cout << x << endl;
}
```

> ❗ **Important Rule (Very Important):** If you use the hack, write `main` like this:
>
> ```cpp
> signed main()
> {
> }
> ```
>
> **Why?**
> - `int main()` becomes `long long main()` (invalid)
> - `signed` avoids replacement

**Should beginners use this hack?**

- Bad practice, but good for **competitive programming**
- Bad for **learning fundamentals**
- Can hide overflow bugs

**Recommendation:**

- Understand `int` and `long long` first
- Use the hack later

```cpp
int main(){
    return 0; // no error

    return 12; /// runtime error
}
```

---

## 4. Short-Circuit Evaluation (Logical Operators)

### What is Short-Circuiting?

In C++, logical operators:

- `&&` (AND)
- `||` (OR)

do **not always evaluate both sides** of an expression. The second condition is evaluated **only if needed**. This behavior is called **short-circuit evaluation**.

### Short-Circuit with AND (`&&`)

**Rule:**

- If the **first condition is false**, the second condition is **not evaluated**.

**Example:**

```cpp
int a = 5;
int b = 0;

if (a > 10 and (b = 10) > 5)
{
    cout << "Inside if" << endl;
}

cout << b << endl;
```

**Dry run:**

- `a > 10` → false
- Second condition is skipped
- `b` is never updated

**Output:**

```
0
```

### Short-Circuit with OR (`||`)

**Rule:**

- If the **first condition is true**, the second condition is **not evaluated**.

**Example:**

```cpp
int a = 5;
int b = 0;

if (a < 10 or (b = 10) > 5)
{
    cout << "Inside if" << endl;
}

cout << b << endl;
```

**Dry run:**

- `a < 10` → true
- Second condition skipped

**Output:**

```
Inside if
0
```

### Why Short-Circuiting Exists

1. Improves performance
2. Prevents runtime errors
3. Enables safe condition checks

### Very Important Practical Example (Division by Zero)

**Without short-circuit (dangerous):**

```cpp
int a = 10;
int b = 0;

if (a / b > 1)   // Runtime error
{
    cout << "Valid" << endl;
}
```

**With short-circuit (safe):**

```cpp
int a = 10;
int b = 0;

if (b != 0 && a / b > 1)
{
    cout << "Valid" << endl;
}
```

**Explanation:**

- `b != 0` is false
- `a / b` is never executed
- Program is safe

### Short-Circuit with Functions

```cpp
bool check()
{
    cout << "Function called" << endl;
    return true;
}

int main()
{
    if (false && check())
    {
        cout << "Inside if" << endl;
    }
}
```

**Output:**

```
(no output)
```

`check()` is **never called**.

---

## MCQs

**Q1**

```cpp
int x = 5;
cout << x++ << endl;
```

**Answer:** `5` (value is used first, then `x` becomes 6)

**Q2**

```cpp
int x = 5;
cout << ++x << endl;
```

**Answer:** `6` (incremented first, then used)

**Q3**

```cpp
int a = 3, b = 7;
cout << (a > b ? a : b);
```

**Answer:** `7`

**Q4**

Which type should be used for storing `10^18`?

**Answer:** `long long`

**Q5**

```cpp
int x = 0;

if (x != 0 && ++x > 1)
{
}

cout << x << endl;
```

**Answer:** `0` (first condition false → `++x` skipped)

**Q6**

```cpp
int x = 0;

if (x == 0 || ++x > 1)
{
}

cout << x << endl;
```

**Answer:** `0` (first condition true → `++x` skipped)

**Q7**

```cpp
int x = 0;

if (x == 1 && ++x)
{
}

cout << x << endl;
```

**Answer:** `0` (first condition false → `++x` skipped)

---

## Summary

- `++x` and `x++` behave differently — pre-increment updates before use, post-increment updates after use.
- The ternary operator (`?:`) replaces a simple if–else in a single line.
- `int` has limits (≈ 2 × 10⁹); use it for normal ranges.
- `long long` prevents overflow (≈ 9 × 10¹⁸); use it for large numbers.
- Short-circuit evaluation skips the second operand of `&&`/`||` when the result is already known — useful for safe checks like avoiding division by zero.
- Keep variable scope as small as possible and prefer local over global variables.


This difference exists because global and local variables are stored in entirely different areas of computer memory with distinct size limits.

Local Variables: These are allocated on the stack, which has a strict, limited size (typically 1 MB to 8 MB depending on the OS). An array of 10⁵ integers fits, but 10⁷ integers (40 MB) will cause a stack overflow.

Global Variables: These are allocated on the data segment (or heap). The data segment has a much larger size limit, often limited only by your computer's available physical RAM.If you need to use large amounts of memory locally without making variables global, you can allocate the memory on the heap using dynamic memory (e.g., int* arr = new int[10000000]; or std::vector<int> arr(10000000);).