//
//  main.cpp
//  leetcode040
//
//  Created by 萧天牧 on 17/3/2.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void Helper(vector<vector<int> > &ret, vector<int> cur, vector<int> &num, int target, int position)
{
    if(target == 0)
        ret.push_back(cur);
    else
    {
        for(int i = position; i < num.size() && num[i] <= target; i ++)
        {
            if(i != position && num[i] == num[i-1])
                continue;
            cur.push_back(num[i]);
            Helper(ret, cur, num, target-num[i], i+1);
            cur.pop_back();
        }
    }
}

vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    sort(num.begin(), num.end());
    vector<vector<int> > ret;
    vector<int> cur;
    Helper(ret, cur, num, target, 0);
    return ret;
}
void printRes(vector<vector<int>> res){
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            cout <<res[i][j] <<" ";
        }
        cout << endl;
    }
}
int main(int argc, const char * argv[]) {
    vector<int > a = {10,1,2,7,6,1,5};
    combinationSum2(a, 8);
    std::cout << "Hello, World!\n";
    return 0;
}
