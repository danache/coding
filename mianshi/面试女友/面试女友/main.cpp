//
//  main.cpp
//  面试女友
//
//  Created by 萧天牧 on 17/4/26.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;
typedef pair<int,int> P;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool isLine(int nowx, int nowy,const vector<int>& tx, const vector<int>& ty, const vector<int>& wx, const vector<int>& wy){
    for(int i = 0; i < tx.size(); i++){
        //(y-y1)/(x-x1)=(y2-y1)/(x2-x1)·
        int x1 = tx[i];
        int y1 = ty[i];
        int x2 = wx[i];
        int y2 = wy[i];
        if(x2 == x1)
            continue;
        if(nowy == (y2-y1)/((x2-x1) * 1.0) * (nowx-x1)+y1)
            return true;
    }
    return false;
}
bool Find(int m, int n, const vector<int>& tx, const vector<int>& ty, const vector<int>& wx, const vector<int>& wy)
{
    char maze[m][n];
    int sx = 0, sy = 0;
    int gx = m, gy = n;
    queue<P> que;
    memset(maze, false, sizeof(maze));
    que.push(P(sx, sy));
    while(!que.empty()){
        P p = que.front();
        que.pop();
        if(p.first == gx && p.second == gy)
            return true;
        for(int i= 0; i < 4; i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(0 <= nx && nx < m && 0 <= ny && ny <n &&!maze[nx][ny] && !isLine(nx, ny,tx,ty, wx, wy)){
                que.push(P(nx,ny));
                maze[nx][ny] = true;
            }
        }
    }
return false;
}

int main()
{
    int m = 0;
    int n = 0;
    vector<int> tx;
    vector<int> ty;
    vector<int> wx;
    vector<int> wy;
    int num = 0;
    cin>>m;
    cin>>n;
    cin>>num;
    for (int i = 0; i < num; ++i) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        tx.push_back(x1);
        ty.push_back(y1);
        wx.push_back(x2);
        wy.push_back(y2);
    }
    cout << Find(m,n,tx,ty,wx,wy) << endl;
    return 0;
}
