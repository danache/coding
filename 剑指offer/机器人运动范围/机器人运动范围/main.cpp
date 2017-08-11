//
//  main.cpp
//  机器人运动范围
//
//  Created by 萧天牧 on 17/5/11.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int countnum(int x, int y){
    int res = 0;
    while(x > 0){
        res += x %10;
        x /= 10;
    }
    while(y > 0){
        res += y % 10;
        y /= 10;
    }
    return res;
    
}
void dfs(int threshold, int rows, int cols, int nowrows, int nowcols, int& count, bool *maze){
    bool b =countnum(nowrows, nowcols) <= threshold;
    if(nowcols < cols && 0 <= nowcols && nowrows < rows && 0 <= nowrows && !maze[nowrows * cols + nowcols] && (countnum(nowrows, nowcols) <= threshold)){
        count++;
        maze[nowrows * cols + nowcols] = true;
        dfs(threshold, rows, cols, nowrows + 1, nowcols, count, maze) ;
        dfs(threshold, rows, cols, nowrows - 1, nowcols, count, maze) ;
        dfs(threshold, rows, cols, nowrows, nowcols + 1, count, maze) ;
        dfs(threshold, rows, cols, nowrows, nowcols - 1, count, maze) ;
    }
}
int movingCount(int threshold, int rows, int cols)
{
    if(threshold <0 || rows < 0 || cols < 0)
        return 0;
    int count = 0;
    bool *maze = new bool[rows * cols];
    for(int i = 0; i < rows*cols; i++)
        maze[i] = false;
    dfs(threshold, rows, cols, 0, 0, count, maze);
    return count;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << countnum(2,1)<<endl;
    cout << movingCount(5,10,10);
    return 0;
}
