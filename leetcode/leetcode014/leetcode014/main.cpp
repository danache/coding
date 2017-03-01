//
//  main.cpp
//  leetcode014
//
//  Created by 萧天牧 on 17/2/23.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty())
        return "";
    for (int i = 0; i < strs[0].length(); i++) {
        for (int j = 1; j < strs.size(); j++)
            if (i >= strs[j].length() || strs[j][i] != strs[0][i])
                return strs[0].substr(0, i);
    }
    return strs[0];
}  int main(int argc, const char * argv[]) {
    vector<string> a = {"abc", "abd", "ab"};
    std::cout << longestCommonPrefix(a);
    return 0;
}
