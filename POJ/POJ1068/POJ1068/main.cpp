//
//  main.cpp
//  POJ1068
//
//  Created by dan on 16/9/13.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

#define MAXN 20
int a[20];
stack<string> sta;
stack<string> stares;

void clearStack(stack<string> &s){
    while(!s.empty())
        s.pop();
}
void initStack(int *a, int ncase){
    int n = 0;
    for (int i = 0; i < ncase; i++){
        int lnum = a[i] - n;
        n = a[i];
        while(lnum--)
            sta.push("l");
        sta.push("r");
    }
    while(!sta.empty()){
        stares.push(sta.top());
        sta.pop();
    }
    
    while(!stares.empty()){
        string c = stares.top();
        stares.pop();
        if (c == "l"){
            sta.push(c);
            continue;
        }
        else{
            int sum = 0;
            while(true){
                string s = sta.top();
                sta.pop();
                if(s == "l"){
                    sum += 1;
                    cout << sum <<" ";
                    string s;
                    stringstream ss;
                    ss << sum;

                    sta.push(ss.str());

                    break;
                }
                else{
                    int tmp = atoi(s.c_str());
                    sum += tmp;
                }

            }
        }
    }
}

using namespace std;
int main(int argc, const char * argv[]) {
    int testCase, ncase;
    cin >> testCase;
    while (testCase--){
        cin >> ncase;
        for (int i = 0; i < ncase; i++){
            cin >> a[i];
        }
        initStack(a, ncase);
        cout << endl;
        memset(a, 0, sizeof(a));
        clearStack(stares);
        clearStack(sta);
    }
}
