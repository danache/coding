//
//  main.cpp
//  leetcode371
//
//  Created by 萧天牧 on 17/8/10.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int add(int a, int b){
    int c = a & b;
    int d = a ^ b;
    return c ==  0?d :add(d, c<< 1);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    add(2,3);
    std::cout << "Hello, World!\n";
    return 0;
}
