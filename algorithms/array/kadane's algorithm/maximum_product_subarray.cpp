// https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1#

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	  long long cur=arr[0];
	  long long mul=arr[0];
	  long long min=arr[0];
	  for(int i=1;i<n;i++){
	      if(arr[i]<0){
	          long long t=cur;
	          cur=min;
	          min=t;
	      }
	      min=min*arr[i]<arr[i]?min*arr[i]:arr[i];
	      cur=cur*arr[i]>arr[i]?cur*arr[i]:arr[i];
	      mul=cur>mul?cur:mul;
	  }
	  return mul;
	}
	
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
