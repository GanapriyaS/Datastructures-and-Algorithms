# Functions in C++

## Table of Contents
1. [Factorial](#1-factorial)
2. [Binomial Coefficient (nCr)](#2-binomial-coefficient-ncr)
3. [What is a Function?](#3-what-is-a-function)
4. [Function Syntax](#4-function-syntax)
5. [Examples](#5-examples)
6. [Function Rules](#6-function-rules)
7. [Factors](#7-factors)
8. [Prime Numbers](#8-prime-numbers)

---

## 1. Factorial

The factorial of a number `n` is the product of all integers from `1` to `n`.

$$n! = n \times (n-1) \times (n-2) \times \dots \times 1 = 1 \times 2 \times 3 \times \dots \times n$$

**Examples**

```
3! = 3 × 2 × 1         = 6
5! = 5 × 4 × 3 × 2 × 1 = 120
```

For `N = 5`, the answer is `120`.

**Code**

```cpp
int N;
cin >> N;

int ans = 1;
for (int i = 1; i <= N; i++)
{
    ans *= i;
}
cout << ans;
```

**Dry run for N = 5**

| i | ans |
|---|-----|
| 1 | 1   |
| 2 | 2   |
| 3 | 6   |
| 4 | 24  |
| 5 | 120 |

Output: `120`

---

## 2. Binomial Coefficient (nCr)

$$^nC_r = \frac{n!}{r! \,(n - r)!}$$

**Example** — input `n = 5`, `r = 2`

$$^5C_2 = \frac{5!}{2! \times 3!} = \frac{120}{2 \times 6} = 10$$

- **Input:** `n` and `r`
- **Output:** the value of `nCr`

**Idea:** compute three factorials — `n!`, `r!`, and `(n-r)!` — using the factorial loop as a reusable block, then combine them.

**Code**

```cpp
int N, R;
cin >> N >> R;

// n!
int nFact = 1;
for (int i = 1; i <= N; i++)
{
    nFact *= i;
}

// r!
int rFact = 1;
for (int i = 1; i <= R; i++)
{
    rFact *= i;
}

// (n - r)!
int nrFact = 1;
for (int i = 1; i <= N - R; i++)
{
    nrFact *= i;
}

cout << nFact / (rFact * nrFact);
```

> Notice we repeat the *same* factorial logic three times. This is exactly the kind of repetition that **functions** eliminate.

---

## 3. What is a Function?

A **function** takes an **input**, runs a **set of steps**, and produces an **output** (think: potato → machine → gold).

- A **set of statements**
- **Write only once**
- **Reuse it multiple times**
- Makes code:
  - Cleaner
  - Shorter
  - Easier to debug

```
Input  →  [ Function: steps to execute ]  →  Output
```

---

## 4. Function Syntax

```cpp
return_type function_name(parameters)
{
    // function body
    return value;
}
```

- **Return type** → what the function gives back
- **Function name** → the identifier used to call it
- **Parameters** → inputs
- **Return statement** → the value sent back

**Factorial as a function**

```cpp
int factorial(int N)
{
    int ans = 1;
    for (int i = 1; i <= N; i++)
    {
        ans *= i;
    }
    return ans;
}
```

---

## 5. Examples

**Sum of two / three numbers**

```cpp
int sum2(int a, int b)
{
    return a + b;
}

int sum3(int a, int b, int c)
{
    return a + b + c;
}
```

**Factorial**

```cpp
int factorial(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
    }
    return ans;
}
```

**Print 1 to N** (returns nothing — `void`)

```cpp
void print1toN(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << endl;
    }
}
```

**Print a square of a character** (nested loop, `void`)

```cpp
void printSquare(int n, char ch)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << ch;
        }
        cout << endl;
    }
}
```

---

## 6. Function Rules

- **Number of parameters must match** the call.
- **Return type must match** the declared type.
- **`return` ends the function** immediately (ends the call).
- **A function may or may not return** a value:
  - `int`, `double`, `bool` → returns a value
  - `void` → prints only, returns nothing

```cpp
return_type function_name( ______ )
{
    ______
    return ;
}
```

---

## 7. Factors

A **factor** of `N` is a number that divides `N` with remainder `0`.

```
12 → 1, 2, 3, 4, 6, 12   (6 factors)
15 → 1, 3, 5, 15         (4 factors)
```

- **Smallest factor** of any `N` → always `1`
- **Largest factor** of any `N` → always `N`
- `i` is a factor of `N` when `N % i == 0` (divide `N` by `i`, remainder `= 0`)

**Print all factors of N**

```cpp
for (int i = 1; i <= N; i++)
{
    if (N % i == 0)   // i is a factor of N
    {
        cout << i << " ";
    }
}
```

Two common tasks:
1. **Print factors**
2. **Count factors**

---

## 8. Prime Numbers

A **prime number** has **exactly 2 factors** — `1` and the number `N` itself.

- `1` is **not** a prime number (it has only one factor).

```
Primes: 2, 3, 5, 7, 11, 13, 17, 19, 23 ...

2  → factors [1, 2]
3  → factors [1, 3]
5  → factors [1, 5]
7  → factors [1, 7]
11 → factors [1, 11]
```

**Check whether a number is prime** (`isPrime`)

```cpp
bool isPrime(int n)
{
    if (n == 1) return false;      // 1 is not prime

    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
        }
    }
    return count == 2;             // exactly 2 factors → prime
}
```

**Print all prime numbers from 1 to N** (reusing `isPrime`)

```cpp
int N;
cin >> N;

for (int i = 1; i <= N; i++)
{
    if (isPrime(i))                // i is prime
    {
        cout << i << " ";
    }
}
```

**Examples**

```
N = 10  →  2 3 5 7
N = 20  →  2 3 5 7 11 13 17 19
```
