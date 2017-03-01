//
//  main.cpp
//  leetcode034
//
//  Created by 萧天牧 on 17/2/28.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res = {-1, -1};
    int left = 0, right = nums.size() - 1;
    if (nums.size() == 0)
        return res;
    while(left < right){
        int mid = (left + right) >> 1;
        if (nums[mid] < target){
            left = mid + 1;
        }
        else if (nums[mid] > target)
            right = mid - 1;
        else//nums[mid] == target时,证明最左边匹配的在[left,mid]中，将right置为mid.
            right = mid;
        
    }
    if (nums[left] != target)
        return res;
    res[0] = left;
    left = 0, right = nums.size() - 1;
    while(left < right){
        int mid = ((left + right) >> 1) + 1;
        if (nums[mid] <  target)
            left = mid + 1;
        else if (nums[mid] >  target)
            right = mid - 1;
        else //nums[mid] == target时，证明最右值在[mid,right]中，将left置为mid
            left = mid;
        //当把mid置为(left + right) / 2 + 1时，整体向右偏。
    }
    res[1] = right;
    return res;
}
void printRes(vector<int> res){
    for (int i = 0; i < res.size() ; i++)
        cout << res[i] << endl;
}
int main(int argc, const char * argv[]) {
    vector<int> a = {1,1,2,3,4,5,5,5,6};
    printRes(searchRange(a, 5));
    return 0;
}
