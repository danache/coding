//
//  main.cpp
//  leetcode400
//
//  Created by 萧天牧 on 17/8/16.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
//http://blog.csdn.net/qq508618087/article/details/52582162
int findNthDigit(int n) {
    long digit = 1, ith = 1, base = 9;
    while(n > base*digit)
    {
        n -= base*(digit++);
        ith += base;
        base *= 10;
    }
    return to_string(ith+(n-1)/digit)[(n-1)%digit]-'0';
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
