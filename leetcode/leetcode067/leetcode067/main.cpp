//
//  main.cpp
//  leetcode067
//
//  Created by 萧天牧 on 17/7/3.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
string addBinary(string a, string b) {
    string res;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int i = 0, j = 0;
    int jinwei = 0;
    while(i < a.size() && j < b.size()){
        int tmp = (a[i] - '0' + b[j] - '0' + jinwei) % 2;
        jinwei =(a[i] - '0' + b[j] - '0' + jinwei) / 2;
        res.push_back(tmp + '0');
        i++;
        j++;
    }
    if(i == a.size()){
        while(j < b.size()){
            int tmp = (b[j] - '0' + jinwei) % 2;
            jinwei =(b[j] - '0' + jinwei) / 2;
            res.push_back(tmp + '0');
            j++;
        }
    }
    else if(j == b.size()){
        while(i < a.size()){
            int tmp = (a[i] - '0' + jinwei) % 2;
            jinwei =(a[i] - '0' + jinwei) / 2;
            res.push_back(tmp + '0');
            i++;
        }
    }
    if(jinwei)
        res.push_back(jinwei+'0');
    reverse(res.begin(), res.end());
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << addBinary("11", "1");
    return 0;
}
