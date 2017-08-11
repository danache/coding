//
//  main.cpp
//  leetcode289
//
//  Created by 萧天牧 on 17/8/4.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int getStatus(vector<vector<int>>& board, int x, int y){
    int nowStatus = board[x][y];
    int live = 0;
    for(int i = x - 1; i <= x + 1; i++)
        for(int j = y - 1; j <= y + 1; j++){
            if(i < 0 || j < 0 || i == board.size() || j == board[0].size()
               || (i == x && j == y))
                continue;
            if(board[i][j] % 10)
                live++;
        }
    if(nowStatus == 0){
        if(live == 3)
            return 10;
    }
    else{
        if (live == 2 || live == 3)
            return 10;
        else
            return 0;
    }
    return 0;
    
}
void gameOfLife(vector<vector<int>>& board) {
    if(board.empty() || board[0].empty())
        return;
    for(int i = 0; i < board.size(); i++)
        for(int j = 0; j < board[0].size(); j++)
            board[i][j] += getStatus(board, i, j);
    for(int i = 0; i < board.size(); i++)
        for(int j = 0; j < board[0].size(); j++)
            board[i][j] /= 10;
    
    return;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>>a = {{1,1,},{1,0}};
    gameOfLife(a);
    std::cout << "Hello, World!\n";
    return 0;
}
