//
//  main.cpp
//  leetcode278
//
//  Created by 萧天牧 on 17/8/2.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
bool isBadVersion(int version);
int firstBadVersion(int n) {
    int left = 1, right = n ;
    while(left < right){
        int mid = left + ((right - left) >> 1);
        if(isBadVersion(mid)){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return right;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> a = {1};
    //cout << BST(a)<<endl;
    return 0;
}
