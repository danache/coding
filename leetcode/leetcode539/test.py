def findMinDifference(self, timePoints):
    """
    :type timePoints: List[str]
    :rtype: int
    """
    all = []
    for time in timePoints:
        tmp = time.split(":")
        minute = int(tmp[0]) * 60 + int(tmp[1])
        all.append(minute)
    all = sorted(all)
    minval = 99999
    for i in range(1,len(all)):

        minval = min(minval, abs(all[i] - all[i - 1]), 1440 - abs(all[i] - all[i - 1]))
    minval = min(minval, 1440 - abs(all[-1] - all[0]))
    return min(minval, 1440 - minval)

print findMinDifference(1,["05:31","22:08","00:35"])

