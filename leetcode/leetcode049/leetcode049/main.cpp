//
//  main.cpp
//  leetcode049
//
//  Created by 萧天牧 on 17/6/27.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    if(strs.size() == 0)
        return res;
    map<string, vector<string>> hashmap;
    for(int i = 0 ; i < strs.size(); i++){
        string str = strs[i];
        sort(str.begin(), str.end());
        if(hashmap.count(str) > 0){
            hashmap[str].push_back(strs[i]);
        }
        else {
            vector<string> tmp = {strs[i]};
            hashmap[str] = tmp;
        }
    }
    map<string, vector<string>>::iterator it = hashmap.begin();
    while(it != hashmap.end()){
        res.push_back(it -> second);
        it++;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> a = {"cat", "cta", "tca", "ssa"};
    vector<vector<string>> res = groupAnagrams(a);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++)
            cout<<res[i][j]<<" ";
        cout << endl;
    }
    return 0;
}
