//
//  main.cpp
//  leetcode223
//
//  Created by 萧天牧 on 17/7/4.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int left = max(E , A);
    int right = max(min(D, H), left);
    int bottom = max(B, F);
    int top = max(bottom, min(D, H));
    return (C - A) * (D - B) + (G - E) * (H - F) - (right -left) * -(bottom - top);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
