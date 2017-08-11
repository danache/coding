//
//  main.cpp
//  leetcode202
//
//  Created by 萧天牧 on 17/6/27.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
bool isHappy(int n) {
    map<int, int> mp;
    if(n == 1)
        return true;
    if(n < 3)
        return false;
    mp[n] = 1;
    
    while(true){
        int tmp = 0;
        while(n){
            tmp += pow((n % 10), 2);
            n /= 10;
        }
        if(tmp == 1)
            return true;
        else if(mp[tmp] > 0)
            return false;
        else {
            mp[tmp] = 1;
            n = tmp;
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << isHappy(1)<<endl;
    return 0;
}
