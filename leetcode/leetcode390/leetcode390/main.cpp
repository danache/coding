//
//  main.cpp
//  leetcode390
//
//  Created by 萧天牧 on 17/8/11.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int getlast(int n, bool reverse){
    if(n ==  1)
        return 1;
    if(n == 2){
        if(reverse)
            return 1;
        else
            return 2;
    }
    
    int res = getlast(n / 2, !reverse);
    if (reverse){
        return res* 2 - 1 + n % 2;
    }
    else
        return 2 * res;
}
int lastRemaining(int n) {
    if(n == 1)
        return 1;
    return getlast(n, false);
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << lastRemaining(9)<<endl;
    return 0;
}
