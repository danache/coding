#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <vector>
using namespace std;
/** 请完成下面这个函数，实现题目要求的功能 **/
/** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/

int dx[] = {-1,0,1,-1,1,-1,0,1};
int dy[] = {-1,-1,-1,0,0,1,1,1};

void dfs(vector<vector<int>> vec, vector<vector<int>>& flags, int nowx, int nowy, int tag, vector<int>& res){
    if(nowx < 0 || nowx >= vec.size() || nowy < 0 || nowy >= vec[0].size()
       || flags[nowx][nowy] != 0 || vec[nowx][nowy] == 0)
        return;
    flags[nowx][nowy] = tag;

    int nowmin = res[0];
    int nowmax = res[1];
    int nowval = vec[nowx][nowy];
    if (nowval < nowmin)
        res[0] = nowval;
    if (nowval > nowmax)
        res[1] = nowval;
    for(int i = 0; i < 8; i++){
        dfs(vec,flags, nowx + dx[i], nowy + dy[i], tag, res);
    }
    return;
}

vector<vector<int>> getMilitaryStrength(vector<vector<int>> vec) {
    int m = vec.size();
    int n = vec[0].size();
    vector<vector<int>> map(m,vector<int>(n,0));
    int tag = 1;
    vector<vector<int>> res;
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j++){
            if (vec[i][j] != 0 && map[i][j] == 0){
                vector<int> tmp = {INT32_MAX, INT32_MIN};
                dfs(vec, map, i, j , tag,tmp);
                res.push_back(tmp);
                tag++;
            }
        }
    }
    return res;
}

int main() {
    int res_size;


    int _A_rows = 0;
    int _A_cols = 0;
    scanf("%d", &_A_rows);
    scanf("%d", &_A_cols);

    vector<vector<int>> vec(_A_rows,vector<int>(_A_cols,0));


    int _A_i, _A_j;
    for(_A_i = 0; _A_i < _A_rows; _A_i++) {
        for(_A_j = 0; _A_j < _A_cols; _A_j++) {
            int _A_item;
            scanf("%d", &_A_item);

            vec[_A_i][_A_j] = _A_item;
        }
    }

    vector<vector<int>>  res = getMilitaryStrength(vec);


    return 0;

}