//
//  main.cpp
//  leetcode022
//
//  Created by 萧天牧 on 17/2/27.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void dfs(string str, int left, int right,vector<string> &result){
    if(right == 0){
        result.push_back(str);
    }
    if(0 < left){
        dfs(str+'(', left - 1, right, result);
    }
    if(left < right){
        dfs(str+')', left, right - 1, result);
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> result;
    if (n == 0)
        return result;
    string str = "";
    dfs(str, n, n, result);
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
