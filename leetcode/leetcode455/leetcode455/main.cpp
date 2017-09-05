//
//  main.cpp
//  leetcode455
//
//  Created by 萧天牧 on 17/8/18.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0;
    int pos = 0;
    int num = 0;
    for(;i < s.size(); i++){
        if(s[i] < g[num])
            continue;
        num++;
        pos++;
        if(pos == g.size())
            break;
    }
    return num;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> g = {10,9,7,8};
    vector<int> s = {5,6,7,8};
    std::cout << findContentChildren(g, s)<<endl;
    return 0;
}
