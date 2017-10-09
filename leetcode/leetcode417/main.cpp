#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<pair<int, int>> res;
    vector<vector<int>> visit;
    void dfs(vector<vector<int>>& matrix, int x, int y, int pre, int preval){
        if(x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() || matrix[x][y] < pre ||
                preval & visit[x][y] == preval)
            return ;
        visit[x][y] |= preval;
        if(visit[x][y] == 3)
            res.push_back(make_pair(x, y));
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        for(int i =0; i < 4; i++){
            dfs(matrix,x + dx[i], y + dy[i], matrix[x][y], visit[x][y]);
        }
    }
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return res;
        int m = matrix.size();
        int n = matrix[0].size();
        visit.resize(m,vector<int>(n, 0 ));
        for(int i =0 ; i <m; i++){
            dfs(matrix,i,0,INT32_MIN,1 );
            dfs(matrix,i, n - 1,INT32_MIN,2 );
        }
        for(int i =0 ; i <n; i++){
            dfs(matrix,0,i,INT32_MIN,1 );
            dfs(matrix,m - 1, i,INT32_MIN,2 );
        }
        return res;
    };
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}