//
//  bracket.cpp
//  stack
//
//  Created by dan on 16/8/31.
//  Copyright © 2016年 dan. All rights reserved.
//

#include "bracket.hpp"
#include <iostream>
#include <stack>
using namespace std;

bool ismate(string str){
    stack<char> sta;
    for (int i = 0; i < str.length(); i++){
        if (str[i] == '(')
            sta.push(str[i]);
        else if(str[i] == ')'){
            if (sta.empty()){
                return false;
            }
            char head = sta.top();
            if (head == '(')
                sta.pop();
            else
                sta.push(str[i]);
        }
        else return false;
    }
    if (!sta.empty())
        return false;
    return true;
}
void prints(string str){
    cout << str << "is: " << ismate(str) << endl;
}
/*
int main(int argc, const char * argv[]) {
    prints("()");
    prints("()(");
    prints("())");
    prints("()()");
    prints("(())");
    prints("(()()()");
}
*/