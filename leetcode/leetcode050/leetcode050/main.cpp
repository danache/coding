//
//  main.cpp
//  leetcode050
//
//  Created by 萧天牧 on 17/6/12.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
//double myPow(double x, int n) {
//    if(x == 1 )
//        return 1;
//    if(x == -1)
//        return n % 2 == 0 ? 1 : -1;
//    if(n == INT_MIN)
//        return 0;
//    double res = 0;
//    bool flag = (n >= 0) ? true:false;
//    if(!flag)
//        n = -n;
//    if(x == 0)
//        return 0;
//    if(n == 0)
//        return 1;
//    res = myPow(x, n >> 1);
//    if(n % 2 == 0){
//        if(!flag)
//            return 1 /(res * res);
//        return res * res;
//    }
//    else{
//        if(!flag)
//            return 1 /(res * res*x);
//        return res * res * x;
//    }
//}
double myPow(double x, int n){
    unsigned long long p;
    double res = 1;
    if(n < 0){
        n = -n;
        x = 1 / x;
    }
    p = n;
    while(p){
        if(p&1)
            res *= x;
        x *= x;
        p = p>> 1;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << myPow(34.00515, -3)<<endl;
    cout << pow(34.00515,-3)<<endl;
    return 0;
}
