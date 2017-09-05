//
//  main.cpp
//  leetcode397
//
//  Created by 萧天牧 on 17/8/14.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int getnum(vector<int>& a, int t){
    a[t] = a[t / 2] + 1;
    return a[t];
}
int integerReplacement(int n) {
    vector<int> a(n + 2, 0);
    a[1] = 0;
    a[2] = 1;
    for (int i = 3; i <= n; i += 2) {
        int ls = getnum(a, i - 1);
        int mr = getnum(a, i + 1);
        a[i] = min(ls, mr) + 1;
    }
    return a[n];
}
int main(int argc, const char * argv[]) {

    for(int i = 1; i < 20; i++)
        cout << "i = " << i <<" << integerReplacement(i)<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
