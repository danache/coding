//
//  main.cpp
//  leetcode118
//
//  Created by 萧天牧 on 17/5/10.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    if(numRows == 0)
        return res;
    vector<int> a = {1};
    res.push_back(a);
    for(int i = 2; i <= numRows; i++){
        vector<int> tmp = {1};
        for(int j = 1; j < i - 1; j++){
            tmp.push_back((res[i - 2][j - 1] + res[i - 2][j]));
        }
        tmp.push_back(1);
        res.push_back(tmp);
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<vector<int>> a = generate(3);
    
    std::cout << "Hello, World!\n";
    return 0;
}
