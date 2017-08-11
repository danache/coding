def isvalid(remain, num1, num2):
    if len(remain) == 0:
        return True
    sum = num1 + num2
    if not remain.startswith(str(sum)):
        return False
    return isvalid(remain[len(str(sum)):],num2, sum)
def isAdditiveNumber(num):
    """
    :type num: str
    :rtype: bool
    """
    L = len(num)
    for i in range(1,L / 2 +1):
        for j in range (i + 1, L):
            if (L - j) < max(i, j - i):
                break
            n1 = num[:i]

            n2 = num[i:j]
            flag1 = n1.startswith("0")
            flag2 = n2.startswith("0")
            flag3 = len(n1)
            flag4 = len(n2)

            if (j - i >= 1 and (n1.startswith("0") and len(n1) > 1) or
                    (n2.startswith("0") and len(n2) > 1)):
                break
            if isvalid(num[j:], int(n1), int(n2)):
                return True
    return False
print (isAdditiveNumber("199001200"))
#print (range(2, 4))

