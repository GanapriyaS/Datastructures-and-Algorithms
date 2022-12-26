def InsertionSort(seq):
    isort(seq,len(seq))
def isort(seq,k):
    if(k>1):
        isort(seq,k-1)
        insert(seq,k-1)
def insert(seq,k):
    pos=k;
    while pos>0 and seq[pos]<seq[pos-1]:
        (seq[pos],seq[pos-1])=(seq[pos-1],seq[pos])
        pos=pos-1
l=[int(x)for x in input("ENTER THE ELEMENTS:").split()]
print("\nBEFORE SORTING:")
for i in l:
    print(i,end=" ")
InsertionSort(l);
print("\nAFTER SORTING:")
for i in l:
    print(i,end=" ")
print("\n")
