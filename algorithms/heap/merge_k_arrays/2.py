#User function Template for python3
import heapq
class Solution:
    #Function to merge k sorted arrays.
    def mergeKArrays(self, lists, K):
        final_list = []
        heap = [(mylst[0], i, 0) for i, mylst in enumerate(lists) if mylst]
        heapq.heapify(heap)
    
        while heap:
            val, list_ind, element_ind = heapq.heappop(heap)
            final_list.append(val)
            if element_ind + 1 < len(lists[list_ind]):
                next_tuple = (lists[list_ind][element_ind + 1],
                              list_ind,
                              element_ind + 1)
                heapq.heappush(heap, next_tuple)
        return final_list

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    t=int(input())
    for _ in range(t):
        n=int(input())
        numbers=[[ 0 for _ in range(n) ] for _ in range(n) ]
        line=input().strip().split()
        for i in range(n):
            for j in range(n):
                numbers[i][j]=int(line[i*n+j])
        ob = Solution();
        merged_list=ob.mergeKArrays(numbers, n)
        for i in merged_list:
            print(i,end=' ')
        print()
# } Driver Code Ends
