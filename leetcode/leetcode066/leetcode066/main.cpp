//
//  main.cpp
//  leetcode066
//
//  Created by 萧天牧 on 17/5/6.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> plusOne(vector<int>& digits) {
    int jinwei = 0;
    reverse(digits.begin(), digits.end());
    for(int i = 0; i < digits.size(); i++){
        int tmp = digits[i] + 1;
        digits[i] = tmp % 10;
        jinwei = tmp / 10;
        if(jinwei == 0)
            break;
    }
    if(jinwei == 1)
        digits.push_back(1);
    reverse(digits.begin(), digits.end());
    return digits;
}
int main(int argc, const char * argv[]) {
    vector<int> a = {9};
    plusOne(a);
    for(int i = 0; i < a.size(); i++)
        cout << a[i];
    return 0;
}
