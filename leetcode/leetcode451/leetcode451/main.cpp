//
//  main.cpp
//  leetcode451
//
//  Created by 萧天牧 on 17/8/18.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
int cmp(const pair<char, int>& x, const pair<char, int>& y)
{
    return x.second > y.second;
}
void sortMapByValue(map<char, int>& tMap,vector<pair<char, int> >& tVector)
{
    for (map<char, int>::iterator curr = tMap.begin(); curr != tMap.end(); curr++)
        tVector.push_back(make_pair(curr->first, curr->second));
    
    sort(tVector.begin(), tVector.end(), cmp);
}
string frequencySort(string s) {
    map<char, int> mp;
    for(auto c : s){
        mp[c]++;
    }
    vector<pair<char, int> > vec;
    sortMapByValue(mp, vec);
    string p = " ";
    string str = "";
    for(int i = 0; i < vec.size(); i++){
        for(int j = 0; j < vec[i].second; j++){
            p[0] = vec[i].first;
            str += (p);
        }
    }
    return str;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << frequencySort("tree");
    return 0;
}
