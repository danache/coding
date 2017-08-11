//
//  main.cpp
//  leetcode166
//
//  Created by 萧天牧 on 17/6/27.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
string fractionToDecimal(int64_t n, int64_t d) {
    if(n == 0)
        return "0";
    string res;
    map<int,int> mp ;
    if (n < 0 ^ d < 0) res += '-';
    n = abs(n);
    d = abs(d);
    res += to_string(n / d);
    if(n % d == 0)
        return res;
    res += ".";
    for(int64_t r = n % d; r; r %= d){
        if(mp.count(r) > 0){
            res.insert(mp[r], 1, '(');
            res += ')';
            break;
        }
        mp[r] = res.size();
        r *= 10;
        res += to_string(r / d);
    }
    return res;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << fractionToDecimal(1, 2)<<endl;
//    std::cout << fractionToDecimal(2, 1)<<endl;
//    std::cout << fractionToDecimal(2, 3)<<endl;
    string res;
    res += to_string(100 / 3);
    cout << res;
    return 0;
}
