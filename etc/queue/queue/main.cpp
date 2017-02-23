//
//  main.cpp
//  queue
//
//  Created by dan on 16/9/1.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <queue>
using namespace std;
const int maxnum = 1000;

struct event{
    int l,p;
};

bool solve(int k, int tem[2][maxnum]){
    if (k <= 0)
        return false;
    queue<event> que;
    event e1, e2;
    int l = 1, p = 1;
    e1.l = 1;
    e1.p = 1;
    que.push(e1);
    while(!que.empty()){
        e1 = que.front();
        l = e1.l;
        p = e1.p;
        if (p == 1 || p == l)
            tem[l % 2][p] = 1;
        else{
            tem[l % 2][p] = tem[(l - 1) % 2][p - 1] + tem[(l - 1) % 2][p] ;
        }
        if(l != k){
            e2.l = l + 1;
            e2.p = p;
            que.push(e2);
            if(p == l)
                e2.p = p + 1;
            que.push(e2);
        }
        que.pop();
    }
    return true;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int tem[2][maxnum];
    int k;
    while(true){
        cin >> k;
        solve(k, tem);
        for (int i = 1; i <= k; i++)
            cout << tem[k %2][i] <<" ";
        cout << endl;
    }
    return 0;
}
