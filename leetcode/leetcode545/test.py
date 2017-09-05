def distributeCandies(self, candies):
    """
    :type candies: List[int]
    :rtype: int
    """
    l1 = len(candies)
    l2 = len(set(candies))
    if l2 >= 0.5 * l1:
        return int(0.5 * l1)
    else:
        return l2