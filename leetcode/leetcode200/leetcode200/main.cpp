//
//  main.cpp
//  leetcode200
//
//  Created by 萧天牧 on 17/7/18.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void search(vector<vector<char>>& grid, vector<vector <int> >& ivec, int x, int y){
    if( 0 <= x && x < grid.size() && y < grid[0].size() && 0 <= y && grid[x][y] == '1'&& ivec[x][y] == 0 ){
        ivec[x][y] = 1;
        search(grid, ivec, x - 1, y);
        search(grid, ivec, x + 1, y);
        search(grid, ivec, x , y - 1);
        search(grid, ivec, x , y + 1);
    }
    return ;
}
int numIslands(vector<vector<char>>& grid) {
    if(grid.empty())
        return 0;
    vector<vector <int> > ivec(grid.size() ,vector<int>(grid[0].size(),0));
    int res = 0;
    for(int i = 0; i < grid.size(); i++){
        for (int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == '1' && ivec[i][j] == 0){
                search(grid, ivec, i , j);
                res++;
            }
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<vector<char>> a = {{'0', '1', '0'}, {'1', '0', '1'}};
    numIslands(a);
    std::cout << "Hello, World!\n";
    return 0;
}
