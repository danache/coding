//
//  main.cpp
//  leetcode093
//
//  Created by 萧天牧 on 17/7/25.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
bool isValid()
void getIP(string s , string nowip, vector<string>  str, vector<string>& res, int leftIp){
    if(s.size() == 0 && leftIp == 0){
        res.push_back(nowip.substr(1));
        return;
    }
    if(s.size() > leftIp * 3)
        return;
    if(s[0]  == '0'){
        for(int i = 0; i < 1;i++){
            if(i == s.size())
                return;
            
            string tmp = nowip + '.' +s.substr(0,i + 1);
            getIP(s.substr(i + 1), tmp, res, leftIp - 1);
        }
    }
    if(s[0] == '1' || s[0] == '2'){
        for(int i = 0; i < 3;i++){
            //if((i == 1 || i == 2) && leftIp == 4)
            //  continue;
            if(i == s.size())
                return;
            string tmp = nowip + '.' +s.substr(0,i + 1);
            getIP(s.substr(i + 1), tmp, res, leftIp - 1);
        }
    }
    else if(s[0] >'2' && s[0] <= '9'){
        for(int i = 0; i < 2;i++){
            if(i == s.size())
                return;
            string tmp = nowip + '.' +s.substr(0,i + 1);
            getIP(s.substr(i + 1), tmp, res, leftIp - 1);
        }
    }
}
vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    string nowip = "";
    vector<string> str;
    getIP(s, nowip,str, res, 4);
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string a =  "Hello, World!\n";
    vector<string> s  = restoreIpAddresses("19216811");
    return 0;
}
