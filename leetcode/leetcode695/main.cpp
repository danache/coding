#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<int>>& grid, int x, int y, int& nowsize, int& maxsize){
    if(x < 0 || x == grid.size() || y <0 || y == grid[0].size()|| grid[x][y] == 0)
        return;
    nowsize += 1;
    maxsize = max(nowsize, maxsize);
    grid[x][y] = 0;
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    for(int i = 0; i < 4; i++){
        dfs(grid, x + dx[i], y + dy[i], nowsize,maxsize);
    }
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
    if(grid.empty() || grid[0].empty())
        return 0;
    int maxsize = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            int tmpsize = 0;
            dfs(grid,i,j,tmpsize,maxsize);
        }
    }
    return maxsize;
}
int main() {
    vector<vector<int>> a = {{0,0,0,0,0,0,0,0}};
    cout << maxAreaOfIsland(a)<<endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}