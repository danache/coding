//
//  main.cpp
//  前k小
//
//  Created by 萧天牧 on 17/5/16.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int  Partition(vector<int> &number, int low, int high){
    int a = number[low];
    int l = low, r = high;
    while(l < r){
        while (l < r && number[r] >= a)
            r--;
        if(l < r)
            number[l] = number[r];
        while (l < r && number[l] < a)
            l++;
        if(l < r)
            number[r] = number[l];
    }
    number[l] = a;
    return l;
}

//void quicksort(vector<int>& number, int low, int high){
//    if(low < high){
//        int a = Partition(number, low, high);
//        quicksort(number, low, a - 1);
//        quicksort(number, a + 1, high);
//
//    }
//}
//vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
//        vector<int> res;
//    if(k <= 0 || input.size() == 0 || k > input.size())
//        return input;
//    if(k == input.size())
//    return input;
//    int low = 0, high = input.size() - 1;
//    int index = Partition(input, low , high);
//    while(index != k - 1){
//        if(index > k - 1){
//            high = index - 1;
//            index = Partition(input, low, high);
//        }
//        else{
//            low = index + 1;
//            index = Partition(input, low, high);
//        }
//    }
//    for(int i = 0;  i < k; i++){
//        res.push_back(input[i]);
//    }
//    return res;
//}
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    vector<int> res;
    multiset<int> heap;
    if(k <= 0 || input.size() == 0 || k > input.size())
        return res;
    if(k == input.size())
        return input;
    for(int i = 0; i < input.size(); i++){
        if(heap.size() < k)
            heap.insert(input[i]);
        else{
            multiset<int>::iterator it = heap.end();
            it--;
            if(input[i] < *(it)){
                heap.erase(it);
                heap.insert(input[i]);
            }
        }
    }
    for(multiset<int>::iterator it = heap.begin(); it != heap.end(); it++)
        res.push_back(*it);
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> number = {4,5,1,6,2,7,3,8};
    vector<int> res = GetLeastNumbers_Solution(number, 4);
    for (int i = 0; i < 4; i++)
        cout <<res[i] <<" ";
}
