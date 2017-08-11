//
//  main.cpp
//  leetcode165
//
//  Created by 萧天牧 on 17/7/31.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int getver(string s, int &cur, int length){
    int buffer = 0;
    while(cur < length && s[cur] != '.'){
        buffer = 10 * buffer + s[cur] - '0';
        cur++;
    }
    cur++;
    return buffer;
}
int compareVersion(string version1, string version2) {
    int cur1 = 0;
    int cur2 = 0;
    while(cur1 < version1.length() || cur2 < version2.length()){
        int v1 = getver(version1, cur1, version1.length());
        int v2 = getver(version2, cur2, version2.length());
        if(v1 > v2 )
            return 1;
        else if (v1 < v2 )
            return -1;
    }
    return 0;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
