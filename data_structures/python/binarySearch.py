def binarySearch(seq,v,l,r):
    if(r-l==0):
        return False,-1
    mid=(l+r)//2
    if(v==seq[mid]):
        return True,mid
    if(v<seq[mid]):
        return (binarySearch(seq,v,l,mid))
    else:
        return (binarySearch(seq,v,mid+1,r))
l=[int(x)for x in input("ENTER THE ELEMENTS:").split()]
v=input("ENTER THE KEY ELEMENT TO SEARCH:")
A,B=binarySearch(l,int(v),0,len(l));
if(A):
    print("ELEMENT ",v," IS PRESENT AT LOCATION ",B)
else:
    print("ELEMENT NOT PRESENT!")
