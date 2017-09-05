//
//  main.cpp
//  leetcode413
//
//  Created by 萧天牧 on 17/8/16.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int getRes(vector<int>A, int nowpos, int diff){
    int res = 0;
    while (nowpos < A.size() - 1) {
        if(A[nowpos] - A[nowpos + 1] == diff){
            res += 1;
            nowpos++;
        }
        else
            break;
            
    }
    return res;
}
int numberOfArithmeticSlices(vector<int>& A) {
    if(A.size() <= 2)
        return 0;
    int res = 0;
    for(int i = 0; i < A.size() - 2; i++){
        if(A[i] - A[i + 1] == A[i + 1] - A[i + 2]){
            res += getRes(A, i + 1, A[i] - A[i + 1] );
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> A = {1,2,3,4};
    cout << numberOfArithmeticSlices(A)<<endl;;
    std::cout << "Hello, World!\n";
    return 0;
}
