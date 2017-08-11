//
//  main.cpp
//  leetcode119
//
//  Created by 萧天牧 on 17/5/10.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> A(rowIndex+1, 0);
    A[0] = 1;
    for(int i=1; i<rowIndex+1; i++)
        for(int j=i; j>=1; j--)
            A[j] += A[j-1];
    return A;
}int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
