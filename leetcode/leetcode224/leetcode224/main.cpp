//
//  main.cpp
//  leetcode224
//
//  Created by 萧天牧 on 17/8/1.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int getIndex(char c){
    if(c == '+')
        return 0;
    if(c == '-')
        return 1;
    if(c == '(')
        return 2;
    if(c == ')')
        return 3;
    return -1;
};
bool op[4][4] = {
    {},
    {},
    {},
    {}
};

int calculate(string s) {
    if(s.empty())
        return 0;
    stack<char> num;
    stack<char> op;
    
    for( auto c : s){
        if(c == ' ')
            continue;
        if('0' <= c && c <= '9' ){
            num.push(c);
            
        }
        else{
            if(!num.empty() && '0' <= num.top() && num.top() <= '9')
                num.push('#');
            if(c ==')'){
                while(op.top() != '('){
                    num.push(op.top());
                    op.pop();
                }
                op.pop();
            }
            else if(c == '(')
                op.push(c);
            else{
                if(op.empty())
                    op.push(c);
                else{
                    
                    while(!op.empty() && op.top() != '('){
                        num.push(op.top());
                        op.pop();
                    }
                    op.push(c);
                }
            }
        }
        
    }
    if(!num.empty() && '0' <= num.top() && num.top() <= '9')
        num.push('#');
    while(!num.empty()){
        op.push(num.top());
        num.pop();
    }
    int nownum = 0;
    stack<int> fuzhu;
    
    while(!op.empty()){
        char c = op.top();
        op.pop();
        if('0' <= c && c <= '9'){
            nownum = nownum * 10 + c - '0';
        }
        else if (c == '#'){
            fuzhu.push(nownum);
            nownum = 0;
        }
        else{
            
            int a1 = fuzhu.top();
            fuzhu.pop();
            int a2 = fuzhu.top();
            fuzhu.pop();
            if(c =='+'){
                fuzhu.push(a1 + a2);
            }
            else
                fuzhu.push(a2 - a1);
        }
    }
    return fuzhu.top();
}
/*
 "1 + 1" = 2
 " 2-1 + 2 " = 3
 "(1+(4+5+2)-3)+(6+8)" = 23
 */
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << calculate("2-1+2");
    return 0;
}
