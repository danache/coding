//
//  main.cpp
//  leetcode013
//
//  Created by 萧天牧 on 17/2/23.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
using namespace std;
int romanToInt(string s) {
    //I(1)，V(5)，X(10)，L(50)，C(100)，D(500)，M(1000)
    int num = 0;
    for(int i = 0; i < s.length(); i++){
        if (s[i] == 'M')
            num += 1000;
        if (s[i] == 'D')
            num += 500;
        if (s[i] == 'C' && i != s.length() && s[i + 1] == 'M'){
            num += 900;
            i++;
        }
        if (s[i] == 'C' && i != s.length() && s[i + 1] == 'D'){
            num += 400;
            i++;
        }
        if (s[i] == 'C')
            num += 100;
        if (s[i] == 'L' ){
            num += 50;
        }
        if (s[i] == 'X' && i != s.length() && s[i + 1] == 'C'){
            num += 90;
            i++;
        }
        if (s[i] == 'X' && i != s.length() && s[i + 1] == 'L'){
            num += 40;
            i++;
        }
        if (s[i] == 'X' ){
            num += 10;
        }
        if (s[i] == 'V' ){
            num += 5;
        }
        if (s[i] == 'I' && i != s.length() && s[i + 1] == 'X'){
            num += 9;
            i++;
        }
        if (s[i] == 'I' && i != s.length() && s[i + 1] == 'V'){
            num += 4;
            i++;
        }
        if (s[i] == 'I' ){
            num += 1;
        }
    }
    return num;
}
int main(int argc, const char * argv[]) {
    string s;
    while (cin >> s) {
        cout << romanToInt(s)<<endl;
    }
}
