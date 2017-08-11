//
//  main.cpp
//  leetcode229
//
//  Created by 萧天牧 on 17/8/2.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> majorityElement(vector<int>& nums) {
    vector<int> res;
    if(nums.empty())
        return res;
    int num1 = -999,num2 = -999;
    int count1 = 0, count2 = 0;
    for(auto n : nums){
        if(n == num1){
            count1++;
        }
        else if(n == num2){
            count2++;
        }
        else if(count1 == 0){
            num1 = n;
            count1++;
        }
        else if(count2 == 0){
            num2 = n;
            count2++;
        }
        
        else{
            count1--;
            count2--;
            
        }
        
    }
    count1 = 0;
    count2 = 0;
    for(auto n : nums){
        if(n == num1)
            count1++;
        else if (n == num2)
            count2++;
    }
    if(count1 > int(num.size() / 3) )
        res.push_back(num1);
    if(count2  > int(num.size() / 3 ))
        res.push_back(num2);
    return res;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {2,2,3,4};
    majorityElement(a);
    std::cout << "Hello, World!\n";
    return 0;
}
