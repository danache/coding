//
//  main.cpp
//  leetcode046
//
//  Created by 萧天牧 on 17/3/6.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
/*
    首先找到第一个a[i] < a[i + 1]
    找i后第一个比a[i]大的数字a[j]的j
    swap(a[i],a[j])
    reverse(a[i+1],end())
 
 
 */
void gets(vector<int> a,vector<vector<int>>& res){
    int i = 0;
    for(i = a.size() - 2;i >= 0; i--){
        if(a[i] < a[i + 1])
            break;
    }
    if(i == -1)
        return;
    int jj = 0;
    int minover = 9999;
    for(int j = i + 1; j < a.size(); j++){
        if(a[j] > a[i]){
            if (a[j] - a[i] < minover){
                minover = a[j] - a[i];
                jj = j;
            }
                
        }
    }
    swap(a[i], a[jj]);
    reverse(a.begin() + i + 1,a.end());
    res.push_back(a);
    gets(a,res);
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<int> bk = nums;
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    res.push_back(nums);
    gets(nums,res);
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1,2,3};
    permute(a);
    std::cout << "Hello, World!\n";
    return 0;
}
