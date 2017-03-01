//
//  main.cpp
//  POJ2103
//
//  Created by dan on 16/9/17.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stack>
#include <string>
#define MAXN 16
using namespace std;
queue<string> que;
stack<string> sta;
string p[MAXN];
void getRes(string* p, int n){
    for (int i = 0; i < n; i++){
        if (i % 2 == 0)
            que.push(p[i]);
        else
            sta.push(p[i]);
    };
    while(!que.empty()){
        cout << que.front() << endl;
        que.pop();
    }
    while(!sta.empty()){
        cout << sta.top() << endl;
        sta.pop();
    }
    
}
int main(int argc, const char * argv[]) {
    int n;
    int casenum = 1;
    while (cin >> n) {
        if (n == 0)
            break;
        for (int i = 0; i < n; i++){
            cin >> p[i];
        }
        cout << "SET " << casenum++ << endl;
        getRes(p, n);
        
    }
}
