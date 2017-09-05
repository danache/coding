def reverseStr(self, s, k):
    """
    :type s: str
    :type k: int
    :rtype: str
    """
    if k >= len(s):
        return s[::-1]
    for i in range(len(s) / 2 / k + 1):
        begin = i*k*2
        end = min(i*k*2 + k, len(s))
        if(begin > end):
            break
        tmp = s[begin:end]
        tmp = tmp[::-1]
        s = s[:begin] + tmp + s[end:]
    return s


a = "hyzqyljrnigxvdtneasepfahmtyhlohwxmkqcdfehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqlimjkfnqcqnajmebeddqsgl"
print (a)
print a[:39]
print a[39:78]
print a[78:]
print reverseStr(1,s = "hyzqyljrnigxvdtneasepfahmtyhlohwxmkqcdfehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqlimjkfnqcqnajmebeddqsgl",k = 39)
