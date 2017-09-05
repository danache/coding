
def lcm(x, y): # very fast
    s = x*y
    while y: x, y = y, x%y
    return s//x
def gcd(a, b):
    if a < b:
        a, b = b, a

    while b != 0:
        temp = a % b
        a = b
        b = temp

    return a
def fractionAddition(self, expression):
    res = 0
    fenzi = 0
    fenmu = 0
    minus = 1
    fen= False
    fz = []
    fm = []
    for c in expression:
        if c == '-':

            if fenmu != 0:
                fz.append(fenzi*minus)
                fm.append(fenmu)
            fenzi = 0
            fenmu = 0
            minus = -1
            fen = False
            continue
        elif c == '+':
            if fenmu != 0:
                fz.append(fenzi*minus)
                fm.append(fenmu)
            fenzi = 0
            fenmu = 0
            minus = 1
            fen = False
            continue
        elif c == '/':
            fen = True
            continue
        else:
            if fen:
                fenmu = fenmu * 10 + int(c)
            else:
                fenzi = fenzi * 10 + int(c)
    fz.append(fenzi * minus)
    fm.append(fenmu)
    minlcm = fm[0]
    for i in range(1,len(fm)):
        minlcm = lcm(minlcm, fm[i])

    for i in range(len(fz)):
        fz[i] = fz[i]*minlcm / fm[i]
    res = 0
    for i in fz:
        res += i

    if res == 0:
        return "0/1"
    if res < 0:
        minus = -1
        res = -res
    else:
        minus = 1
    gc = gcd(res, minlcm)
    return "%d/%d" % (res*minus / gc, minlcm / gc)



print fractionAddition(1,"-1/2+1/2+1/3")
