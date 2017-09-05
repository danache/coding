def findWords(self, words):
    """
    :type words: List[str]
    :rtype: List[str]
    """
    row1 = ['q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p']
    row2 = ['a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l']
    row3 = ['z', 'x', 'c', 'v', 'b', 'n', 'm']

    sss = []

    for loword in words:
        lst = []
        flag = True
        word = loword.lower()
        for i in word:
            if i in row1:
                if len(lst) == 0:
                    lst.append(1)
                    break
                else:
                    if (1 not in lst):
                        flag =  False
                        break
            if i in row2:
                if len(lst) == 0:
                    lst.append(2)
                    break
                else:
                    if (2 not in lst):
                        flag = False
                        break
            if i in row3:
                if len(lst) == 0:
                    lst.append(3)
                    break
                else:
                    if (3 not in lst):
                        flag = False
                        break
        if flag:
            sss.append(loword)

    return sss

print findWords(0,["a","b"])