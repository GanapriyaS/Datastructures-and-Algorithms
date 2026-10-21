# DSA — Pattern Printing (Complete)

**Key Idea:** Outer loop = rows, Inner loop = what to print per row. Find the relationship between row number `i` and the count of spaces/stars/chars.

---

## Table of Contents

| # | Pattern | # | Pattern |
|---|---------|---|---------|
| 1 | Print 1 to N | 16 | Pyramid — Right Aligned |
| 2 | 2 Stars per row | 17 | Symmetric Star Pyramid |
| 3 | 4 Stars per row | 18 | Triangle (pyramid + inverted) |
| 4 | Rectangle (n×m stars) | 19 | Hollow Triangle (left) |
| 5 | Square (n×n spaced) | 20 | Hollow Triangle (right-aligned) |
| 6 | Pyramid | 21 | Diamond |
| 7 | Inverted Pyramid | 22 | Hollow Diamond |
| 8 | Hollow Square | 23 | Crown |
| 9 | Hollow Rectangle | 24 | Butterfly |
| 10 | Numbered Rectangle I | 25 | Inverted Diamond |
| 11 | Numbered Rectangle II | 26 | Numbered Pyramid |
| 12 | Numbered Rectangle III | 27 | Binary Pyramid |
| 13 | Numbered Rectangle IV | | |
| 14 | Pyramid — Right Aligned (no spaces) | | |
| 15 | Pyramid — Right Aligned (spaced) | | |

---

## Pattern 1 — Print 1 to N

```
n=5    n=6    n=7
1      1      1
2      2      2
3      3      3
4      4      4
5      5      5
       6      6
              7
```

**Code:**
```cpp
for(int i = 1; i <= n; i++)
{
    cout << i << endl;
}
```

---

## Pattern 2 — 2 Stars per row

Given n (number of rows), print 2 stars on each row:

```
n=5    n=6    n=7
**     **     **
**     **     **
**     **     **
**     **     **
**     **     **
       **     **
              **
```

**Code:**
```cpp
for(int i = 1; i <= n; i++)
{
    cout << "**" << endl;
}
```

---

## Pattern 3 — 4 Stars per row

Given n (number of rows), print 4 stars on each row:

```
n=5    n=6    n=7
****   ****   ****
****   ****   ****
****   ****   ****
****   ****   ****
****   ****   ****
       ****   ****
              ****
```

**Code:**
```cpp
for(int i = 1; i <= n; i++)
{
    cout << "****" << endl;
}
```

---

## Pattern 4 — M Stars Rectangle

Given n (rows) and m (cols), print a rectangle of stars:

```
n=5,m=7     n=6,m=3    n=7,m=4
*******     ***        ****
*******     ***        ****
*******     ***        ****
*******     ***        ****
*******     ***        ****
            ***        ****
                       ****
```

**Code:**
```cpp
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= m; j++)
    {
        cout << "*";
    }
    cout << endl;
}
```

---

## Pattern 5 — Square (with spaces)

Given n (rows and cols), print an n×n grid of stars with spaces:

```
n=5            n=6                n=7
* * * * *      * * * * * *        * * * * * * *
* * * * *      * * * * * *        * * * * * * *
* * * * *      * * * * * *        * * * * * * *
* * * * *      * * * * * *        * * * * * * *
* * * * *      * * * * * *        * * * * * * *
               * * * * * *        * * * * * * *
                                  * * * * * * *
```

**Code:**
```cpp
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= n; j++)
    {
        cout << "* ";
    }
    cout << endl;
}
```

---

## Pattern 6 — Pyramid (increasing stars)

Row i has i stars:

```
n=5    n=6    n=7
*      *      *
**     **     **
***    ***    ***
****   ****   ****
*****  *****  *****
       ******  ******
               *******
```

**Code:**
```cpp
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= i; j++)
    {
        cout << "*";
    }
    cout << endl;
}
```

---

## Pattern 7 — Inverted Pyramid (decreasing stars)

Row i has (n - i + 1) stars:

```
n=5     n=6      n=7
*****   ******   *******
****    *****    ******
***     ****     *****
**      ***      ****
*       **       ***
        *        **
                 *
```

**Code:**
```cpp
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= n - i + 1; j++)
    {
        cout << "*";
    }
    cout << endl;
}
```

---

## Pattern 8 — Hollow Square

Only the **boundary** has stars, interior is empty. (Boundary will exist on row 1, row n, col 1, col n)

```
n=5              n=6
* * * * *        * * * * * *
*       *        *         *
*       *        *         *
*       *        *         *
* * * * *        *         *
                 * * * * * *
```

**Code:**
```cpp
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= n; j++)
    {
        if(i == 1 || i == n || j == 1 || j == n)
            cout << "* ";
        else
            cout << "  ";
    }
    cout << endl;
}
```

---

## Pattern 9 — Hollow Rectangle

Only the boundary has stars, interior is empty:

```
n=5,m=7     n=6,m=8     n=7,m=4
*******     ********    ****
*     *     *      *    *  *
*     *     *      *    *  *
*     *     *      *    *  *
*******     *      *    *  *
            *      *    *  *
            ********    ****
```

**Code:**
```cpp
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= m; j++)
    {
        if(i == 1 || i == n || j == 1 || j == m)
            cout << "*";
        else
            cout << " ";
    }
    cout << endl;
}
```

---

## Pattern 10 — Numbered Rectangle I (row number repeated)

Each row i is filled with the digit i, m times:

```
n=5,m=7      n=6,m=3    n=7,m=4
1111111      111        1111
2222222      222        2222
3333333      333        3333
4444444      444        4444
5555555      555        5555
             666        6666
                        7777
```

**Tip:** Draw the star pattern first, then replace `*` with the row number `i`.

**Code:**
```cpp
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= m; j++)
    {
        cout << i;
    }
    cout << endl;
}
```

---

## Pattern 11 — Numbered Rectangle II (1 to m repeated)

Each row prints 1 2 3 ... m:

```
n=5,m=7      n=6,m=3    n=7,m=4
1234567      123        1234
1234567      123        1234
1234567      123        1234
1234567      123        1234
1234567      123        1234
             123        1234
                        1234
```

**Code:**
```cpp
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= m; j++)
    {
        cout << j;
    }
    cout << endl;
}
```

---

## Pattern 12 — Numbered Rectangle III (A to (A+m-1) repeated)

Each row prints A B C ... (m characters):

```
n=5,m=7      n=6,m=3    n=7,m=4
ABCDEFG      ABC        ABCD
ABCDEFG      ABC        ABCD
ABCDEFG      ABC        ABCD
ABCDEFG      ABC        ABCD
ABCDEFG      ABC        ABCD
             ABC        ABCD
                        ABCD
```

**Code:**
```cpp
for(int i = 1; i <= n; i++)
{
    char ch = 'A';
    for(int j = 1; j <= m; j++)
    {
        cout << ch;
        ch++;
    }
    cout << endl;
}
```

---

## Pattern 13 — Numbered Rectangle IV (row letter repeated)

Row i prints the i-th alphabet m times:

```
n=5,m=7      n=6,m=3    n=7,m=4
AAAAAAA      AAA        AAAA
BBBBBBB      BBB        BBBB
CCCCCCC      CCC        CCCC
DDDDDDD      DDD        DDDD
EEEEEEE      EEE        EEEE
             FFF        FFFF
                        GGGG
```

**Code:**
```cpp
for(int i = 1; i <= n; i++)
{
    char ch = 'A' + (i - 1);
    for(int j = 1; j <= m; j++)
    {
        cout << ch;
    }
    cout << endl;
}
```

---

## Pattern 14 — Pyramid Right-Aligned (no spaces between stars)

Row i: (n-i) spaces, then i stars

| i | spaces | stars |
|---|--------|-------|
| 1 | n-1    | 1     |
| 2 | n-2    | 2     |
| 3 | n-3    | 3     |
| n | 0      | n     |

```
n=5:
    *
   **
  ***
 ****
*****
```

**Answer:**
```cpp
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= n - i; j++)   // spaces
        cout << " ";
    for(int j = 1; j <= i; j++)       // stars
        cout << "*";
    cout << endl;
}
```

---

## Pattern 15 — Pyramid Right-Aligned (spaced stars)

Row i: (n-i) spaces, then i stars with spaces between them

```
n=5:
    *
   * *
  * * *
 * * * *
* * * * *
```

**Answer:**
```cpp
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= n - i; j++)
        cout << " ";
    for(int j = 1; j <= i; j++)
    {
        cout << "*";
        if(j < i) cout << " ";
    };
    cout << endl;
}
```

---

## Pattern 16 — Symmetric Star Pyramid (stars-spaces-stars)

Row i: i stars + (2n-2i) spaces + i stars → total width = 2n

| i | left stars | spaces | right stars |
|---|-----------|--------|-------------|
| 1 | 1         | 2n-2   | 1           |
| 2 | 2         | 2n-4   | 2           |
| n | n         | 0      | n           |

```
n=5:
*        *
**      **
***    ***
****  ****
**********
```

**Answer:**
```cpp
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= i; j++)           // left stars
        cout << "*";
    for(int j = 1; j <= 2*(n-i); j++)     // middle spaces
        cout << " ";
    for(int j = 1; j <= i; j++)           // right stars
        cout << "*";
    cout << endl;
}
```

---

## Pattern 17 — Triangle (Pyramid + Inverted Pyramid)

First half increases, second half decreases.

```
n=5:
*
* *
* * *
* * * *
* * * * *
* * * *
* * *
* *
*
```

**Answer:**
```cpp
// upper half
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= i; j++) cout << "* ";
    cout << endl;
}
// lower half
for(int i = n - 1; i >= 1; i--)
{
    for(int j = 1; j <= i; j++) cout << "* ";
    cout << endl;
}
```

---

## Pattern 18 — Hollow Triangle (Left-Aligned)

First row = 1 star, last row = all n stars, middle rows = first and last star only.

```
n=5:
*
* *
*   *
*     *
* * * * *
```

**Answer:**
```cpp
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= i; j++)
    {
        if(j == 1 || j == i || i == n)
            cout << "* ";
        else
            cout << "  ";
    }
    cout << endl;
}
```

---

## Pattern 19 — Hollow Triangle (Right-Aligned / Inverted)

```
n=5:
* * * * *
 *     *
  *   *
   * *
    *
```

**Answer:**
```cpp
for(int i = n; i >= 1; i--)
{
    for(int j = 1; j <= n - i; j++)    // leading spaces
        cout << " ";
    for(int j = 1; j <= i; j++)
    {
        if(j == 1 || j == i || i == n)
            cout << "* ";
        else
            cout << "  ";
    }
    cout << endl;
}
```

---

## Pattern 20 — Hollow Triangle (Right-Aligned, growing)

```
n=5:
    *
   * *
  *   *
 *     *
* * * * *
```

**Answer:**
```cpp
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= n - i; j++)    // leading spaces
        cout << " ";
    for(int j = 1; j <= i; j++)
    {
        if(j == 1 || j == i || i == n)
            cout << "* ";
        else
            cout << "  ";
    }
    cout << endl;
}
```

---

## Pattern 21 — Diamond

Upper half = right-aligned pyramid (spaces then spaced stars)
Lower half = inverted right-aligned pyramid

```
n=5:
    *
   * *
  * * *
 * * * *
* * * * *
 * * * *
  * * *
   * *
    *
```

**Answer:**
```cpp
// upper half
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= n - i; j++) cout << " ";
    for(int j = 1; j <= i; j++)
    {
        cout << "*";
        if(j < i) cout << " ";
    }
    cout << endl;
}
// lower half
for(int i = n - 1; i >= 1; i--)
{
    for(int j = 1; j <= n - i; j++) cout << " ";
    for(int j = 1; j <= i; j++)
    {
        cout << "*";
        if(j < i) cout << " ";
    }
    cout << endl;
}
```

---

## Pattern 22 — Hollow Diamond

Only boundary stars; interior spaces.

```
n=5:
    *
   * *
  *   *
 *     *
*       *
 *     *
  *   *
   * *
    *
```

**Answer:**
```cpp
// upper half
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= n - i; j++) cout << " ";
    for(int j = 1; j <= i; j++)
    {
        if(j == 1 || j == i)
            cout << "* ";
        else
            cout << "  ";
    }
    cout << endl;
}
// lower half
for(int i = n - 1; i >= 1; i--)
{
    for(int j = 1; j <= n - i; j++) cout << " ";
    for(int j = 1; j <= i; j++)
    {
        if(j == 1 || j == i)
            cout << "* ";
        else
            cout << "  ";
    }
    cout << endl;
}
```

---

## Pattern 23 — Crown

Row i: i stars + (2n-2i) spaces + i stars. Last row = 2n stars (joined).

```
n=5:
*               *
* *           * *
* * *       * * *
* * * *   * * * *
* * * * * * * * *

n=6:
*                 *
* *             * *
* * *         * * *
* * * *     * * * *
* * * * * * * * * *
* * * * * * * * * *
```

**Answer:**
```cpp
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= i; j++) cout << "* ";    // left stars
    for(int j = 1; j <= 2*(n-i); j++) cout << "  "; // middle spaces
    for(int j = 1; j <= i; j++) cout << "* ";    // right stars
    cout << endl;
}
```

---

## Pattern 24 — Butterfly

Upper half = crown (growing), lower half = crown (shrinking).

```
n=5:
*               *
* *           * *
* * *       * * *
* * * *   * * * *
* * * * * * * * *
* * * *   * * * *
* * *       * * *
* *           * *
*               *
```

**Answer:**
```cpp
// upper half
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= i; j++) cout << "* ";
    for(int j = 1; j <= 2*(n-i); j++) cout << "  ";
    for(int j = 1; j <= i; j++) cout << "* ";
    cout << endl;
}
// lower half
for(int i = n - 1; i >= 1; i--)
{
    for(int j = 1; j <= i; j++) cout << "* ";
    for(int j = 1; j <= 2*(n-i); j++) cout << "  ";
    for(int j = 1; j <= i; j++) cout << "* ";
    cout << endl;
}
```

---

## Pattern 25 — Inverted Diamond

Upper half = inverted crown (shrinking from 2n), lower half = crown (growing to 2n).

```
n=5:
* * * * * * * * *
* * * *   * * * *
* * *       * * *
* *           * *
*               *
* *           * *
* * *       * * *
* * * *   * * * *
* * * * * * * * *
```

**Answer:**
```cpp
// upper half (n down to 1)
for(int i = n; i >= 1; i--)
{
    for(int j = 1; j <= i; j++) cout << "* ";
    for(int j = 1; j <= 2*(n-i); j++) cout << "  ";
    for(int j = 1; j <= i; j++) cout << "* ";
    cout << endl;
}
// lower half (2 up to n)
for(int i = 2; i <= n; i++)
{
    for(int j = 1; j <= i; j++) cout << "* ";
    for(int j = 1; j <= 2*(n-i); j++) cout << "  ";
    for(int j = 1; j <= i; j++) cout << "* ";
    cout << endl;
}
```

---

## Pattern 26 — Numbered Pyramid

Row i: digit i repeated i times.

```
n=5      n=6      n=7
1        1        1
22       22       22
333      333      333
4444     4444     4444
55555    55555    55555
         666666   666666
                  7777777
```

**Answer:**
```cpp
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= i; j++)
        cout << i;
    cout << endl;
}
```

---

## Pattern 27 — Binary Pyramid

Row i starts with (i % 2 == 0 ? 1 : 0), alternates 0 and 1:

```
n=5       n=6       n=7
0         0         0
10        10        10
010       010       010
1010      1010      1010
01010     01010     01010
          101010    101010
                    0101010
```

**Key insight:** `num % 2` switches between 0 and 1 (odd/even toggle).

**Code:**
```cpp
for(int i = 1; i <= n; i++)
{
    int start = (i % 2 == 0) ? 1 : 0;  // even row starts with 1, odd starts with 0
    for(int j = 1; j <= i; j++)
    {
        cout << start << " ";
        start = 1 - start;               // flip 0→1 or 1→0
    }
    cout << endl;
}


for (int i = 1; i <= n; i++)
{
    // Calculate the starting point
    int num;
    if (i % 2 == 1)
    {
        num = 0;
    }
    else
    {
        num = 1;
    }

    for (int j = 1; j <= i; j++)
    {
        cout << (num % 2);
        num++;
    }
    cout << endl;
}
```

---

## Quick Reference — Row Formula Table

| Pattern | Spaces | Stars/chars |
|---------|--------|-------------|
| Pyramid | 0 | i |
| Inverted Pyramid | 0 | n-i+1 |
| Right-Aligned Pyramid | n-i | i |
| Symmetric Crown (left) | 0 | i stars, 2(n-i) spaces, i stars |
| Diamond (upper) | n-i | i (spaced) |

## How to Approach Any Pattern

1. **Count rows** → outer loop `i` from 1 to n (or n to 1) - outer loop runs `n` times
2. Count what's printed per row → inner loop logic
3. Find the relationship between row number `i` and what's printed
4. For star patterns: draw the star pattern first, then replace `*` with the required character/number
5. **Count columns** → find formula for spaces and stars using `i` and `n`
6. **For hollow shapes** → draw solid first, then only print `*` on boundary
7. **For number patterns** → replace `*` with `i` or `j`
8. **For compound shapes** → split into top half + bottom half
