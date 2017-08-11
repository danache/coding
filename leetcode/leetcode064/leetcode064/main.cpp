//
//  main.cpp
//  leetcode064
//
//  Created by 萧天牧 on 17/5/5.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int minPathSum(vector<vector<int>>& grid) {
    int maps[1000][1000];
    int m = grid.size();
    int n = grid[0].size();
    for(int i = 0; i < m; i++)
        maps[i][n] = 999999;
    for(int j = 0; j < n; j++)
        maps[m][j] = 999999;
    int rowx = m - 1, rowy = n - 1;
    maps[m][n-1] = 0;
    maps[m-1][n] = 0;
    while(true){
        for(int i = rowx; i>= 0; i--)
            maps[i][rowy] = grid[i][rowy] + min(maps[i+1][rowy] ,maps[i][rowy+1]);
        for(int j = rowy; j>= 0; j--){
            maps[rowx][j] = grid[rowx][j]+min(maps[rowx][j+1] , maps[rowx+1][j]);
        }
        if(rowx == 0 || rowy == 0)
            break;
        rowx--;
        rowy--;
    }
    return maps[0][0];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> grid = {{1,2},{1,1}};
    cout <<minPathSum(grid);
    std::cout << "Hello, World!\n";
    return 0;
}
