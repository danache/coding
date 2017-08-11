//
//  main.cpp
//  leetcode394
//
//  Created by 萧天牧 on 17/7/13.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
string decodeString(string s) {
    if(s.empty())
        return s;
    stack<string> sta;
    stack<int> stint;
    int num = 0;
    string nowstr = "";
    stack<string> huanchun;
    for(int i = 0; i < s.size(); i++){
        if('0' <= s[i] && s[i] <='9')
            num = num * 10 + s[i] - '0';
        else if(s[i] == '['){
            
            stint.push(num);
            huanchun.push(nowstr);
            nowstr = "";
            num = 0;
        }
        else if(s[i] == ']'){
            int chongfu = stint.top();
            stint.pop();
            string tmp = "";
            
            for(int j = 0; j < chongfu; j++){
                tmp += nowstr;
            }
            tmp = huanchun.top() + tmp;
            huanchun.pop();
            nowstr = tmp;
        }
        else{
            nowstr += s[i];
        }
    }
    if(!nowstr.empty())
        sta.push(nowstr);
    stack<string> fuzhu;
    while(!sta.empty()){
        fuzhu.push(sta.top());
        sta.pop();
    }
    string res = "";
    while(!fuzhu.empty()){
        res += fuzhu.top();
        fuzhu.pop();
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << decodeString("3[a2[c]]")<<endl;
    cout << decodeString("2[abc]3[cd]ef")<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
