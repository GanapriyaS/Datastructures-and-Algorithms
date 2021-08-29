class heap:
    def __init__(self,l=[]):
        self.heap=[]
        if l is not None:
            for root in l:
                self.insert(root)

    def print(self):
        for i in self.heap:
            print(i,end=" ")

    def bottom(self, index):
        root_index = (index - 1) // 2
        if root_index < 0:
            return
        if self.heap[index] > self.heap[root_index]:
            self.swap(index,root_index)
            self.bottom(root_index)

    def top_down(self, index):
        child_index = 2 * index + 1
        if child_index >= len(self.heap):
            return
        if child_index + 1 < len(self.heap) and self.heap[child_index] < self.heap[child_index + 1]:
            child_index += 1
        if self.heap[child_index] > self.heap[index]:
            self.swap(child_index, index)
            self.top_down(child_index)

    def insert(self,x):
        self.heap.append(x)
        self.bottom(len(self.heap)-1)

    def delete_max(self):
        if len(self.heap)!=0:
            self.swap(len(self.heap) - 1, 0)
            root = self.heap.pop()
            self.top_down(0)
        else:
            root="Heap is empty"
        return root

    def peek(self):
        if len(self.heap)!=0:
            return(self.heap[0])
        else:
            return("heap is empty")

    def swap(self,i, j):
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]


l=[int(x)for x in input().split()]
h=heap(l)
h.insert(17)
h.insert(68)
h.insert(1)
v=h.delete_max()
print("DELETING ELEMET:",v)
h.print()
print("PEEK ELEMENT:",h.peek())
