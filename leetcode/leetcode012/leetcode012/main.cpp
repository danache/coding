//
//  main.cpp
//  leetcode012
//
//  Created by 萧天牧 on 17/2/23.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
using namespace std;
string intToRoman(int num) {
    string roma = "MDCLXVI";
    int roma_num[] = {1000, 500, 100, 50, 10, 5, 1};
    string res;
    for(int i = 0; i < num / 1000; i++)
        res += "M";
    num %=  1000;
    if(num / 100 == 9){
        res += "CM";
        num -= 900;
    }
    else if (num >= 500)
    {
        res += "D";
        num -= 500;
    }
    if (num / 100 == 4){
        res += "CD";
        num -= 400;
    }
    else
        for (int i = 0; i < num / 100; i++)
            res += "C";
    num %= 100;
    if(num / 10 == 9){
        res += "XC";
        num -= 90;
    }
    else if (num >= 50)
    {
        res += "L";
        num -= 50;
    }
    if (num / 10 == 4){
        res += "XL";
        num -= 40;
    }
    else
        for (int i = 0; i < num / 10; i++)
            res += "X";
    num %= 10;
    if (num == 9){
        res += "IX";
        return res;
    }
    else if(num >= 5){
        res += "V";
        num -= 5;
    }
    if (num / 1 == 4){
        res += "IV";
    }
    else{
        for (int i = 0; i < num ; i++)
            res += "I";

    }
    return res;
}

int main(int argc, const char * argv[]) {
    int a;
    while (cin >> a) {
        cout << intToRoman(a) << endl;
    }
}
