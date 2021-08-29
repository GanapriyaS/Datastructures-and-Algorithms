def insertionSort(seq):
    for sliceEnd in range(len(seq)):
        pos=sliceEnd;
        while pos>0 and seq[pos]<seq[pos-1]:
            (seq[pos],seq[pos-1])=(seq[pos-1],seq[pos])
            pos=pos-1
l=[int(x)for x in input("ENTER THE ELEMENTS:").split()]
print("\nBEFORE SORTING:")
for i in l:
    print(i,end=" ")
insertionSort(l);
print("\nAFTER SORTING:")
for i in l:
    print(i,end=" ")
print("\n")
