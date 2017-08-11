//
//  main.cpp
//  leetcode171
//
//  Created by 萧天牧 on 17/7/4.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int titleToNumber(string s) {
    int64_t n = 0;
    int64_t jinwei = 1;
    for(int i = s.size() - 1; i >= 0; i--){
        n += (s[i] - 'A' + 1) * jinwei;
        jinwei *= 26;
    }
    return n;
}
int main(int argc, const char * argv[]) {
    string s;
    while(cin >> s){
        cout << titleToNumber(s) << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
