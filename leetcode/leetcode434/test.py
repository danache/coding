def countSegments(self, s):
    """
    :type s: str
    :rtype: int
    """
    sasa = len(s)
    while(True):
        if(len(s) == 0):
            break
        if s[0] != " ":
            break
        s = s[1:]
    while(True):
        if (len(s) == 0):
            break
        if s[len(s) - 1] != " ":
            break
        s = s[:-1]
    if(len(s) == 0):
        return 0
    count = 0
    for i in range(len(s)):
        c = s[i]
        if(s[i] == " " and (i != 0) and (s[i - 1] != " ")):
            count += 1
    return count + 1

print countSegments(1,", , , ,        a, eaefa")

