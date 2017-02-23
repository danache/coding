//
//  main.cpp
//  leetcode008
//
//  Created by 萧天牧 on 17/2/1.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
using namespace std;

int myAtoi(string str) {
    int sign = 1;
    int i = 0;
    int sum = 0;
    bool overflow = false;
    while (i < str.length() && (str[i] ==' ' || str[i] =='\t' || str[i] =='\n'))
        i++;
    if (i == str.length())
        return sum;
    if (str[i] == '-' || str[i] == '+'){
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while(i < str.length()){
        if (!isdigit(str[i]))
            break;
        if ((((sign == 1) && ((INT_MAX - (str[i] - '0')) / 10) < sum))|| ((sign == -1) && (-sum  < (INT_MIN + (str[i] - '0')) / 10))){
            overflow = true;
            break;
        }
        sum = sum * 10 + str[i] - '0';
        i++;
    }
    if (overflow)
        return sign == 1 ? INT_MAX : INT_MIN;
    else
        sum *= sign;
    return sum;
}
int main(){
    string s;
    cout << INT_MAX<<endl;
    cout << INT_MIN<<endl;
    
    while(cin >> s)
        cout << myAtoi(s)<<endl;
}
