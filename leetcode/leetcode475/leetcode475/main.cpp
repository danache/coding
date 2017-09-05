//
//  main.cpp
//  leetcode475
//
//  Created by 萧天牧 on 17/8/24.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    int maxV = INT_MIN;
    int j = 0;
    for(int i = 0; i < houses.size() ; i++){
        while(j < heaters.size() - 1 && abs(heaters[j] - houses[i]) >=
              abs(heaters[j + 1] - houses[i]))
            j++;
        maxV = max(maxV, abs(heaters[j] - houses[i]));
            
    }
    return maxV;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
