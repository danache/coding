//
//  main.cpp
//  leetcode264
//
//  Created by 萧天牧 on 17/7/4.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int nthUglyNumber(int n) {
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    vector<int> vec(n);
    vec[0] =1;
    int t2 = 0, t3 = 0, t5 = 0;
    for(int i = 1; i < n; i++){
        int tmp = min(vec[t3] * 3, vec[t5] * 5);
        int minx = min(tmp, vec[t2] * 2);
        vec[i] = minx;
        if(minx == 2 * vec[t2])
            t2++;
        if(minx == 3 * vec[t3])
            t3++;
        if(minx == 5 * vec[t5])
            t5++;
    }
    return vec[n - 1];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    nthUglyNumber(7);
    std::cout << "Hello, World!\n";
    return 0;
}
