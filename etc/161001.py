
import os
import numpy as np
def softmax(x):
    """Compute softmax values for each sets of scores in x."""
    tem = [ pow(np.e, i) for i in x]
    tmp = sum (tem)
    res = np.array([(i * 1.0) / tmp for i in tem])
    return res
scores = [1.0, 2.0, 3.0]
print (1000000000+0.000001*1000000-1000000000)