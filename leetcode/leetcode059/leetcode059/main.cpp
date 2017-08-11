//
//  main.cpp
//  leetcode059
//
//  Created by 萧天牧 on 17/4/27.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res;
    for(int i = 0; i < n; i++){
        vector<int> tmp;
        for(int j = 0; j < n; j++)
            tmp.push_back(0);
        res.push_back(tmp);
    }
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
