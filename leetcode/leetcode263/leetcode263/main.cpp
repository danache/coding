//
//  main.cpp
//  leetcode263
//
//  Created by 萧天牧 on 17/7/4.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
bool isUgly(int num) {
    if(num <= 0)
        return false;
    while(num % 2 == 0){
        num /= 2;
    }
    while(num % 3 == 0)
        num /= 3;
    while(num % 5 == 0)
        num /= 5;
    return num == 1 ;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << isUgly(1);
    return 0;
}
