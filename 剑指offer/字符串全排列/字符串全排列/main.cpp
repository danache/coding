//
//  main.cpp
//  字符串全排列
//
//  Created by 萧天牧 on 17/5/16.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void genetate(string str, int pos, string nowselect, vector<string>& res){
    if(str[pos] == '\0'){
        res.push_back(nowselect);
        return;
    }
    else{
        for(int i = 0; i <= nowselect.size(); i++){
            string tmp = nowselect;
            tmp.insert (tmp.begin()+i,str[pos]);
            genetate(str, pos+1, tmp, res);
        }
    }
    
}
vector<string> Permutation(string str) {
    
    vector<string> res;
    if(str=="")
        return res;
    //为什么暴露比掩饰来得从容
    genetate(str,0,"",res);
    sort(res.begin(), res.end());
    vector<string>::iterator new_end = unique(res.begin(), res.end());//"删除"相邻的重复元素
    res.erase(new_end, res.end());//删除(真正的删除)重复的元素
    return res;
}
int main(int argc, const char * argv[]) {
    vector<string> a = Permutation("abc");
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << endl;
    return 0;
}
