// https://leetcode.com/problems/max-value-of-equation/


class Solution {
public:
	int findMaxValueOfEquation(vector<vector<int>>& p, int k) {
		int n = p.size();
		deque<int> d;
		int ans = INT_MIN;
		for (int i = 0; i < n; i++) {
			while (d.size() and p[i][0] - p[d.front()][0] > k)  
				d.pop_front();
			if (d.size())
				ans = max(ans, p[i][0] + p[i][1] - (p[d.front()][0] - p[d.front()][1]));
			while (d.size() and p[i][1] - p[i][0] >= p[d.back()][1] - p[d.back()][0]) 
				d.pop_back();
			d.push_back(i);
		}
		return ans;
	}
};

// class Solution {
// public:
//     int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
//         priority_queue<pair<int,int>>q;
//         int n=points.size();
//         int value=INT_MIN;
//         for(int i=0;i<n;i++){
//             while((!q.empty()) && points[i][0]-q.top().second > k  ){
//                 q.pop();
//         }
//             if(!q.empty()){
//                 int temp=points[i][0]+points[i][1]+q.top().first;
               
//                 value=value>temp?value:temp;
//                  cout<<endl<<value<<endl;
//             }
//             q.push({points[i][1]-points[i][0],points[i][0]});
        
//         }
//         return value;
//     }
// };

// class Solution {
// public:
//     int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
//         queue<pair<int,int>>q;
//         int n=points.size();
//         int value=INT_MIN;
//         for(int i=0;i<n;i++){
//             while((!q.empty()) && points[i][0]-q.front().second > k  ){
//                 q.pop();
//         }
//             if(!q.empty()){
//                 int temp=points[i][0]+points[i][1]+q.front().first;
               
//                 value=value>temp?value:temp;
//                  cout<<endl<<value<<endl;
//             }
//             q.push({points[i][1]-points[i][0],points[i][0]});
        
//         }
//         return value;
//     }
// };
