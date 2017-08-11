//
//  main.cpp
//  leetcode228
//
//  Created by 萧天牧 on 17/8/1.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    if(nums.empty())
        return res;
    int begin =0;
    int end = 0;
    int lastnum = -1;
    for(int i = 0; i < nums.size(); i++){
        if(i == 0){
            begin = 0;
            lastnum = nums[i];
        }
        else{
            if (nums[i] - lastnum != 1){
                end = i - 1;
                string tmp;
                if(begin == end){
                    sprintf(tmp, "%d", begin)
                }
                else{
                    sprintf(tmp,"%d->%d" ,(begin,end));
                }
                res.push_back(tmp);
                
            }
        }
    }
    return res;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
