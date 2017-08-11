//
//  main.cpp
//  leetcode231
//
//  Created by 萧天牧 on 17/7/4.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
bool isPowerOfTwo(int n) {
    if(n == 0)
        return false;
    int count = 0;
    while(n){
        count += (n & 0x01);
        if(count > 1)
            return false;
        n >>= 1;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int n = 10;
    while(n){
        cout << (n & 0x01) << endl;
        n = n >> 1;
    }
    return 0;
}
