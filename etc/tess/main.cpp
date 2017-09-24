#include <iostream>
#include <map>
#include <queue>
using namespace std;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void getmaxblack(vector<vector<int>> map,vector<vector<bool>>& flag, int& maxlen, int i, int j , int len, int lastdirection){
    if(flag[i][j])
        return;
    if(map[i][j] != 1){
        flag[i][j] = true;
        return ;
    }
    flag[i][j] = true;
    if(map[i][j] == 1){
        len += 1;
        if(lastdirection != -1){
            int next_i = i + dx[lastdirection];
            int next_j = j + dx[lastdirection];
            if(0 <=next_i && 0 <=next_j && next_i < map.size() && next_j< map.size()
               && !flag[next_i][next_i] ){
                if(map[next_i][next_j] == 2){
                    flag[next_i][next_j] = true;
                    len -= 1;
                    maxlen = max(maxlen, len);
                }
                else if (map[next_i][next_j] == 1){
                    getmaxblack(map,flag,
                             maxlen, next_i, next_j , len, lastdirection);
                }
            }

        }else{
            for(int k = 0; i < 4; i++){
                int next_i = i + dx[k];
                int next_j = j + dx[k];
                if(0 <=next_i && 0 <=next_j && next_i < map.size() && next_j< map.size()
                   && !flag[next_i][next_i] && map[next_i][next_j] == 1){
                    getmaxblack(map,flag,
                                maxlen, next_i, next_j , len, k);
                }
            }
        }

    }
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> map(n,vector<int>(n,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }
    vector<
}
