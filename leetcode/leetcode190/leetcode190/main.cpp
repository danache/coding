//
//  main.cpp
//  leetcode190
//
//  Created by 萧天牧 on 17/8/1.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for(int i = 0; i < 32; i++){
        if(n & 1){
            res = (res << 1) + 1;
        }
        else
            res <<= 1;
        n >>= 1;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    uint32_t a = 43261596;
    cout << reverseBits(a);
    std::cout << "Hello, World!\n";
    return 0;
}
