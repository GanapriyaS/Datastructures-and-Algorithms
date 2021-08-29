class Node:
    def __init__(self,initial):
        self.value=initial
        self.next=None
        return
    def isEmpty(self):
        return(self.value==None)

    def appendr(self,v):
        if self.isEmpty():
            self.value=v
        elif self.next==None:
            newnode=Node(v)
            self.next=newnode
        else:
            (self.next).appendr(v)
        return
    def appendi(self,v):
        if self.isEmpty():
            self.value=v
            return
        temp=self
        while temp.next!=None:
            temp=temp.next
        newnode=Node(v)
        temp.next=newnode
        return

    def insert(self,v):
        if self.isEmpty():
            self.value=v
            return
        newnode=Node(v)
        (self.value,newnode.value)=(newnode.value,self.value)
        (self.next,newnode.next)=(newnode,self.next)
        return

    def deletei(self,x):
        if self.isEmpty():
            return
        if self.value==x:
            if self.next==None:
                self.value=None
            else:
                self.value=self.next.value
                self.next=self.next.next
                return
        temp=self
        while temp.next!=None:
            if temp.next.value==x:
                temp.next=temp.next.next
                return
            else:
                temp=temp.next
        return()

    def deleter(self,x):
        if self.isEmpty():
            return()
        if self.value==x:
            if self.next==None:
                self.value=None
            else:
                self.value=self.next.value
                self.next=self.next.next
                return()
        else:
            if self.next!=None:
                self.next.deleter(x)
                if self.next.value==None:
                    self.next=self.next.next
        return()

    def __str__(self):
        selflist=[]
        if self.value==None:
            return(str(selflist))
        temp=self
        selflist.append(self.value)
        while temp.next!=None:
            temp=temp.next
            selflist.append(temp.value)
        return(str(selflist))

l=Node(43)
l.appendi(7)
l.appendr(8)
l.deleter(8)
l.deletei(7)
l.appendi(67)
l.insert(78)
print(l)
