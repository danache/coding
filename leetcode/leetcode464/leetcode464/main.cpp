//
//  main.cpp
//  leetcode464
//
//  Created by 萧天牧 on 17/8/22.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
bool canIWin(int maxChoosableInteger, int desiredTotal) {
    while(desiredTotal > maxChoosableInteger){
        desiredTotal -= (maxChoosableInteger + 1);
    }
    if(desiredTotal == 0)
        return false;
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << canIWin(10, 11);
    
    return 0;
}
