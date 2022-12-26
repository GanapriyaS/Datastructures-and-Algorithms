def selectionSort(l):
    for start in range(len(l)):
        minpos=start
        for i in range(start,len(l)):
            if(l[i]<l[minpos]):
                minpos=i
        (l[start],l[minpos])=(l[minpos],l[start])
l=[int(x)for x in input("ENTER THE ELEMENTS:").split()]
print("\nBEFORE SORTING:")
for i in l:
    print(i,end=" ")
selectionSort(l);
print("\nAFTER SORTING:")
for i in l:
    print(i,end=" ")
print("\n")
