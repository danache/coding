def findRestaurant(self, list1, list2):
    """
    :type list1: List[str]
    :type list2: List[str]
    :rtype: List[str]
    """
    a = dict()
    for i in range(len(list1)):
        if list1[i] in list2:
            a[list1[i]] = i
    for i in range(len(list2)):
        if list2[i] in a.keys():
            a[list2[i]] += i

    minnum = 99999
    bianhao = ""
    a = sorted(a.iteritems(), key=lambda d: d[1], reverse=True)
    res= []
    for i in a:
        res.append(i[0])
    return res

a = ["Shogun","Tapioca Express","Burger King","KFC"]
b = ["KFC","Burger King","Tapioca Express","Shogun"]

print(findRestaurant(1, a, b))