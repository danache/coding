//
//  main.cpp
//  leetcode357
//
//  Created by 萧天牧 on 17/8/10.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int A(int n, int num){
    if (num == 0)
        return 1;
    if (num == 1)
        return n;
    else
        return n * A(n -1, num - 1);
}
int countNumbersWithUniqueDigits(int n) {
    if(n == 0)
        return 1;

    int nownum = 1;
    for(int i = 1; i <= n; i++){
        nownum += 9 *A(9, i -1);
    }
    return nownum;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << countNumbersWithUniqueDigits(1)<<endl;;
    ;
    return 0;
}
