//
//  main.cpp
//  leetcode474
//
//  Created by 萧天牧 on 17/8/23.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
static bool cmp(string a, string b){
    return a.size() < b.size();
}
pair<int, int> counts(string s){
    int num0 = 0, num1 = 0;
    for(auto c : s){
        if (c == '0')
            num0++;
        else
            num1++;
    }
    return make_pair(num0, num1);
}
int findMaxForm(vector<string>& strs, int m, int n) {
    int num = 0;
    if(strs.empty())
        return num;
    sort(strs.begin(), strs.end(), cmp);
    for(auto s : strs){
        pair<int, int> p = counts(s);
        if(m - p.first >= 0 && n - p.second >= 0){
            m -= p.first;
            n -= p.second;
            num++;
        }
    }
    return num;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> vec = {"10", "0001", "111001", "1", "0"};
    cout << findMaxForm(vec,5, 3);
    std::cout << "Hello, World!\n";
    return 0;
}
