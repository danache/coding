//
//  main.cpp
//  leetcode054
//
//  Created by 萧天牧 on 17/4/25.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
enum{up,down,lef,rig};
vector<int> spiralOrder(vector<vector<int>>& matrix) {

    vector<int >result;
    int ylen = matrix.size();
    if(ylen == 0)
        return result;
    int xlen = matrix[0].size();
    int lastDir = rig;
    bool flag[matrix.size()][matrix.size()];
    memset(flag, false, sizeof(flag));
    int initx = 0, inity = 0;
    while(true){
        if(initx < 0 || initx == ylen || inity < 0 || inity == xlen||flag[initx][inity])
            break;
        result.push_back(matrix[initx][inity]);
        flag[initx][inity] = true;
        switch (lastDir) {
            case rig:
                if(inity + 1 == xlen || flag[initx][inity + 1]){
                    initx += 1;
                    lastDir = down;
                }
                else
                    inity += 1;
                break;
            case down:
                if(initx + 1 == ylen || flag[initx + 1][inity]){
                    inity -= 1;
                    lastDir = lef;
                }
                else
                    initx += 1;
                break;
            case lef:
                if(inity - 1 < 0 ||  flag[initx][inity - 1]){
                    initx -= 1;
                    lastDir = up;
                }
                else
                    inity -= 1;
                break;
            case up:
                if(initx - 1 < 0 ||  flag[initx - 1][inity]){
                    inity += 1;
                    lastDir = rig;
                }
                else
                    initx -= 1;
                break;
            default:
                break;
        }
        
    }
    return result;
}
int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix = {{2,3}};
    vector<int> res =spiralOrder(matrix);
    for(int i = 0; i < res.size(); i++)
        cout << res[i]<<" ";
    return 0;
}
