//
//  main.cpp
//  leetcode011
//
//  Created by 萧天牧 on 17/2/23.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int area = 0;
    int left = 0;
    int right = height.size() - 1;
    while(left < right){
        area = max(area, (right - left) * (min(height[left], height[right])));
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return area;
    
}
int main(int argc, const char * argv[]) {
    vector<int> a = {1, 1};
    cout << maxArea(a);
}
