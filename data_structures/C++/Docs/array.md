# Arrays in C++

Combined notes: the **concepts + problem set** (Arrays deck) and the **worked solutions** (Excalidraw answers deck).

## Table of Contents
- **Concepts**
  1. [Why Arrays? (Storing marks of N students)](#1-why-arrays--storing-marks-of-n-students)
  2. [What is an Array?](#2-what-is-an-array)
  3. [Creating an Array](#3-creating-an-array)
  4. [Accessing Elements](#4-accessing-elements)
  5. [Input / Output](#5-input--output)
- **Problems (with solutions)**
  6. [Print Array in Reverse](#6-print-array-in-reverse)
  7. [Find Max of the Array](#7-find-max-of-the-array) ✅
  8. [Find Min of the Array](#8-find-min-of-the-array)
  9. [Search in an Array](#9-search-in-an-array)
  10. [Count Occurrences](#10-count-occurrences) ✅
  11. [Check if the Array is Sorted](#11-check-if-the-array-is-sorted) ✅
  12. [Sort 0s and 1s (Sort 01)](#12-sort-0s-and-1s-sort-01) ✅
  13. [Swap 2 Numbers](#13-swap-2-numbers) ✅
  14. [Swap Alternate](#14-swap-alternate) ✅
  15. [Reverse in the Same Array](#15-reverse-in-the-same-array) ✅
  16. [Missing / Special Number](#16-missing--special-number) ✅
  17. [Intersection of Two Arrays](#17-intersection-of-two-arrays)
  18. [Pair Sum](#18-pair-sum)
  19. [Triplet Sum](#19-triplet-sum)
  20. [Quadruplet Sum](#20-quadruplet-sum)
  21. [Find HCF (using a function)](#21-find-hcf-using-a-function) ✅

> ✅ = a handwritten solution was provided in the answers deck.

---

## 1. Why Arrays? (Storing marks of N students)

Storing **5** marks with separate variables is fine:

```cpp
int main()
{
    int m1, m2, m3, m4, m5;
    cin >> m1 >> m2 >> m3 >> m4 >> m5;
}
```

**10** marks is already annoying:

```cpp
int main()
{
    int m1, m2, m3, m4, m5, m6, m7, m8, m9, m10;
    cin >> m1 >> m2 >> m3 >> m4 >> m5 >> m6 >> m7 >> m8 >> m9 >> m10;
}
```

**100** marks — impossible and very hard to manage 🤡

```cpp
// impossible and very hard to manage
int main()
{
    int m1, m2, m3, ... m100;
    cin >> m1 >> m2 >> m3 >> ..... >> m100;
}
```

**The array way** — one name, indexed slots `0 … 99`:

```cpp
int main()
{
    int marks[100];

    marks[1]  = 17;
    marks[4]  = 25;
    marks[99] = 75;
}
```

And reading all of them collapses into a single loop:

```cpp
// Instead of: cin >> marks[0]; cin >> marks[1]; ... cin >> marks[99];
for (int i = 0; i <= 99; i++)
{
    cin >> marks[i];
}
```

---

## 2. What is an Array?

- A **collection of similar kind of data** stored together at **continuous memory locations**.
- It lets us create **multiple variables of the same data type** using a **single name**.
- Each element is accessed using the **array name** with its **unique index**.
- **Indexing starts at `0`**, and the last element is at index **`N − 1`**, where `N` is the total number of elements.

```
 First index                         Element (at index 8)
      ↓                                       ↓
      0   1   2   3   4   5   6   7   8   9  ← indices
    ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
    │   │   │   │   │   │   │   │   │   │   │
    └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
    └──────────── Array length is 10 ────────────┘
```

---

## 3. Creating an Array

```cpp
DataType ArrayName[NUMBER_OF_ELEMENTS];
```

Examples:

```cpp
int       a[20];    // indices 0 .. 19
float     b[30];    // indices 0 .. 29
long long c[500];   // indices 0 .. 499
```

> Once you create an array, all elements can hold **any random value** — often called a **garbage value** — until you assign something.

---

## 4. Accessing Elements

```cpp
int a[20];

a[0] = 31;              // assign
a[1]++;                 // modify
cout << a[2] << endl;   // may print a garbage value
```

- Valid indices run from **`0` to `N − 1`**.
  - `a[1]` ✔, `a[19]` ✔
  - `a[20]` ✗ (out of range), `a[-1]` ✗ (out of range)
- Accessing `a[i]` where `i < 0` or `i >= N` is **undefined behaviour** — it could be a **runtime error**, a **segmentation fault**, or **reading garbage**.

---

## 5. Input / Output

Read `n`, then `n` values, then print them back.

```cpp
int main()
{
    int n;
    cin >> n;

    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}
```

```
Input:  5
        7 8 1 2 4
Output: 7 8 1 2 4
```

---

## 6. Print Array in Reverse

```
Input:  5
        7 8 1 2 4
Output: 4 2 1 8 7
```

**Solution** — loop from the last index down to `0`:

```cpp
for (int i = n - 1; i >= 0; i--)
{
    cout << A[i] << " ";
}
```

---

## 7. Find Max of the Array ✅

```
Input:  6
        1 4 8 7 9 3
Output: 9        (value)   |   5 (1-based location)
```

**Solution** — start by assuming the first element is the answer, then update whenever a bigger element appears. (Track its 1-based `location` too.)

```cpp
int ans = a[0], location = 1;

for (int i = 1; i < n; i++)
{
    if (a[i] > ans)          // ">" → maximum
    {
        ans = a[i];
        location = i + 1;
    }
}

cout << ans << " " << location << endl;
```

> Note: the answers deck wrote this template with `if (a[i] < ans)`, which actually finds the **minimum**. Use `>` for the maximum and `<` for the minimum — the rest of the structure is identical (see [Find Min](#8-find-min-of-the-array)).

---

## 8. Find Min of the Array

```
Input:  6
        7 6 8 9 1 3
Output: 1
```

**Solution**

```cpp
int ans = a[0];

for (int i = 1; i < n; i++)
{
    if (a[i] < ans)          // "<" → minimum
    {
        ans = a[i];
    }
}

cout << ans;
```

---

## 9. Search in an Array

```
Input:  6 10          Input:  6 8
        7 6 8 9 1 3            7 6 8 9 1 3
Output: NOT FOUND     Output: FOUND
```

First line is `n` and the `target`; second line is the array. Print `FOUND` if the target exists.

**Solution**

```cpp
bool found = false;
for (int i = 0; i < n; i++)
{
    if (a[i] == target)
    {
        found = true;
        break;
    }
}
cout << (found ? "FOUND" : "NOT FOUND");
```

---

## 10. Count Occurrences ✅

```
Input:  6 7           Input:  6 8
        7 6 7 9 7 3           7 6 8 9 1 3
Output: 3             Output: 1
```

**Solution** — read `n` and `target`, read the array, then count matches.

```cpp
int n;
cin >> n;

int target;
cin >> target;

int a[n];
for (int i = 0; i < n; i++)
{
    cin >> a[i];
}

int count = 0;
for (int i = 0; i < n; i++)
{
    if (a[i] == target)
    {
        count++;
    }
}

cout << count << endl;
```

---

## 11. Check if the Array is Sorted ✅

```
Input:  6                    Input:  6
        1 2 2 8 11 31                7 6 7 9 7 3
Output: YES                  Output: NO
```

For an array to be in **ascending order**, `a[i] >= a[i - 1]` must be true for **every** `i`.
So the array is **not sorted** the moment we find some `a[i] < a[i - 1]`.

**Solution** (flag pattern)

```cpp
int n;
cin >> n;

int a[n];
for (int i = 0; i < n; i++)
{
    cin >> a[i];
}

bool flag = false;                 // assume sorted
for (int i = 1; i < n; i++)
{
    if (a[i] < a[i - 1])
    {
        // array is not sorted
        flag = true;
        break;
    }
}

if (flag)
{
    cout << "NOT SORTED";
}
else
{
    cout << "SORTED";
}
```

---

## 12. Sort 0s and 1s (Sort 01) ✅

The array contains **only 0s and 1s**. Print it in ascending order.

```
Input:  6                Input:  6
        1 1 0 1 1 0              1 0 0 1 1 0
Output: 0 0 1 1 1 1      Output: 0 0 0 1 1 1
```

**Idea:** count how many 0s (`c0`) and 1s (`c1`) there are, then print all the 0s followed by all the 1s.

**Solution**

```cpp
int c0 = 0, c1 = 0;

for (int i = 0; i < n; i++)
{
    if (a[i] == 0)
    {
        c0++;
    }
    else
    {
        c1++;
    }
}

// print all 0's
for (int i = 1; i <= c0; i++)
{
    cout << "0 ";
}

// print all 1's
for (int i = 1; i <= c1; i++)
{
    cout << "1 ";
}
```

---

## 13. Swap 2 Numbers ✅

```
Input:  A = 2, B = 5
Output: A = 5, B = 2
```

**Solution** — use a temporary variable.

```cpp
int temp = A;
A = B;
B = temp;
```

```
Before:  A = 7   B = 4
temp = A → temp = 7
A = B    → A = 4
B = temp → B = 7
After:   A = 4   B = 7
```

---

## 14. Swap Alternate ✅

Swap elements in pairs: `(0,1), (2,3), (4,5) …`

```
Input:  5                Input:  6
        7 8 1 2 4                7 9 8 1 2 4
Output: 8 7 2 1 4        Output: 9 7 1 8 4 2
```

**Solution** — step `i` by 2 and swap each element with the one before it.

```cpp
for (int i = 1; i < n; i += 2)
{
    swap(a[i], a[i - 1]);
}
```

---

## 15. Reverse in the Same Array ✅

Reverse the array **in place** (do not use a second array).

```
Input:  5                Input:  6
        7 8 1 2 4                7 9 8 1 2 4
Output: 4 2 1 8 7        Output: 4 2 1 8 9 7
```

**Idea:** two pointers — one at the start (`i`), one at the end (`j`). Swap and move them toward each other until they meet.

**Solution**

```cpp
int i = 0, j = n - 1;

while (i <= j)
{
    swap(a[i], a[j]);
    i++;
    j--;
}

for (int i = 0; i < n; i++)
{
    cout << a[i] << " ";
}
```

---

## 16. Missing / Special Number ✅

Every number in the array is present **twice**, except for **one special element** that occurs **only once**. Find it.

```
Input:  7                    Input:  7
        2 1 9 1 2 3 9                1 2 1 2 3 4 3
Output: 3                    Output: 4
```

**Idea (brute force):** for each element, count how many times it appears in the whole array; the one with `count == 1` is the answer.

**Solution**

```cpp
int ans;

for (int i = 0; i < n; i++)
{
    // check how many times a[i] occurs in the array
    int count = 0;
    for (int j = 0; j < n; j++)
    {
        if (a[j] == a[i])
        {
            count++;
        }
    }

    if (count == 1)
    {
        ans = a[i];
        break;
    }
}

cout << ans << endl;
```

---

## 17. Intersection of Two Arrays

Print the elements present in **both** arrays.

```
Input:  6                    Input:  4
        2 6 8 5 4 3                  2 6 1 2
        4                            5
        2 3 4 7                      1 2 3 4 2
Output: 2 4 3                Output: 2 2
```

(First array is size `n` then its elements; second array is size `m` then its elements. Duplicates count — matched elements are consumed.)

**Solution** — for each element of the first array, look for an unused match in the second; mark it used so it isn't matched twice.

```cpp
bool used[m] = {false};

for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        if (!used[j] && a[i] == b[j])
        {
            cout << a[i] << " ";
            used[j] = true;      // consume this match
            break;
        }
    }
}
```

---

## 18. Pair Sum

Count how many pairs in the array satisfy `A[i] + A[j] = target`.

```
Input:  9
        1 3 6 2 5 4 3 2 4
        7                    (target)
Output: 7
```

**Solution** — check every pair `(i, j)` with `i < j`.

```cpp
int count = 0;
for (int i = 0; i < n; i++)
{
    for (int j = i + 1; j < n; j++)
    {
        if (a[i] + a[j] == target)
        {
            count++;
        }
    }
}
cout << count;
```

---

## 19. Triplet Sum

Count how many triplets satisfy `A[i] + A[j] + A[k] = target`.

```
Input:  7
        1 2 3 4 5 6 7
        12                   (target)
Output: 5
```

**Solution** — three nested loops with `i < j < k`.

```cpp
int count = 0;
for (int i = 0; i < n; i++)
{
    for (int j = i + 1; j < n; j++)
    {
        for (int k = j + 1; k < n; k++)
        {
            if (a[i] + a[j] + a[k] == target)
            {
                count++;
            }
        }
    }
}
cout << count;
```

---

## 20. Quadruplet Sum

Count how many quadruplets satisfy `A[i] + A[j] + A[k] + A[l] = target`.

**Solution** — four nested loops with `i < j < k < l`.

```cpp
int count = 0;
for (int i = 0; i < n; i++)
{
    for (int j = i + 1; j < n; j++)
    {
        for (int k = j + 1; k < n; k++)
        {
            for (int l = k + 1; l < n; l++)
            {
                if (a[i] + a[j] + a[k] + a[l] == target)
                {
                    count++;
                }
            }
        }
    }
}
cout << count;
```

---

## 21. Find HCF (using a function) ✅

> **Problem.** You are given two integers `A` and `B` (`1 ≤ A, B ≤ 10⁵`). Find the HCF of `A` and `B` by writing a function that takes `A` and `B` as parameters and returns their HCF.
>
> **Input:** two integers `A` and `B`.
> **Output:** the HCF of `A` and `B`.
>
> ```
> input
> 12 36
> output
> 12
> ```

**Idea:** the HCF (Highest Common Factor) is the **largest number that divides both**. Walk `i` from `1` to `n`; whenever `i` divides **both** numbers, it's a common factor — keep the last (largest) such `i`.

```
12 → 1, 2, 3, 4, 6, 12
8  → 1, 2, 4, 8              highest common factor of {1,2,4} = 4

12 → 1, 2, 3, 4, 6, 12
36 → 1, 2, 3, 4, 6, 9, 12, 18, 36   highest common factor = 12
```

**Solution**

```cpp
int n, m;
cin >> n >> m;

int ans = 1;
for (int i = 1; i <= n; i++)
{
    if (n % i == 0 && m % i == 0)   // i is a factor of both n and m
    {
        ans = i;
    }
}

cout << ans << endl;
```

**As a function** (matching the problem's requirement):

```cpp
int hcf(int a, int b)
{
    int ans = 1;
    for (int i = 1; i <= a; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            ans = i;
        }
    }
    return ans;
}
```
