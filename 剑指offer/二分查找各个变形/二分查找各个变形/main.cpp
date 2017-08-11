//
//  main.cpp
//  二分查找各个变形
//
//  Created by 萧天牧 on 17/5/9.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
//最普通二分查找
int bs1(vector<int> a, int target){
    if(a.size() == 0)
        return -1;
    int left = 0, right = a.size() - 1;
    while(left <= right){
        int mid = left + ((right - left) >> 1);
        if(a[mid] == target)
            return mid;
        else if (a[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

//查找第一个与key相等的元素
int bs2(vector<int> a, int target){
    if(a.size() == 0)
        return -1;
    int left = 0, right = a.size() - 1;
    while(left <= right){
        int mid = left + ((right - left) >> 1);
        if(a[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    if(left<a.size() && a[left] == target)
        return left;
    else
        return -1;
}

//查找最后一个与key相等的元素
int bs3(vector<int> a, int target){
    if(a.size() == 0)
        return -1;
    int left = 0, right = a.size() - 1;
    while(left <= right){
        int mid = left + ((right - left + 1) >> 1);
        if(a[mid] <= target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    if(0<=right && a[right] == target)
        return right;
    else
        return -1;
}
//查找最后一个等于或者小于key的元素
int bs4(vector<int> a, int target){
    if(a.size() == 0)
        return -1;
    int left = 0, right = a.size() - 1;
    while(left <= right){
        int mid = left + ((right - left + 1) >> 1);
        if(a[mid] <= target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right;
}
//查找最后一个小于key的元素
int bs5(vector<int> a, int target){
    if(a.size() == 0)
        return -1;
    int left = 0, right = a.size() - 1;
    while(left <= right){
        int mid = left + ((right - left) >> 1);
        if(a[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right;
}
//查找第一个等于或者大于key的元素
int bs6(vector<int> a, int target){
    if(a.size() == 0)
        return -1;
    int left = 0, right = a.size() - 1;
    while(left <= right){
        int mid = left + ((right - left) >> 1);
        if(a[mid] < target)
            left = mid + 1;
        else
            right = mid -1;
    }
    return left;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {0,1,1,2,2,2,4};
    cout << bs6(a,2);
    return 0;
}
