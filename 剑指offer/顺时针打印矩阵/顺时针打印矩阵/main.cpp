//
//  main.cpp
//  顺时针打印矩阵
//
//  Created by 萧天牧 on 17/5/15.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void printCircle(vector<vector<int> > matrix, int start, vector<int>& res){
    int endx = matrix[0].size() - 1 - start;
    int endy = matrix.size() - 1 - start;
    for(int i = start; i <= endx; i++){
        res.push_back(matrix[start][i]);
    }
    if(start < endy){
        for(int i = start + 1; i<= endy; i++){
            res.push_back(matrix[i][endx]);
        }
    }
    if(start < endx && start < endy){
        for(int i = endx - 1; i>= start; i--){
            res.push_back(matrix[endy][i]);
        }
    }
    if(start < endx && start < endy - 1){
        for(int i = endy - 1; i > start; i--){
            res.push_back(matrix[i][start]);
        }
    }
}
vector<int> printMatrix(vector<vector<int> > matrix) {
    vector<int> res;
    if(matrix.size() <= 0 || matrix[0].size() == 0)
        return res;
    int endx = matrix[0].size();
    int endy = matrix.size();
    int start = 0;
    while(start*2 < endx && start * 2 < endy){
        printCircle(matrix, start,  res);
        start++;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<vector<int>> a = {{1,2}, {3,4}};
    vector<int> res = printMatrix(a);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] <<" ";
    std::cout << "Hello, World!\n";
    return 0;
}
