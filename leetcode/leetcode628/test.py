def maximumProduct(self, nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    nums = sorted(nums)
    a = nums[:3]
    b = nums[-3:]
    maxn = 1
    for i in b:
        maxn *= i
    print a
    print b
    return max(maxn, b[-1] * a[0] * a[1])


print maximumProduct(1,[9,1,5,6,7,2])