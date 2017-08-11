//
//  main.cpp
//  leetcode375
//
//  Created by 萧天牧 on 17/8/10.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
#include <iostream>
#include <vector>
using namespace std;

int guess(int a, int b){
    if (a < b)
        return 1;
    if(a ==b)
        return 0;
    return -1;
}
int guessNumber(int n, int b) {
    int left = 1, right = n;
    int res = 0;
    while(left <= right){
        int mid = left +( (right - left) >> 1);
        res += mid;
        int res = guess(mid,b);
        if (res == 0)
            return mid;
        else if (res == 1)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    guessNumber(10, 6);
    return 0;
}
