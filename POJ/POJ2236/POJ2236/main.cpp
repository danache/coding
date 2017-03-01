//
//  main.cpp
//  POJ2236
//
//  Created by dan on 16/9/26.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <stdio.h>
#define MAXN 20005
using namespace std;
struct computer{
    int x;
    int y;
};

int father[MAXN];
computer location[MAXN];
int ranks[MAXN];
bool repair[MAXN];

int num, dis;
void init(int n){
    for (int i = 1; i <= n; i++){
        father[i] = i;
        ranks[i] = 0;
        location[i].x = 0;
        location[i].y = 0;
    }
    memset(repair, false, sizeof(repair));
}

int find(int x){
    if (x == father[x])
        return x;
    else
        return father[x] = find(father[x]);
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (ranks[x] < ranks[y])
        father[x] = y;
    else{
        father[y] = x;
        if (ranks[x] == ranks[y])
            ranks[x]++;
    }
}

bool issame(int x, int y){
    return find(x) == find(y);
}

bool getDistance(computer &a, computer &b){
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    
    if (pow(double(dx), 2) + pow(double(dy), 2) <= pow(double(dis), 2 )){
        return true;
    }
    else
        return false;
    
}
void update(int newnumber){
    for (int i = 1; i <= num; i++){
       
        if(repair[i]){
            if (!issame(newnumber, i) && getDistance(location[newnumber], location[i])){
                unite(newnumber, i);
            }
        }
    }
}
void printres(){
    for (int i = 1; i <= num; i++){
        cout << father[i] << endl;
    }
    
}
int main(int arg, const char * argv[]) {
    scanf("%d%d", &num, &dis);
    init(num);
    for(int i = 1; i <= num; i++){
        cin >> location[i].x >> location[i].y;
    }
    
    char s;
    int a, b;
    while(cin >> s){
        if (s == 'O'){
            cin >> a;
            repair[a] = true;
            update(a);
        }
        else{
            cin >> a >> b;
            if(issame(a, b)) {
                cout << "SUCCESS" << endl;
            }
            else
                cout << "FAIL" << endl;
        }
    }
}
