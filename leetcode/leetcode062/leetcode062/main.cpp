//
//  main.cpp
//  leetcode062
//
//  Created by 萧天牧 on 17/5/5.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int maps[101][101];

int uniquePaths(int m, int n) {
    for(int i = 0; i < m; i++)
        maps[i][n] = 0;
    for(int j = 0; j < n; j++)
        maps[m][j] = 0;
    int rowx = m - 1, rowy = n - 1;
    maps[m][n-1] = 1;
    while(true){
        for(int i = rowx; i>= 0; i--)
            maps[i][rowy] = maps[i+1][rowy] + maps[i][rowy+1];
        for(int j = rowy; j>= 0; j--){
            maps[rowx][j] = maps[rowx][j+1] + maps[rowx+1][j];
        }
        if(rowx == 0 || rowy == 0)
            break;
        rowx--;
        rowy--;
    }
    return maps[0][0];
}int main(int argc, const char * argv[]) {
    cout << uniquePaths(1, 2);
}
