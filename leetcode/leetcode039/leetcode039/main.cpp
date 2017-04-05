//
//  main.cpp
//  leetcode039
//
//  Created by 萧天牧 on 17/3/2.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


void dfs(int lastnum, vector<int> candidate, vector<vector<int >>& result, vector<int> nowSelect, int nowPos){
    vector<int> newSelect = nowSelect;
    if (lastnum == 0){
        result.push_back(nowSelect);
        return;
    }
    for(int i = nowPos; i < candidate.size(); i++){
        if (candidate[i] > lastnum)
            return;
        vector<int> newSelect = nowSelect;
        newSelect.push_back(candidate[i]);
        dfs(lastnum - candidate[i], candidate, result, newSelect, i);
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int >> result;
    vector<int> nowSelect;
    sort(candidates.begin(), candidates.end());
    dfs(target, candidates, result, nowSelect, 0);
    return  result;
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
    vector<int> candidates = {2, 3, 6, 7};
    printRes(combinationSum(candidates, 7));
    return 0;
}
