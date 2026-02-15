10^8 simple operations

1. a = 1 -> O(1)
2. b = 2 -> O(1)
3. c = a + b -> O(1)
4. printf("hello") -> O(1)
5. return a + b -> O(1)
   O(5) is same as O(1)
   O(n-1)/ O(n+1) is O(n) take highest power
   O(n^2 + 2n + 1) is O(n^2)

---

printf("hello")
for(i=0; i<n; i++){
print("hello");
}
sort(a.begin(), a.end())

O(1 + n + nlogn) is O(nlogn)

---

Limit is 10^8

n = 10
O(1) (constant time - not depend on input)
O(n) = 10 operations
O(logn) = log2 10 = 3 operations
O(nlogn) = 10 * log2 10 = 30
O(n^2) = 100
O(n^3) = 1000
O(2^n) = 2^10 = 1024 operations
O(n!) = 10*9*8*7*... *1 = 55
O(n^n) = 10000000000

---

n = 1000
O(n) = 1000
O(n^2) = 10^6
O(n^3) = 10^9

---

n = 10^5
O(n) = 10^5
O(nlogn) = 10^5 _ log2 10^3 = 10^5 _ 30 = 3 \* 10^6
O(n^2) = 10^10

---

n = 10^8
O(n) = 10^8
O(nlogn) = 10^8 \* log2 10^8

---

n = 10^9
O(logn) = log (10^9) = 30
O(n) = 10^9
