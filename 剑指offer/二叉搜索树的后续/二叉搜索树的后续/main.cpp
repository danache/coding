//
//  main.cpp
//  二叉搜索树的后续
//
//  Created by 萧天牧 on 17/5/15.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
bool judge(const vector<int> sequence ,int start,int end){
    if(start >= end)
        return true;
    int root = sequence[end];
    int i = start;
    for(i; i <end; i++){
        int tmp=sequence[i];
        if(tmp == root)
            return false;
        if(tmp > root)
            break;
    }
    i--;
    int j = i + 1;
    for(j;j <end; j++){
        if(sequence[j] < root)
            return false;
    }
    bool flag = judge(sequence, start, i) && judge(sequence, i + 1, end - 1);
    return flag;
    
}
bool VerifySquenceOfBST(vector<int> sequence) {
    if(sequence.empty())
        return true;
    
    return judge(sequence, 0, sequence.size() - 1);
}
int main(int argc, const char * argv[]) {
    vector<int> a = {5,7,6,9,11,10,8};
    vector<int> b = {7,4,6,5};
    
    cout <<VerifySquenceOfBST(b)<<" ";
    return 0;
}
