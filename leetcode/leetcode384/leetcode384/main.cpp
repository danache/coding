//
//  main.cpp
//  leetcode384
//
//  Created by 萧天牧 on 17/8/11.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> ori, shuf;
    Solution(vector<int> nums) {
        ori = nums;
        shuf = ori;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        shuf = ori;
        return shuf;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i = shuf.size() - 1; i >=0; i--){
            swap(shuf[i], shuf[rand() % (i + 1)]);
        }
        return shuf;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
