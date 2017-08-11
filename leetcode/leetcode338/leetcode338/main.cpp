//
//  main.cpp
//  leetcode338
//
//  Created by 萧天牧 on 17/8/9.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> countBits(int num)
{
    vector<int> ret(num + 1, 0);
    for (int i = 1; i <= num; ++i)
        ret[i] = ret[i&(i - 1)] + 1;
    return ret;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
