//
//  main.cpp
//  leetcode383
//
//  Created by 萧天牧 on 17/8/11.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
#include <map>
bool canConstruct(string ransomNote, string magazine) {
    map<int, int> mp;
    for(auto c : magazine){
        if(mp.count(c) == 0){
            mp[c] = 1;
        }
        else{
            mp[c]++;
        }
    }
    for(auto c : ransomNote){
        if(mp.count(c) == 0|| mp[c] == 0)
            return false;
        else{
            mp[c]--;
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << canConstruct("a", "b") << endl;
    cout << canConstruct("aa", "ab") << endl;
    cout << canConstruct("aa", "aab") << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
