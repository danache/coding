//
//  main.cpp
//  leetcode526
//
//  Created by 萧天牧 on 17/8/29.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void dfs(int pos, vector<bool> vec, int& res, int leftnum){
    if(pos == vec.size() && leftnum == 0){
        res++;
        return;
    }
    if(leftnum == 0)
        return;
    for(int i = 1 ; i < vec.size(); i++){
        if( vec[i] == false && ((i % pos == 0) || (pos % i == 0))){
            vec[i] = true;
            dfs(pos+1, vec, res,leftnum - 1);
            vec[i] = false;
        }
    }
}
int countArrangement(int N) {
    int res = 0;
    vector<bool> vec(N + 1,false);
    dfs(1,vec, res,N);
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << countArrangement(3)<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
