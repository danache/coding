//
//  main.cpp
//  leetcode073
//
//  Created by 萧天牧 on 17/5/8.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.size() == 0)
        return false;
    if(matrix[0].size() == 0)
        return false;
    int up = 0, down = matrix.size() - 1;
    while(up <= down){
        int mid = up + ((down - up) >> 1 );
        if (matrix[mid][0] <= target){
            up = mid + 1;
        }
        else{
            down = mid - 1;
        }
    }
    int left = 0, right = matrix[down].size() - 1;
    if(down == -1)
        down = 0;
    while(left <= right){
        int mid = left + ((right - left) >> 1);
        if(matrix[down][mid] == target)
            return true;
        else if (matrix[down][mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> a = {{1,1}};
    vector<int> b = {1,3};
    cout << searchMatrix(a, 0) <<endl;

    std::cout << "Hello, World!\n";
    return 0;
}
