// https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/


#include<iostream>
#include<deque>
using namespace std;

int main(){
	int a[]={2, 5, -1, 7, -3, -1, -2};
	int n=7;
	int k=3;
	deque<int>mn;
	deque<int>mx;
	int sum=0;
	for(int i=0;i<n;i++){
		while((!mx.empty()) && a[i]>=a[mx.back()])
		{
			mx.pop_back();
		}
		while((!mn.empty()) && a[i]<=a[mn.back()])
		{
			mn.pop_back();
		}
		mx.push_back(i);
		mn.push_back(i);
		if(mx.front()==i-k)mx.pop_front();
		if(mn.front()==i-k)mn.pop_front();
		if(i>=k-1){
			sum=sum+a[mn.front()]+a[mx.front()];
		}
	}
	cout<<sum;
	return 0;
}
