# DSA — Loops

---

## The Problem: Print from 1 to 5

```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << 1 << endl;
    cout << 2 << endl;
    cout << 3 << endl;
    cout << 4 << endl;
    cout << 5 << endl;
}
```

---

## Print from 1 to 10

```cpp
int main()
{
    cout << 1 << endl;
    cout << 2 << endl;
    cout << 3 << endl;
    cout << 4 << endl;
    cout << 5 << endl;
    cout << 6 << endl;
    cout << 7 << endl;
    cout << 8 << endl;
    cout << 9 << endl;
    cout << 10 << endl;
}
```

---

## Print from 1 to 1000?

```
cout << 1 << endl;
cout << 2 << endl;
cout << 3 << endl;
...
cout << 1000 << endl;
```

> **How can we repeat work without writing the same code again and again?**

---

## Loops

When you want to **repeat an action** again and again till a **certain condition**, we can use **loops**.

---

## Types of Loops

1. **While** loop
2. **For** loop
3. **Do-while** loop

---

## While Loop

**Syntax:**

```cpp
initialization;

while(condition)
{
    // body
    update;
}
```

---

## Example: Print 1 to 10 (While Loop)

```cpp
int i = 1;
while(i <= 10)
{
    cout << i << endl;
    i++;
}
```

**How it works:**

| i  | i <= 10 | prints |
|----|---------|--------|
| 1  | YES     | 1      |
| 2  | YES     | 2      |
| 3  | YES     | 3      |
| 4  | YES     | 4      |
| 5  | YES     | 5      |
| ...| ...     | ...    |
| 10 | YES     | 10     |
| 11 | NO      | stops  |

---

## Print 1 to N (user input)

```cpp
int main()
{
    int n;
    cin >> n;

    int i = 1;
    while(i <= n)
    {
        cout << i << endl;
        i++;
    }
}
```

**Reverse variant (N down to 1):**

```cpp
int i = n;
while(i >= 1)
{
    cout << i << endl;
    i--;
}
```

---

## Print N to 1

```cpp
int main()
{
    int n;
    cin >> n;

    int i = n;
    while(i >= 1)
    {
        cout << i << endl;
        i--;
    }
}
```

**Example:** n = 4 → prints 4, 3, 2, 1

---

## Print Numbers from L to R

```cpp
int main()
{
    int l, r;
    cin >> l >> r;

    int i = l;
    while(i <= r)
    {
        cout << i << endl;
        i++;
    }
}
```

---

## Print All Even Numbers from 1 to N

**Approach 1 — check each number:**

```cpp
int n;
cin >> n;

int i = 1;
while(i <= n)
{
    if(i % 2 == 0)
    {
        cout << i << endl;
    }
    i++;
}
```

**Approach 2 — start at 2, jump by 2 (more efficient):**

```cpp
int i = 2;
while(i <= n)
{
    cout << i << endl;
    i += 2;
}
```

**Examples:**
- n = 5 → 2, 4
- n = 6 → 2, 4, 6

---

## Print All Uppercase Alphabets (A – Z)

```cpp
char ch = 'A';
while(ch <= 'Z')
{
    cout << ch << endl;
    ch++;
}
```

**ASCII Values:**

| Character | Value | Character | Value |
|-----------|-------|-----------|-------|
| 'A'       | 65    | 'a'       | 97    |
| 'B'       | 66    | 'b'       | 98    |
| 'C'       | 67    | 'c'       | 99    |
| ...       | ...   | ...       | ...   |

---

## Print Multiplication Table

```cpp
int i = 1;
while(i <= 10)
{
    cout << n << " x " << i << " = " << (n * i) << endl;
    i++;
}
```

**Example output:**

| n = 5       | n = 6       |
|-------------|-------------|
| 5 x 1 = 5   | 6 x 1 = 6   |
| 5 x 2 = 10  | 6 x 2 = 12  |
| 5 x 3 = 15  | 6 x 3 = 18  |
| 5 x 4 = 20  | 6 x 4 = 24  |
| 5 x 5 = 25  | 6 x 5 = 30  |
| 5 x 6 = 30  | 6 x 6 = 36  |
| 5 x 7 = 35  | 6 x 7 = 42  |
| 5 x 8 = 40  | 6 x 8 = 48  |
| 5 x 9 = 45  | 6 x 9 = 54  |
| 5 x 10 = 50 | 6 x 10 = 60 |

---

## Print Number in Reverse (digits)

```cpp
int n;
cin >> n;

if(n==0){
    cout << 0;
}

while(n != 0)
{
    cout << n % 10;
    n = n / 10;
}
```

**How it works (n = 1927):**

```
n = 1927  → print 7,  n = 192
n = 192   → print 2,  n = 19
n = 19    → print 9,  n = 1
n = 1     → print 1,  n = 0  → stop
```

**Examples:**
- n = 512 → 215
- n = 1927 → 7291
- n = 3429 → 9243

---

## Digits Sum / Count no of of digits

Sum all the digits of a number.

```cpp
int sum = 0;
int n;
cin >> n;

while(n != 0)
{
    sum += n % 10;
    n = n / 10;
}
cout << sum << endl;
```

**Examples:**
- n = 512 → 5 + 1 + 2 = **8**
- n = 1927 → 1 + 9 + 2 + 7 = **19**
- n = 3429 → 3 + 4 + 2 + 9 = **18**

---

## Reverse and Store in a Variable

```cpp
int ans = 0;
int n;
cin >> n;

while(n != 0)
{
    ans = (ans * 10) + n % 10;
    n = n / 10;
}
cout << ans << endl;
```

**Trace (n = 1927):**

| n    | n % 10 | ans              |
|------|--------|------------------|
| 1927 | 7      | 0*10 + 7 = 7     |
| 192  | 2      | 7*10 + 2 = 72    |
| 19   | 9      | 72*10 + 9 = 729  |
| 1    | 1      | 729*10 + 1 = 7291|
| 0    | —      | stop             |

**Examples:**
- n = 512 → ans = 215
- n = 1927 → ans = 7291
- n = 3429 → ans = 9243

---

## Palindrome

A number is a **palindrome** if it equals its reverse.

```cpp
int rev = 0;
int n;
cin >> n;

int temp = n;   // save original

while(n != 0)
{
    rev = (rev * 10) + n % 10;
    n = n / 10;
}

if(rev == temp)
{
    cout << "YES";
}
else
{
    cout << "NO";
}
```

**Examples:**
- n = 12321 → rev = 12321 → **YES**
- n = 1927 → rev = 7291 → **NO**
- n = 1 → rev = 1 → **YES**

> **Note:** After the while loop, `n` becomes 0. Use `temp` to compare against the original value.

---

## For Loop

The `for` loop is a compact way to write a while loop when you know the number of iterations.

**Syntax:**

```cpp
for(initialization; condition; update) {
    // code
}
```

**Equivalent while loop:**

```cpp
// while                      // for
int i = 1;                    for(int i = 1; i <= 100; i++)
while(i <= 100)               {
{                                 cout << i << endl;
    cout << i << endl;        }
    i++;
}
```

`while()` → `for` loop ✓ (they are interchangeable)
