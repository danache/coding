//
//  main.cpp
//  leetcode495
//
//  Created by 萧天牧 on 17/8/29.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    if(timeSeries.empty())
        return 0;
    int begin = 0,lastbegin = 0;
    int res = 0;
    for(int i = 0; i < timeSeries.size(); i++){
        if(i == 0){
            begin = lastbegin = timeSeries[i];
        }
        else{
            if(timeSeries[i] < lastbegin + duration)
                lastbegin = timeSeries[i];
            else{
                res += lastbegin + duration - begin;
                begin = lastbegin = timeSeries[i];
            }
        }
    }
    res += lastbegin + duration - begin;
    return res;
    
}
//[1,4], 2
//[1,2], 2
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1,2};
    cout << findPoisonedDuration(a, 2)<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
