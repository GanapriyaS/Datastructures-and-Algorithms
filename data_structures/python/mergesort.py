def mergeSort(A,left,right):
    if(right-left<=1):
        return(A[left:right])
    if(right-left>1):
        mid=(left+right)//2
        L=mergeSort(A,left,mid)
        R=mergeSort(A,mid,right)
        return(merge(L,R))
def merge(A,B):
    (c,m,n)=([],len(A),len(B))
    (i,j)=(0,0)
    while(i+j!=m+n):
        if i==m :
            c.append(B[j])
            j=j+1
        elif j==n:
            c.append(A[i])
            i=i+1
        elif A[i]<=B[j]:
            c.append(A[i])
            i=i+1
        elif A[i]>B[j]:
            c.append(B[j])
            j=j+1
    return(c)
l=[int(x)for x in input("ENTER THE ELEMENTS:").split()]
c=[]
print("\nBEFORE SORTING:")
for i in l:
    print(i,end=" ")
c=list(mergeSort(l,0,len(l)));
print(c)
print("\nAFTER SORTING:")
for i in c:
    print(i,end=" ")
print("\n")
