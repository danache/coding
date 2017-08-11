//
//  main.cpp
//  旋转数组的最小数字
//
//  Created by 萧天牧 on 17/5/8.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int findline(vector<int> array, int begin, int end){
    int tmp = array[begin];
    for(int i = begin + 1; i < end; i++)
        if(array[i] != tmp)
            return array[i];
    return tmp;
}
int minNumberInRotateArray(vector<int> rotateArray) {
    if(rotateArray.size() == 0)
        return 0;
    int left = 0, right = rotateArray.size() - 1;
    int mid = left;
    if(rotateArray[left] < rotateArray[right])
        return rotateArray[left];
    while(left < right - 1){
        mid = ((right - left)>>1) + left;
        if(rotateArray[left] == rotateArray[mid] && rotateArray[mid] == rotateArray[right])
            return findline(rotateArray, left, right);
        else if(rotateArray[mid] >= rotateArray[left]){
            left = mid;
        }
        else if(rotateArray[mid] <= rotateArray[right])
            right = mid;
    }
    return rotateArray[right];
}
int main(int argc, const char * argv[]) {
    vector<int> a1 = {1,2,3,4,5};
    vector<int> a2 = {5,4,3,2,1};
    vector<int> a3 = {4,5,1,2,3};
    vector<int> a4 = {3,4,5,1,2};
    vector<int> a5 = {1,0,1,1,1};
    //cout << minNumberInRotateArray(a1) << endl;
    //cout << minNumberInRotateArray(a2) << endl;
    //cout << minNumberInRotateArray(a3) << endl;
    cout << minNumberInRotateArray(a4) << endl;
   // cout << minNumberInRotateArray(a5) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
