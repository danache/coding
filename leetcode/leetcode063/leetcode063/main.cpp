//
//  main.cpp
//  leetcode063
//
//  Created by 萧天牧 on 17/5/5.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int maps[101][101];

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    for(int i = 0; i < m; i++)
        maps[i][n] = 0;
    for(int j = 0; j < n; j++)
        maps[m][j] = 0;
    int rowx = m - 1, rowy = n - 1;
    maps[m][n-1] = 1;
    while(true){
        for(int i = rowx; i>= 0; i--)
            if(obstacleGrid[i][rowy] == 0)
                maps[i][rowy] = maps[i+1][rowy] + maps[i][rowy+1];
            else
                maps[i][rowy] = 0;
        for(int j = rowy; j>= 0; j--){
            if(obstacleGrid[rowx][j] == 0)
                maps[rowx][j] = maps[rowx][j+1] + maps[rowx+1][j];
            else
                maps[rowx][j] = 0;
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
    std::cout << "Hello, World!\n";
    return 0;
}
