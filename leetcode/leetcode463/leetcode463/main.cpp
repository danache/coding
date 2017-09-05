//
//  main.cpp
//  leetcode463
//
//  Created by 萧天牧 on 17/8/22.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int mapx[] = {1, -1, 0, 0};
int mapy[] = {0, 0, 1, -1};
bool isvalid(vector<vector<int>>& grid,vector<vector<bool>> flag,int x, int y){
    if(x < 0 || x == grid.size() || y < 0 || y == grid[0].size() ||
       flag[x][y] == true || grid[x][y] == 0)
        return false;
    return true;
    
}
int dfs(vector<vector<int>>& grid,vector<vector<bool>>& flag,int x, int y){
    if(isvalid(grid, flag,x, y))
        flag[x][y] = true;
    int num = 0;
    for(int i = 0; i < 4; i++){
        int dx = x + mapx[i];
        int dy = y + mapy[i];
        if(isvalid(grid, flag, dx, dy)){
            num++;
            num += dfs(grid, flag, dx, dy);
        }
        
    }
    return num;
}
int islandPerimeter(vector<vector<int>>& grid) {
    if(grid.empty() || grid[0].empty())
        return 0;
    vector<vector<bool>> flag(grid.size(),vector<bool>(grid[0].size(),false));
    
    int vai = 0, vaj = 0;
    bool fffflag = false;
    int initx = -1, inity = -1;
    int count = 0;
    for(vai = 0; vai < grid.size(); vai++){
        for(vaj = 0; vaj < grid[0].size(); vaj++){
            if(grid[vai][vaj] == 1){
                count++;
                
                if(!fffflag){
                    initx = vai;
                    inity = vaj;
                    fffflag = true;
                }
            }
            
        }
    }

//flag[0][0] = true;
    
int res = dfs(grid, flag, initx,inity);

return 4*count - 2*  res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> grid = {{1,1},
        {1,1},
        
    };
    std::cout << islandPerimeter(grid);
    return 0;
}
