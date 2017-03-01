//
//  main.cpp
//  POJ2155
//
//  Created by dan on 16/10/25.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#define MAXN 10000
using namespace std;
int a[MAXN];
int getMin(int x){
    return x & (-x);
}

void update(int num, int i){
    while (i < MAXN){
        a[i] += num;
        i += getMin(i);
    }
}

void sum(int i){
    int ans = 0;
    while(i > 0){
        ans += a[i];
        i -= getMin(i);
    }
}
int main(int argc, const char * argv[]) {
    cout << getMin(6) << endl;
    
}
