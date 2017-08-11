//
//  main.cpp
//  leetcode303
//
//  Created by 萧天牧 on 17/8/7.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class NumArray {
public:
    vector<int> vec;
    NumArray(vector<int> nums) {
        vec = vector<int>(nums.size() * 4,0);
        for(int i = 1; i <= nums.size(); i++){
            update(i, nums[i - 1]);
        }
    }
    int getLowBit(int k){
        return k &-k;
    }
    int read(int n){
        int sum = 0;
        while(n){
            sum += vec[n];
            n -= getLowBit(n);
        }
        return sum;
    }
    void update(int pos, int value){
        while(pos <= vec.size()){
            vec[pos] += value;
            pos += getLowBit(pos);
        }
    }
    int sumRange(int i, int j) {
        return read(j+1) - read(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray *obj = new NumArray(nums);
    cout << obj->sumRange(0,5);
    std::cout << "Hello, World!\n";
    return 0;
}
