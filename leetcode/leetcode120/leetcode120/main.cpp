//
//  main.cpp
//  leetcode120
//
//  Created by 萧天牧 on 17/5/10.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int minimumTotal(vector<vector<int>>& triangle) {
    if(triangle.size() == 0)
        return 0;
    if(triangle.size() == 1)
        return triangle[0][0];
    if(triangle.size() == 2)
        return triangle[0][0] + min(triangle[1][0], triangle[1][1]);
    vector<int> tmp = triangle[triangle.size() - 1];
    
    for(int i = triangle.size() -2;i >= 0; i--){
        for(int j = 0; j < triangle[i].size(); j++){
            triangle[i][j] += min(triangle[i + 1][j],triangle[i + 1][j + 1] );
        }
        tmp = triangle[i];
    }
    
    return triangle[0][0];
}
int main(int argc, const char * argv[]) {
    vector<vector<int>> a = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << minimumTotal(a);
    std::cout << "Hello, World!\n";
    return 0;
}
