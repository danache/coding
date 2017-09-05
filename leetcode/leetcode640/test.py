def getxishu(self,left):
    leftnum = 0
    leftxishu = 0
    now = 0
    minus = 1
    for i in range(len(left)):
        c = left[i]
        if c == '-':
            if left[i - 1] != 'x':
                leftnum += minus * now
            now = 0
            minus = -1
        elif c == '+':
            if left[i - 1] != 'x':
                leftnum += minus * now
            now = 0
            minus = 1
        elif '0'<= c and c <= '9':
            now = now * 10 + int(c)
        elif c == 'x':
            if i > 0 and left[i - 1] == '0':
                continue
            if now == 0:
                leftxishu += 1 * minus
            else:
                leftxishu += now * minus
            now = 0
            minus = 1
    leftnum += now * minus
    return leftxishu,leftnum
def solveEquation(self, equation):
    """
    :type equation: str
    :rtype: str
    """
    left,right = equation.split("=")

    rightxishu = 0

    leftxishu, leftnum =getxishu(1,left)
    rightxishu, rightnum = getxishu(1,right)
    print leftxishu,leftnum,rightxishu,rightnum
    if leftxishu == rightxishu :
        if leftnum == rightnum:
            return "Infinite solutions"
        else:
            return "No solution"
    solve = (leftnum - rightnum)*1.0 / (-leftxishu + rightxishu)
    return "x=%d" % solve


print solveEquation(11,"0x=0")