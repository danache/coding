//
//  main.cpp
//  leetcode187
//
//  Created by 萧天牧 on 17/6/27.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<string> findRepeatedDnaSequences(string s) {
    vector<string> res ;
    if(s.size() < 10)
        return res;
    map<string, int> mp;
    for(int i = 9; i < s.size(); i++){
        string subs = s.substr(i - 9, 10);
        if(mp.count(subs) > 0)
            mp[subs] ++;
        else
            mp[subs] = 1;
    }
    map<string, int>::iterator it = mp.begin();
    while(it != mp.end()){
        
        if(it -> second > 1)
            res.push_back(it -> first);
        it++;
    }
    return res;
}int main(int argc, const char * argv[]) {
    // insert code here...
findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    cout << s.substr(3,12)<<endl;
    return 0;
}
