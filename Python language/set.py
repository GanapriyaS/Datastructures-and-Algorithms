a={'red','yellow','red','orange',9,1,9}
print(a)
b=set()
print(b)
print('red' in a)
c=set([1,2,3,4,'red'])
print(c)
d=set('banana')
print(d)
print("UNION",a|c)
print("INTERSECTION",a&c)
print("SET DIFFERENCE",a-c)
print("EXCLUSIVE OR",a^c)
