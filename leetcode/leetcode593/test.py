def getDis( p1, p2):
    return (p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1])
def validSquare(self, p1, p2, p3, p4):
    """
    :type p1: List[int]
    :type p2: List[int]
    :type p3: List[int]
    :type p4: List[int]
    :rtype: bool
    """
    a = set()
    b = set()
    b.add(tuple(p1))
    b.add(tuple(p2))
    b.add(tuple(p3))
    b.add(tuple(p4))
    if len(b) != 4:
        return False

    for i in range(len(b)):
        for j in range(i + 1, len(b)):
            a.add(getDis(b[i],b[j]))
    print a
    return len(a) ==  2

#print set()
a = tuple([0,1])
b = tuple([0,0])
c = tuple([0,1])
d = [a,b,c]
e= set(d)
print e