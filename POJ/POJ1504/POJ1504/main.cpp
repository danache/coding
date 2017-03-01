//
//  main.cpp
//  POJ1504
//
//  Created by dan on 16/9/17.
//  Copyright © 2016年 dan. All rights reserved.
//
/*********************************************
 不要把事情想的太麻烦。。。
 *********************************************/

#include <iostream>
#define MAXN 1000
using namespace std;

long getReverse(long n){
    long long sum = 0;
    while( n != 0){
        sum  = sum * 10 + n % 10;
        n /= 10;
    }
    return sum;
}
int main(int argc, const char * argv[]) {
    int ncase;
    cin >> ncase;
    while(ncase--){
        long long a, b;
        cin >> a >> b;
        cout << getReverse(getReverse(a) + getReverse(b)) << endl;
    }
}
