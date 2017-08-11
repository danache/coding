//
//  main.cpp
//  leetcode205
//
//  Created by 萧天牧 on 17/6/27.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
string transferStr(string s){
    char table[128] = {0};
    char tmp = '0';
    for(int i = 0; i < s.size(); i++){
        char c = s.at(i);
        if(table[c] == 0)
            table[c] = tmp++;
        s[i] = table[c];
    }
    return s;
}
bool isIsomorphic(string s, string t) {
    
    if (s.length() != t.length()) {
        return false;
    }
    if (transferStr(s) == transferStr(t)) {
        return true;
    }
    return false;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
