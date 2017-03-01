//
//  main.cpp
//  leetocde029
//
//  Created by 萧天牧 on 17/2/28.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
using namespace std;

int divide(int dividend, int divisor) {
    if (divisor == 0 || ((dividend == INT_MIN) && (divisor = -1)))
        return INT_MAX;
    long long absDividend = labs(dividend);
    long long absDivisor = labs(divisor);
    int flag = ((divisor >0)^(dividend > 0))?-1:1;
    int res = 0;
    while(absDividend >= absDivisor){
        long long tmp = absDivisor;
        int sig = 0;
        while(absDividend >= tmp << 1){
            tmp <<= 1;
            sig <<= 1;
        }
        absDividend -= tmp;
        res += sig;
    }
    return flag == 1? res : -res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << (((1<2)^(2 < 3))? -1 : 1);
    return 0;
}
