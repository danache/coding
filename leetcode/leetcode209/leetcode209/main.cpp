//
//  main.cpp
//  leetcode209
//
//  Created by 萧天牧 on 17/6/2.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int minSubArrayLen(int s, vector<int>& nums) {
    int tmp[nums.size()][nums.size()];
    memset(tmp, 0, sizeof(tmp));
    int minLen = 99999;
    for(int i = 0; i < nums.size(); i++){
        tmp[i][i] = nums[i];
    }
    for(int i = 0; i < nums.size(); i++){
        for(int j = i + 1; j < nums.size(); j++){
            tmp[i][j] = tmp[i][j-1]+tmp[j][j];
            if(tmp[i][j] == s)
                if(j - i < minLen){
                    minLen = j - i;
                }
            else if(tmp[i][j] > s)
                break;
        }
    }
    return minLen == 99999 ? 0 : minLen;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
