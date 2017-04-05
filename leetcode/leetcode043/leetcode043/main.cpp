//
//  main.cpp
//  leetcode043
//
//  Created by 萧天牧 on 17/3/6.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
using namespace std;
string multiply(string num1, string num2) {
    string sum(num1.size() + num2.size(),'0');
    for (int i = num1.size() - 1; i >= 0; i--){
        int carry = 0;
        for (int j = num2.size() - 1; j >= 0; j--){
            int tmp = sum[i + j + 1] - '0' + carry + (num1[i] - '0') * (num2[j] - '0');
            sum[i + j + 1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        sum[i] += carry;
    }
    size_t startpos = sum.find_first_not_of("0");
    if (string::npos != startpos) {
        return sum.substr(startpos);
    }
    return "0";
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string s1 = "123", s2 = "4567";
    cout << multiply(s1, s2);
    
    return 0;
}
