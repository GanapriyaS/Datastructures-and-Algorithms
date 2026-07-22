# Mixed Problem Solving Session

Practice problems on **strings** and **2D arrays**, with worked traces and C++ solutions.

## Table of Contents
- **String Problems**
  1. [Sum of Digits](#1-sum-of-digits)
  2. [Compress String (Run-Length Encoding)](#2-compress-string-run-length-encoding)
  3. [Longest Word](#3-longest-word)
- **2D Array Problems**
  4. [Diagonal Sum](#4-diagonal-sum)
  5. [Rotate Image (90° Clockwise)](#5-rotate-image-90-clockwise)
  6. [Spiral Matrix / Boundary Trace](#6-spiral-matrix--boundary-trace)

---

## 1. Sum of Digits

> Find the sum of the digits of a number `N`.

```
N = 126   → 1 + 2 + 6     = 9
N = 7253  → 7 + 2 + 5 + 3 = 17
```

**Approach A — arithmetic (`% 10` and `/ 10`).** Peel off the last digit repeatedly.

```cpp
int sum = 0;
while (N != 0)
{
    sum += N % 10;   // last digit
    N /= 10;         // drop the last digit
}
cout << sum << endl;
```

**Approach B — read as a string.** Useful for **very big numbers** (that `long long` can't store). Each character digit is converted to its numeric value by subtracting `'0'` (i.e. `- 48`).

```
'0' → 0,  '1' → 1,  '2' → 2,  ...  '9' → 9      (char - '0')
```

```cpp
string s = "7253";
//          0123
int n = s.size(), sum = 0;

for (int i = 0; i < n; i++)
{
    sum += s[i] - '0';
}
cout << sum;
```

---

## 2. Compress String (Run-Length Encoding)

> Replace each run of a repeated character with the character followed by its count.

```
i/p: aaabbddccc          →  o/p: a3b2d2c3
i/p: ggttttffffrreeegggg →  o/p: g2t4f4r2e3g4
i/p: xyzzz               →  o/p: xyz3
i/p: abcde               →  o/p: abcde
```

**Idea (two pointers):** `i` marks the start of a run; `j` runs forward while the character stays the same, counting the run length. Print `s[i]` + count, then jump `i` to `j`.

```cpp
int N = s.size();
int i = 0;

while (i < N)
{
    int j = i;
    int cnt = 0;

    while (j < N && s[i] == s[j])
    {
        cnt++;
        j++;
    }

    cout << s[i] << cnt;

    i = j;   // move to the next distinct character
}
```

---

## 3. Longest Word

> Given a sentence, find the **length** of its longest word.

```
i/p: "I am learning DSA"          →  o/p: 8   ("learning")
i/p: "Improving Myself Everyday"  →  o/p: 9   ("Improving")
```

> **Reading the input:** `cin >> s` reads only **one word** (stops at the space). To read the whole line use **`getline(cin, s)`**.

**Idea (two pointers):** skip spaces; for each word let `j` run to the next space, counting its length; track the maximum in `ans`.

```cpp
string s;
getline(cin, s);

int N = s.size();
int i = 0;
int ans = 0;

while (i < N)
{
    if (s[i] == ' ')
    {
        i++;
        continue;
    }

    int j = i;
    int cnt = 0;

    while (j < N && s[j] != ' ')
    {
        cnt++;
        j++;
    }

    if (cnt > ans)
    {
        ans = cnt;
    }

    i = j;
}

cout << ans;
```

---

## 4. Diagonal Sum

> Given an `N × N` 2D array, find the sum of its **diagonal** elements.

**Main diagonal** — cells where **row number = column number**: `(0,0), (1,1), (2,2), …`

```
      0  1  2
   0 [5][6][8]
   1 [2][5][1]      main diagonal = 5 + 5 + 6 = 16
   2 [9][8][6]
```

```
      0  1  2  3
   0 [1][2][6][8]
   1 [3][6][2][5]   main diagonal = 1 + 6 + 8 + 9 = 24
   2 [9][7][8][5]
   3 [6][6][2][9]
```

**Main-diagonal code** — since `i == j`, one index is enough:

```cpp
int i = 0, sum = 0;
while (i < N)
{
    sum += A[i][i];
    i++;
}
```

**Anti-diagonal** — from top-right to bottom-left; start `i = 0, j = N-1`, then `i++, j--`:

```cpp
int i = 0, j = N - 1, sum = 0;
while (i < N && j >= 0)
{
    sum += A[i][j];
    i++;
    j--;
}
```

---

## 5. Rotate Image (90° Clockwise)

> Given an `N × N` 2D array, rotate it 90° clockwise.

```
i/p:              o/p:
1 2 3             7 4 1
4 5 6      →      8 5 2
7 8 9             9 6 3
```

**Observation:** the rotated output, printed row by row, is the **original read column-by-column, bottom to top**. So for each column `j` (left → right), print `arr[i][j]` from the **bottom row up**.

```cpp
for (int j = 0; j < M; j++)
{
    for (int i = N - 1; i >= 0; i--)
    {
        cout << arr[i][j] << " ";
    }
    cout << endl;
}
```

- `j` → column
- `i` → row (going from `N-1` up to `0` → bottom to top)

---

## 6. Spiral Matrix / Boundary Trace

> Print the matrix in **spiral order** (outer boundary first, then spiral inward).

```
 1  2  3  4          Output: 1 2 3 4 5 6 ...
14 15 16  5          (walk the outer ring clockwise,
13 20 17  6           then move one layer in and repeat)
12 19 18  7
11 10  9  8
```

### Boundary Trace (one ring)

Walk a single ring in four straight passes. Each pass starts one step after the previous corner so corners aren't printed twice.

```
// Start Row (row = 0): left → right
for (int j = 0; j < M; j++)
{
    cout << arr[0][j] << " ";
}

// End Col (col = M-1): top → bottom, start below the corner
for (int i = 1; i < N; i++)
{
    cout << arr[i][M - 1] << " ";
}

// End Row (row = N-1): right → left, from M-2 back to 0
for (int j = M - 2; j >= 0; j--)
{
    cout << arr[N - 1][j] << " ";
}

// Start Col (col = 0): bottom → top, from N-2 back to 1
for (int i = N - 2; i >= 1; i--)
{
    cout << arr[i][0] << " ";
}
```

### Full Spiral (layer by layer)

Maintain four boundaries — `startRow`, `endRow`, `startCol`, `endCol` — and shrink them inward after each ring.

```cpp
int startRow = 0, endRow = N - 1;
int startCol = 0, endCol = M - 1;

while (startRow <= endRow && startCol <= endCol)
{
    // Start Row: i = startRow, j → startCol … endCol
    for (int j = startCol; j <= endCol; j++)
    {
        cout << arr[startRow][j] << " ";
    }

    // End Col: j = endCol, i → startRow+1 … endRow
    for (int i = startRow + 1; i <= endRow; i++)
    {
        cout << arr[i][endCol] << " ";
    }

    // End Row: i = endRow, j → endCol-1 … startCol
    if(startRow != endRow){ // to handle single row 
      for (int j = endCol - 1; j >= startCol; j--)
      {
          cout << arr[endRow][j] << " ";
      }
    }

    // Start Col: j = startCol, i → endRow-1 … startRow+1
    if(startCol != endCol ){ // to handle single col
      for (int i = endRow - 1; i >= startRow + 1; i--)
      {
          cout << arr[i][startCol] << " ";
      }
    }

    // move into the next layer
    startRow++;
    endRow--;
    startCol++;
    endCol--;
}
```
