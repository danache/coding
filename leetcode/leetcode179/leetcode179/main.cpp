//
//  main.cpp
//  leetcode179
//
//  Created by 萧天牧 on 17/7/31.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
static bool myop(int a, int b)
{
    stringstream s1,s2;
    s1 << a;
    s2 << b;
    string sa = s1.str();
    string sb = s2.str();
    
    string c1 = sa + sb;
    string c2 = sb + sa;
    return c1 > c2;
}
string largestNumber(vector<int>& nums) {
    
    vector<string> tmp;
    if(nums.empty())
        return "0";
    string res = "";
    
    sort(nums.begin(),nums.end(),myop);
    bool flag = true;
    for(auto n : nums){
        if (n == 0 && flag){
            continue;
        }
        else{
            flag = false;
            stringstream s1;
            s1 << n;
            string sa = s1.str();
            res += sa;
        }
    }
    return res.size() == 0 ? "0" : res;
    
}
int main(int argc, const char * argv[]) {
    vector<int> a = {1};
    cout <<largestNumber(a)<<endl;
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
