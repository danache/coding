//
//  main.cpp
//  leetcode071
//
//  Created by 萧天牧 on 17/7/10.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
string simplifyPath(string path) {
    if(path.size()  == 0)
        return path;
    string res, tmp;
    vector<string> stk;
    stringstream ss(path);

    while( getline(ss, tmp, '/')){
        if(tmp == "." || tmp == "")
            continue;
        if(tmp == ".." && !stk.empty())
            stk.pop_back();
        else if (tmp != "..")
            stk.push_back(tmp);
    }
    for(auto str : stk) res += "/"+str;
    return res.empty() ? "/" : res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
