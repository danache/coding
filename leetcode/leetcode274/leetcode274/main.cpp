//
//  main.cpp
//  leetcode274
//
//  Created by 萧天牧 on 17/6/29.
//  Copyright © 2017年 萧天牧. All rights reserved.
//
//直到某篇论文的序号大于该论文被引次数，那个序号减去1就是h指数
#include <iostream>
#include <vector>
using namespace std;
//[3, 0, 6, 1, 5] 3
//[0, 1, 3 ,5, 6] 3
bool myfunction (int i,int j) { return (i>j); }
int hIndex(vector<int>& citations) {
    if(citations.size() == 0 || (citations.size() == 0 && citations[0] == 0))
        return 0;
    int res = 0;
    int beyong_zero = 0;
    sort(citations.begin(), citations.end(), myfunction);
    
    for(int i = 0; i <citations.size() ;i++){
        if(citations[i] < i + 1 ){
            res = i;
            break;
        }
        if(citations[i] > 0)
            beyong_zero++;
    }
    if(res == 0)
        return beyong_zero;
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {100};
    std::cout << hIndex(a);
    return 0;
}
