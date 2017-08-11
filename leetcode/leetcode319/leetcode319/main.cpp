//
//  main.cpp
//  leetcode319
//
//  Created by 萧天牧 on 17/8/8.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int bulbSwitch(int n) {
    if(n == 0)
        return 0;
    
    vector<bool> a(n+1,false);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if((j ) % i == 0)
                a[j] = !a[j];
        }
    }
    int res = 0;
    for(int i = 0; i <= n; i++){
        if(a[i])
            res++;
        
    }
    return res;
}
////
int bulbSwitch(int n) {
    return sqrt(n);
}
///
//一个数的因数都是偶数，除了完全平方数！！！
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << bulbSwitch(4);
    return 0;
}
