//
//  main.cpp
//  leetcode007
//
//  Created by 萧天牧 on 17/2/1.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
using namespace std;
int reverse(int x) {
    long sum = 0;
    int a[1000];
    int i = 0;
    bool flag = true;
    if (x < 0)
        flag = false;
    x = abs(x);
    while (x > 0){
        a[i++] = x % 10;
        x /= 10;
    }
    int j = 0;
    while(j < i){
        sum *= 10;
        sum += a[j];
        j++;
    }
    if (sum > 2147483647 || sum < -2147483647)
        return 0;
    if (!flag)
        sum = -sum;

    return sum;
}
int main(int argc, const char * argv[]) {
    int x;
    cout << (1 << 31);
    while(cin >>x){
        cout << reverse(x)<<endl;
    }
}
