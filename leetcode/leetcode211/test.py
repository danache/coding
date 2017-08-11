import re
vec = ["bad","dad","mad"]
flag = False
for num in vec:
    a =  re.findall('b..', num)
    if(a):
        print("1")
print("0")
'''
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
'''