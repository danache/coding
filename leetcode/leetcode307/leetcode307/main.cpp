//
//  main.cpp
//  leetcode307
//
//  Created by 萧天牧 on 17/8/8.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
//class NumArray {
//    vector<int> vec;
//    vector<int> ori;
//public:
//    int getLowBit(int k){
//        return k & -k;
//    }
//    NumArray(vector<int> nums) {
//        vec = vector<int>(4*nums.size() + 1 ,0 );
//        ori = nums;
//        for(int i = 1; i <= nums.size(); i++ )
//            upone(i, nums[i - 1]);
//    }
//    
//    void update(int i, int val) {
//        int nowVal = ori[i];
//        ori[i] = val;
//        upone(i + 1,  val-nowVal);
//    }
//    
//    void upone(int i, int val){
//        while(i <= vec.size()){
//            vec[i] += val;
//            i += getLowBit(i);
//        }
//    }
//    int getres(int i){
//        int res = 0;
//        while(i){
//            res += vec[i];
//            i -= getLowBit(i);
//        }
//        return res;
//    }
//    int sumRange(int i, int j) {
//        return getres(j + 1) - getres(i);
//    }
//};

class NumArray {
    vector<int> vec;
public:

    NumArray(vector<int> nums) {

    }
    void update(int i, int val) {

    }

    int sumRange(int i, int j) {

    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1,3,5};
    NumArray obj = NumArray(a);
    //obj.update(i,val);
    cout <<obj.sumRange(0,2);
    obj.update(1, 2);
    cout <<obj.sumRange(0,2);
    std::cout << "Hello, World!\n";
    return 0;
}
