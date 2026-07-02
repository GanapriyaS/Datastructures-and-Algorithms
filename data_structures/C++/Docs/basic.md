# DSA : Introduction to C++

---

- How computers think?
- Why programming languages exist?
- Writing our first C++ code
- Rules of printing
- Data types & operators
- Taking input
- Making decisions (if-else)
- Assignments walkthrough

---

## What is Programming?

Computers are **dumb**:
- No common sense
- Can't think independently
- Follow only if you provide proper instructions

> **Programming** = Clear instructions to a computer, so that it can do some work for us.

---

## Why Programming Languages Exist?

Computers only understand **0s and 1s** (Binary).

```
Human (English) → Program → Computer (Binary)
```

Programming languages act as a bridge between human-readable code and binary that computers understand.

Popular languages: Python, JavaScript, SQL, Java, PHP, C#, C++, TypeScript, Golang, Rust, Ruby, C, Swift, R

---

## IDE & Importance of Syntax

An **IDE** (Integrated Development Environment) is a tool where you write, run, and debug your code.

Popular IDEs: VS Code, IntelliJ IDEA, WebStorm, Sublime Text

**Syntax** = The grammar rules of a programming language. Every language has strict syntax — even one mistake stops the code from running.

---

## First C++ Code (Hello World)

```cpp
#include <bits/stdc++.h>   // includes everything (alternative: #include <iostream>)
using namespace std;

int main()
{
    cout << "Hello world";
}
```

---

## Some Important Rules to Remember (Printing)

- **Semicolon**: Every statement must end with `;`
- **Case Sensitive**: `cout` will work, but `COUt` will not
- **Printing Text**: Text must be inside double quotes
- **New Line**: For a new line, use `endl`
- **Brackets Come in Pairs**: Every `{` must have a closing `}`

---

## Arithmetic Operators

| Operator | Meaning   |
|----------|-----------|
| `+`      | Add       |
| `-`      | Subtract  |
| `*`      | Multiply  |
| `/`      | Divide    |
| `%`      | Remainder |

- integer / integer then quotient is always integer ( 10 / 3 == 3)
- float / float or float / integer is float ( 6 / 5 = 1.2) 
    - cout << 10.0 / 3; (3.3333) 
    - cout << 6.0 / 6; (1)
- maths - BODMAS

---

## Variables

A **variable** is a named box in the computer's memory where we store some data.

```cpp
int age = 20; or int age = 20.22; then also value of age is 20
double price = 99.5;
char grade = 'A';

int age = 20;
int aGE = 23;
int AGE = 24; // all 3 are different variables as case-sensitive
```

---

## Data Types (Foundation)

| Type        | Use              |
|-------------|------------------|
| `int`       | Whole numbers    |
| `long long` | Big numbers      |
| `double`    | Decimal numbers  |
| `char`      | Single character |
| `bool`      | true / false     |

---

## Some Important Rules to Remember (Variables)

- Variable must be declared before use and name should not be reserved word
- No spaces in variable names
- Case sensitive: `marks` ≠ `Marks`
- Name should be meaningful (not `x1`, `a2` everywhere)

---

## Taking Input

Use `cin` with `>>` to take input from the user:

```cpp
cin >> a >> b >> c;

// 20 60 or

// 20 
// 60 

// c++ works same but python need to change syntax
```

---

## Relational Operators

| Operator | Meaning                  | Example    | Result |
|----------|--------------------------|------------|--------|
| `>`      | Greater than             | `5 > 3`    | true   |
| `<`      | Less than                | `5 < 3`    | false  |
| `>=`     | Greater than or equal to | `5 >= 5`   | true   |
| `<=`     | Less than or equal to    | `4 <= 3`   | false  |
| `==`     | Equal to                 | `5 == 5`   | true   |
| `!=`     | Not equal to             | `5 != 3`   | true   |

**Note:**
- `int a = 10;`
- `5 == 5` → ✓ true
- `6 == 5` → ✗ false

---

## True / False (bool)

- `0` → False
- Non-zero → True

```cpp
bool ans  = 5 == 5;   // true
bool ans2 = 6 != 5;   // true
bool ans3 = 6 < 5;    // false

bool ans4 = 0;
bool ans5 = 1;
bool ans6 = 134189;
bool ans7 = -134;

cout << ans  << endl; // 1 (true)
cout << ans2 << endl; // 1 (true)
cout << ans3 << endl; // 0 (false)

cout << ans4 << endl; // 0 (false)
cout << ans5 << endl; // 1 (true)
cout << ans6 << endl; // 1 (true)
cout << ans7 << endl; // 1 (true)
```

---

## Logical Operators

| Description | Symbol |
|-------------|--------|
| AND         | `&&`   |
| OR          | `\|\|` |
| NOT         | `!`    |

```cpp
// AND: both conditions must be true
if (age >= 18 && hasID == true)

// OR: at least one condition must be true
if (isAdmin || isModerator)

// NOT: flips the condition
if (!isLoggedIn)
```

---

## Conditionals (if-else)

Make decisions based on conditions.

**Real-world analogy:**
```
if "raining"
    carry umbrella
else
    don't carry umbrella

if age >= 18
    access granted
else
    can't give access
```

**C++ syntax:**
```cpp
if (condition) {
    // do this
} else {
    // do that
}
```

---

## if-else Ladder (Even / Odd Example)

Anything divisible by 2 → even

```cpp
int N;
cin >> N;

if (N % 2 == 0) {
    cout << "Even";
} else {
    cout << "Odd";
}
```

---

## Max and Min of 2 Numbers

**Example:** A = 10, B = 7 → Max = 10, Min = 7

```cpp
if (A > B) {
    cout << "Max = " << A << endl;
} else {
    cout << "Max = " << B << endl;
}
```

## Max and Min of 3 Numbers

**Example:** A = 10, B = 7, C = 15 → Max = 15, Min = 7

### Finding Maximum

```cpp
if (A >= B && A >= C) {
    cout << "Max = " << A << endl;
} else if (B >= A && B >= C) {
    cout << "Max = " << B << endl;
} else {
    cout << "Max = " << C << endl;
}
```