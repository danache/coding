//
//  main.cpp
//  leetcode172
//
//  Created by 萧天牧 on 17/7/4.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int64_t trailingZeroes(int64_t n) {
    int64_t res = 0;
    int64_t init = 5;
    while(init <= n){
        res += n / init;
        init *= 5;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
