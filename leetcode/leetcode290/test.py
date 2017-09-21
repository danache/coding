def wordPattern( pattern, str):
    """
    :type pattern: str
    :type str: str
    :rtype: bool
    """
    tmp1 = dict()
    tmp2 = dict()
    word_list = str.split(" ")
    if len(word_list) != len(pattern):
        return False
    for i in range(len(pattern)):
        word = word_list[i]
        if (word not in tmp1) and (pattern[i] not in tmp2):
            tmp1[word] = pattern[i]
            tmp2[pattern[i]] = word
        elif word in tmp1:
            if (tmp1[word] != pattern[i]) :
                return False
        elif pattern[i] in tmp2:
            if tmp2[pattern[i]] != word:
                return False

    return True

print(wordPattern("aba", "dog cat cat"))