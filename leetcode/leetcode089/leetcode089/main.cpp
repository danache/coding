//
//  main.cpp
//  leetcode089
//
//  Created by 萧天牧 on 17/7/25.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> grayCode(int n) {
    vector<int> res;
    for(int i = 0; i < pow(2,n); i++){
        res.push_back((i >> 1) ^ i);
    }
    return res;
    
}
int main(int argc, const char * argv[]) {
    grayCode(0);
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
