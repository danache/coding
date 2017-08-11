//
//  main.cpp
//  leetcode168
//
//  Created by 萧天牧 on 17/7/4.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

string convertToTitle(int n) {
    string res;
    if (n == 0)
        return res;
    while(n){
        if(n % 26 == 0)
            res += 'Z';
        else
            res += (n )% 26 -1+ 'A';
        n = (n - 1) /26;
        
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(int argc, const char * argv[]) {
    int n;
    while(cin >> n){
        cout << convertToTitle(n)<<endl;
    }
    return 0;
}
