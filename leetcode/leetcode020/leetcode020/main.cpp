//
//  main.cpp
//  leetcode020
//
//  Created by 萧天牧 on 17/2/27.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> sta;
    //()[]{}
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            sta.push(s[i]);
        else if(s[i] == ')'){
            if(sta.empty())
                return false;
            char t = sta.top();
            if (t == '(')
                sta.pop();
            else
                return false;
        }
        else if(s[i] == ']'){
            if(sta.empty())
                return false;
            char t = sta.top();

            if (t == '[')
                sta.pop();
            else
                return false;
        }
        else if(s[i] == '}'){
            if(sta.empty())
                return false;
            char t = sta.top();

            if (t == '{')
                sta.pop();
            else
                return false;
        }
    }
    return sta.size() == 0;
}int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << isValid("]");
    return 0;
}
