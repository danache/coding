def summaryRanges(self, nums):
    """
    :type nums: List[int]
    :rtype: List[str]
    """
    res = []
    if len(nums) == 0:
        return res
    begin = 0
    end = -99999999
    flag = False
    for i in range(len(nums)):

        if i != 0 and nums[i] - nums[i - 1] != 1:
            end = i - 1
            if begin == end:
                res.append("%d" % nums[begin])
            else:
                res.append("%d->%d" % (nums[begin], nums[end]))
            begin = i
            end = -99999999
            flag = False
        elif (i != 0):
            flag = True
    if flag:
        res.append("%d->%d" % (nums[begin], nums[-1]))
    else:
        res.append("%d" % nums[-1])
    return res