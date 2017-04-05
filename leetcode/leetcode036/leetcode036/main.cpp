//
//  main.cpp
//  leetcode036
//
//  Created by 萧天牧 on 17/3/2.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int row[9], col[9], sqr[3][3];
bool check(int x, int y, int val) {
    return !((row[x]>>val)&1) && !((col[y]>>val)&1) && !((sqr[x/3][y/3]>>val)&1);
}
void mark(int x, int y, int val) {
    row[x] |= (1<<val);
    col[y] |= (1<<val);
    sqr[x/3][y/3] |= (1<<val);
}
bool isValidSudoku(vector<vector<char> > &board) {
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(sqr, 0, sizeof(sqr));
    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[i].size(); j++)
            if (board[i][j] != '.') {
                if (!check(i, j, board[i][j] - '1'))
                    return false;
                mark(i, j, board[i][j] - '1');
            }
    return true;
    // return dfs(0, board);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
