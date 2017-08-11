//
//  main.cpp
//  leetcode372
//
//  Created by 萧天牧 on 17/8/10.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void div(vector<int>& b){
    int res = 0;
    for(int i = 0; i < b.size(); i++){
        int tmp = res;
        res = b[i]  %2;
        b[i] = (b[i] +tmp * 10)/ 2;
    }
}

bool beyongzero(vector<int> b){
    for(auto n : b)
        if (n > 0)
            return true;
    return false;
}
int superPow(int a, vector<int>& b) {
    if (!beyongzero(b))
        return 1;
    
    a %= 1337;
    bool odd = false;
    if(b[b.size() - 1] % 2== 1)
        odd = true;
    div(b);
    int res = superPow(a, b);
    res %= 1337;
    res *=  res;
    res %= 1337;
    if(odd){
        res *= a;
        res %= 1337;
    }
    
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {6};
    std::cout << superPow(2, a);
    return 0;
}
