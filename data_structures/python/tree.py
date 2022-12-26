class Tree:
    def __init__(self,initial=None):
        self.value=initial
        if self.value:
            self.left=Tree()
            self.right=Tree()
        else:
            self.left=None
            self.right=None

    def isEmpty(self):
        return(self.value==None)

    def isleaf(self):
        return(self.left.isEmpty() and self.right.isEmpty())

    def find(self,v):
        if self.isEmpty():
            return(False)
        if self.value==v:
            return(True)
        if v<self.value:
            return(self.left.find(v))
        if v>self.value:
            return(self.right.find(v))

    def minval(self):
        if self.left.left==None:
            return(self.value)
        else:
            return(self.left.minval())

    def maxval(self):
        if self.right.right==None:
            return(self.value)
        else:
            return(self.right.maxval())

    def insert(self,v):
        if self.isEmpty():
            self.value=v
            self.left=Tree()
            self.right=Tree()
        if self.value==v:
            return
        if v<self.value:
            self.left.insert(v)
            return
        if v>self.value:
            self.right.insert(v)
            return

    def inorder(self):
        if self.isEmpty():
            return([])
        else:
            return(self.left.inorder()+[self.value]+self.right.inorder())

    def delete(self,v):
        if self.isEmpty():
            return
        if v<self.value:
            self.left.delete(v)
            return
        if v>self.value:
            self.right.delete(v)
            return
        if v==self.value:
            if self.isleaf():
                self.makeempty()
            elif self.left.isEmpty():
                self.copyright()
            else:
                self.value=self.left.maxval()
                self.left.delete(self.left.maxval())
            return

    def makeempty(self):
        self.value=None
        self.left=None
        self.right=None
        return

    def copyright(self):
        self.value=self.right.value
        self.left=self.right.left
        self.right=self.right.right
        return

    def __str__(self):
        return(str(self.inorder()))

t=Tree(10)
t.insert(2)
t.insert(1)
t.insert(5)
t.insert(6)
t.insert(7)
t.delete(5)
print(t)
print("MAX ",t.maxval())
print("MIN ",t.minval())
print(t.find(10))
