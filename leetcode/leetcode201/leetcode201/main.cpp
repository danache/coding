//
//  main.cpp
//  leetcode201
//
//  Created by 萧天牧 on 17/8/1.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int rangeBitwiseAnd(int m, int n) {
    if(m == n)
        return m;
    int count = 0;
    while(m != n){
        m >>= 1;
        n >>= 1;
        count ++;
    }
    return m << count;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
