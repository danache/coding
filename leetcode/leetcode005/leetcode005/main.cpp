//
//  main.cpp
//  leetcode005
//
//  Created by 萧天牧 on 16/12/18.
//  Copyright © 2016年 萧天牧. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        string str = "$#";
        for (int i = 0; i < s.size(); i++){
            str += s[i];
            str += '#';
        }//处理数组
        int *p = new int[str.size() + 1];
        //构建辅助数组
        int max_len_pos = 0, max_middle_pos = 0;
        
        for (int i = 1; i <= str.size(); i++){
            if (i < max_len_pos){
                p[i] = min(p[2 * max_middle_pos - i], max_len_pos - i);
            }//如果当前的i值在最大边界里面，说明他要么和与其对称的j（2 * max_middle_pos - i）一样，要么小于它，因此去最小的，相当于起始数目增加了
            else
                p[i] = 1;//否则只能老老实实一个一个试验
            while(str[i - p[i]] == str[i + p[i]])
                p[i]++;
            if (p[i] + i > max_len_pos){
                max_len_pos = p[i] + i;
                max_middle_pos = i;
            }
        }
        int ii = 0;
        int max_num = 0;
        for (int i = 1; i < str.size(); i++){
            if (p[i] > max_num){
                ii = i;
                max_num = p[i];
            }
        }
        max_num--;
        int begin = ii - max_num;
        int end = ii + max_num;
        string result;
        for(int i = begin; i <= end; i++){
            if (str[i] != '#')
                result += str[i];
        }
        
        return result;
    }
};

int main(){
    Solution *sol = new Solution();
    cout << sol->longestPalindrome("abccba")<<endl;
    return 0;
}
