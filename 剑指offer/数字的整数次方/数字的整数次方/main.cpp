//
//  main.cpp
//  数字的整数次方
//
//  Created by 萧天牧 on 17/5/11.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
double Power(double base, int exponent) {
    
    if(base == 0)
        return 0;
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;
    double tmp = Power(base, exponent >> 1);
    tmp *= tmp;
    if(exponent & 0x01)
        tmp *= base;
    return tmp;
}
int main(int argc, const char * argv[]) {
    cout << Power(2,2);
    return 0;
}
