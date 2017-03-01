//
//  main.cpp
//  leetcode017
//
//  Created by 萧天牧 on 17/2/26.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

void dfs(string digits, vector<string> num, string out, vector<string> &result){
    if (digits.size() == 0){
        result.push_back(out);
        return;
    }
    int value = digits[0] - '0';
    digits = digits.substr(1);
    for(int i = 0; i < num[value].size(); i++){
        dfs(digits, num, out+num[value][i], result);
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> result;
    if(digits.size() == 0)
        return result;
    vector<string> num = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string out = "";
    dfs(digits, num, out, result);
    return result;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string a;
    string b = "abc";
    a= b[0] + "";
    std::cout << a << endl;
    cin >> a;
    return 0;
}
