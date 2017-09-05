//
//  main.cpp
//  leetcode423
//
//  Created by 萧天牧 on 17/8/17.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
string originalDigits(string s) {
    vector<int> p(26,0);
    vector<int> res(10,0);
    for(auto c : s){
        p[c - 'a']++;
    }
    res[0] = p['z' - 'a'];
    res[2] = p['w' - 'a'];
    res[4] = p['u' - 'a'];
    res[6] = p['x' - 'a'];
    res[8] = p['g' - 'a'];
    
    res[5] = p['f' - 'a'] - res[4];
    
    res[3] = p['h' - 'a'] -  res[8];
    
    res[7] = p['s' - 'a'] - res[6];
    res[1] = p['o' - 'a'] - res[2] - res[4] -res[0];
    res[9] = p['i' - 'a'] - res[5] - res[6] - res[8];
    string str = "";
    for(int i = 0; i < res.size(); i++){
        if(res[i] > 0){
            for(int j = 0; j < res[i]; j++){
                str += to_string(i);
            }
        }
    }
    return str;
}/*
  0 	numbers[0] = ‘z’的个数
  2 	numbers[2] = ‘w’的个数
  4 	numbers[4] = ‘u’的个数
  6 	numbers[6] = ‘x’的个数
  8 	numbers[8] = ‘g’的个数
  5 	numbers[5] = ‘f’的个数 - numbers[4]
  3 	numbers[3] = ‘h’的个数 - numbers[8]
  7 	numbers[7] = ‘s’的个数 - numbers[6]
  1 	numbers[1] = ‘o’的个数 - numbers[0] - numbers[2] - numbers[4]
  9 	numbers[9] = ‘i’的个数 - numbers[5] - numbers[6] - numbers[8]
  */
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << originalDigits("owoztneoer")<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
