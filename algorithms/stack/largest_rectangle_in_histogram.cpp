// https://leetcode.com/problems/largest-rectangle-in-histogram/

// class Solution
// {
// 	public:
// 		int top = -1;
// 	int n;
// 	void push(int *stk, int s)
// 	{
// 		if (top != n - 1)
// 		{
// 			stk[++top] = s;
// 		}
// 	}

// 	int pop(int *stk)
// 	{
// 		return top == -1 ? -1 : stk[top--];
// 	}

// 	int largestRectangleArea(vector<int> &heights)
// 	{
// 		n = heights.size();
// 		int stk[n];
// 		int area = 0;
// 		int i;

// 		for (i = 0; i < n; i++)
// 		{
// 			if (top == -1 || heights[i] >= heights[stk[top]])
// 			{
// 				push(stk, i);
// 			}
// 			else
// 			{
// 				while (!(top == -1) && heights[i] < heights[stk[top]])
// 				{
// 					int h = pop(stk);
// 					int temp = top == -1 ? heights[h] *i : heights[h] *(i - stk[top] - 1);
// 					area = area > temp ? area : temp;
// 				}

// 				push(stk, i);
// 			}
// 		}

// 		while (!(top == -1))
// 		{
// 			int h = pop(stk);
// 			int temp = top == -1 ? heights[h] *i : heights[h] *(i - stk[top] - 1);
// 			area = area > temp ? area : temp;
// 		}

// 		return area;
// 	}
// };


// second modification

// class Solution
// {
// 	public:
// 		int top = -1;
// 	int n;
// 	void push(int *stk, int s)
// 	{
// 		if (top != n - 1)
// 		{
// 			stk[++top] = s;
// 		}
// 	}

// 	int pop(int *stk)
// 	{
// 		return top == -1 ? -1 : stk[top--];
// 	}

// 	int largestRectangleArea(vector<int> &heights)
// 	{
// 		n = heights.size();
// 		int stk[n];
// 		int area = 0;
// 		int i;

// 		for (i = 0; i < n; i++)
// 		{
//             while (!(top == -1) && heights[i] < heights[stk[top]])
// 				{
// 					int h = pop(stk);
// 					int temp = top == -1 ? heights[h] *i : heights[h] *(i - stk[top] - 1);
// 					area = area > temp ? area : temp;
// 				}

// 				push(stk, i);
// 		}

// 		while (!(top == -1))
// 		{
// 			int h = pop(stk);
// 			int temp = top == -1 ? heights[h] *i : heights[h] *(i - stk[top] - 1);
// 			area = area > temp ? area : temp;
// 		}

// 		return area;
// 	}
// };


// Third modfication

// class Solution
// {
// 	public:
// 		int top = -1;
// 	int n;
// 	void push(int *stk, int s)
// 	{
// 		if (top != n - 1)
// 		{
// 			stk[++top] = s;
// 		}
// 	}

// 	int pop(int *stk)
// 	{
// 		return top == -1 ? -1 : stk[top--];
// 	}

// 	int largestRectangleArea(vector<int> &heights)
// 	{
// 		n = heights.size();
// 		int stk[n];
// 		int area = 0;
// 		int i;

// 		for (i = 0; i <= n; i++)
// 		{
//             while (!(top == -1) && (i==n || heights[i] < heights[stk[top]]))
// 				{
// 					int h = pop(stk);
// 					int temp = top == -1 ? heights[h] *i : heights[h] *(i - stk[top] - 1);
// 					area = area > temp ? area : temp;
// 				}

// 				push(stk, i);
// 		}

// 		return area;
// 	}
// };


class Solution
{
public:
    int top;
	void push(int *stk, int s,int n)
	{
		if (top != n - 1)
		{
			stk[++top] = s;
		}
	}

	int pop(int *stk)
	{
		return top == -1 ? -1 : stk[top--];
	}
    int largestRectangleArea(vector<int> &arr)
    {
        // Your code here
        int n=arr.size();
        int st[n];
        vector<int>left(n);
        vector<int>right(n);
        
        top=-1;
        for(int i=0;i<n;i++)
        {
            while(!(top==-1) && arr[i]<=arr[st[top]])
            {
                pop(st);
            }
            left[i]= (top!=-1)?st[top]:-1;
            push(st,i,n);
            
        }
        
        top=-1;
        
        for(int i=n-1;i>=0;i--)
        {
            while(!(top==-1) && arr[i]<=arr[st[top]])
            {
                pop(st);
            }
            
            right[i]=(top!=-1)?st[top]:n;
            push(st,i,n);
        }
        int mx=0;
        for(int i=0;i<n;i++)
        {
            
            int curr_area=(right[i]-left[i]-1)*arr[i];
            
            mx=max(mx,curr_area);
        }
        return mx;
        
    }
};
