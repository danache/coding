//
//  main.cpp
//  leetcode447
//
//  Created by 萧天牧 on 17/8/18.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;


int numberOfBoomerangs(vector<pair<int, int>>& points) {
    
    int res = 0;
    for(int i = 0; i < points.size(); i++){
        unordered_map<int,int> mp;
        for(int j = 0; j < points.size();j++ ){
            
            if (i == j)
                continue;
            int x = points[i].first - points[j].first;
            int y = points[i].second - points[j].second;
            mp[x * x + y * y]++;
        }
        unordered_map<int,int>::iterator it = mp.begin();
        
        while(it != mp.end()){
            if(it -> second > 1){
                res += (it -> second) * (it -> second - 1);
            }
            it++;
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<pair<int, int>> vec = {{0,0},{1,0},{-1,0},{0,1},{0,-1}};
    cout << numberOfBoomerangs(vec);
    std::cout << "Hello, World!\n";
    return 0;
}
