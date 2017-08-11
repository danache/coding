//
//  main.cpp
//  leetcode367
//
//  Created by 萧天牧 on 17/8/10.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
/**************************************/
//数学技巧，判断一个数是不是完全平方数，因为完全平方数一定可以表示成为 1 + 3 + 5 + .......
//int i = 1;
//while (num > 0) {
//    num -= i;
//    i += 2;
//}
//return num == 0;

//二分

bool isPerfectSquare(int num) {
    
    int left = 1, right = num;
    while(left <= right){
        long mid = left +( (right  - left) >> 1);
        if (mid * mid == num)
            return true;
        else if (mid * mid < num)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int num;
    while (cin >> num) {
        cout << isPerfectSquare(num)<<endl;
    }
    return 0;
}
