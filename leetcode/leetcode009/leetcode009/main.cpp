//
//  main.cpp
//  leetcode009
//
//  Created by 萧天牧 on 17/2/1.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
bool isPalindrome(int x) {
    int dx = x;
    int y = 0;
    
    while ( dx != 0 ) {
        y = y * 10 + dx % 10;
        dx /= 10;
    }
    return x >= 0 && (x == y);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int x;
    std::cin >> x;
    std::cout <<isPalindrome(x);
    return 0;
}
