//
//  main.cpp
//  leetcode258
//
//  Created by 萧天牧 on 17/7/4.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int addDigits(int num) {
    if(num == 0)
        return 0;
    if(num% 9 == 0)
        return 9;
    else
        
        return num % 9;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
