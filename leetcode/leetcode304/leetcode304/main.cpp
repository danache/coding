//
//  main.cpp
//  leetcode304
//
//  Created by 萧天牧 on 17/8/7.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class NumMatrix {
public:
    vector<vector<int>> vec;
    bool flag = false;
    NumMatrix(vector<vector<int>> matrix) {
        if(matrix.empty() || matrix[0].empty())
            flag = true;
        else{
            vec = vector<vector<int>> (matrix.size() + 1 ,vector<int>(matrix[0].size() + 1,0));
            for(int i = 1; i <= matrix.size(); i++)
                for(int j = 1; j <= matrix[0].size(); j++)
                    update(i, j, matrix[i - 1][j - 1]);
        }
    }
    int getLowBit(int k){
        return k & -k;
    }
    void update(int x, int y, int num){
        for(int i = x; i < vec.size(); i += getLowBit(i))
            for(int j = y; j < vec[0].size(); j += getLowBit(j))
                vec[i][j] += num;
    }
    int getnum(int x, int y){
        int res = 0;
        for(int i = x; i > 0; i -= getLowBit(i)){
            for(int j = y; j > 0; j -= getLowBit(j)){
                res += vec[i][j];
            }
        }
        return res;
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(flag)
            return 0;
        
        row1 += 1;
        row2 += 1;
        col1 += 1;
        col2 += 1;
        int v1 = getnum(row1 - 1, col1 - 1);
        int v2 = getnum(row1 - 1, col2);
        int v3 = getnum(row2 , col1 - 1);
        int v4 = getnum(row2, col2);
        return v4 + v1 - v2 -v3;
        
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    //vector<vector<int>> a ={{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}};
    vector<vector<int>> a ={{1,2,3},{4,5,6},{7,8,9}};
    
    NumMatrix *obj = new NumMatrix(a);
    //cout << obj -> sumRegion(0, 0, 1, 1) << endl;
    cout << obj -> sumRegion(1, 1, 2, 2) << endl;
    //cout << obj -> sumRegion(1, 2, 2, 3) << endl;
    
    
    //[[],[2,1,4,3],[1,1,2,2],[1,2,2,4]]
    std::cout << "Hello, World!\n";
    return 0;
}
