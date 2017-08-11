//
//  main.cpp
//  leetcode073
//
//  Created by 萧天牧 on 17/5/6.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void setZeroes(vector<vector<int>>& matrix) {
    bool colZero = false, rowZero = false;
    for(int i = 0; i < matrix[0].size(); i++)
        if(matrix[0][i] == 0){
            rowZero = true;
            break;
        }
    for(int j = 0; j < matrix.size(); j++)
        if(matrix[j][0] == 0){
            colZero = true;
            break;
        }
    for(int i = 1; i < matrix[0].size(); i++)
        for(int j = 1; j < matrix.size(); j++)
            if(matrix[j][i] == 0){
                matrix[0][i] = 0;
                matrix[j][0] = 0;
            }
    for(int i = 1; i < matrix[0].size(); i++){
        if(matrix[0][i] == 0){
            for(int j = 1; j < matrix.size(); j++){
                matrix[j][i] = 0;
            }
        }
    }
    for(int j = 1; j < matrix.size(); j++){
        if(matrix[j][0] == 0){
            for(int i = 1; i < matrix[0].size(); i++){
                matrix[j][i] = 0;
            }
        }
    }
    if (colZero)
        for(int j = 0; j < matrix.size(); j++)
            matrix[j][0] = 0;
    if (rowZero)
        for(int i = 0; i < matrix[0].size(); i++)
            matrix[0][i] = 0;
    return;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
