//
//  main.cpp
//  leetcode415
//
//  Created by 萧天牧 on 17/8/16.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
string addStrings(string num1, string num2) {
    if(num1.empty())
        return num2;
    if(num2.empty())
        return num1;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int jinwei = 0;
    int i = 0;
    string res = "";
    while(i < num1.size() && i < num2.size()){
        int nownum = num1[i] - '0' + num2[i] - '0' + jinwei;
        jinwei = nownum / 10;
        res += (to_string(nownum % 10));
        i++;
    }
    if(i < num1.size()){
        while(jinwei || i < num1.size()){
            if(jinwei){
                int nownum = 0;
                if(i < num1.size())
                    nownum = num1[i] - '0' + jinwei;
                else
                    nownum = jinwei;
                jinwei = nownum / 10;
                res += (to_string(nownum % 10));
                i++;
            }
            else{
                res += num1.substr(i);
                break;
            }
        }
    }
    else{
        while(jinwei || i < num2.size()){
            if(jinwei){
                int nownum = 0;
                if(i < num2.size())
                    nownum = num2[i] - '0' + jinwei;
                else
                    nownum = jinwei;
                jinwei = nownum / 10;
                res += (to_string(nownum % 10));
                i++;
            }
            else{
                res += num2.substr(i);
                break;
            }
        }
    }
    reverse(res.begin(), res.end());
    return res;
        
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << addStrings("12", "456");
    return 0;
}
