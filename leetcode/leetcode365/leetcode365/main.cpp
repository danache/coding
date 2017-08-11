//
//  main.cpp
//  leetcode365
//
//  Created by 萧天牧 on 17/8/10.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int gcd(int x, int y)
{
    return y==0?x:gcd(y, x%y);
}

bool canMeasureWater(int x, int y, int z) {
    if(z > x+y) return false;
    return z==0?true:z%gcd(x, y) ==0;
}
//本题关键是球最大公约数。。如果能整除就是可以，否则不行
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
