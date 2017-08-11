//
//  main.cpp
//  leetcode402
//
//  Created by 萧天牧 on 17/7/13.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//
//string removeKdigits(string num, int k) {
//    if(k > num.size())
//        return "";
//    if(k == num.size())
//        return "0";
//    
//    for(int step = 0; step < k; step++){
//        int firstpos = 0;
//        int secondpos = 1;
//        if(num[secondpos] == '0'){
//            num.erase(0,2);
//            continue;
//        }
//        else{
//            bool flag = true;
//            while(secondpos < num.size()){
//                if(num[secondpos] < num[firstpos]){
//                    num.erase(firstpos,1);
//                    flag = false;
//                    break;
//                }
//                firstpos = secondpos;
//                secondpos++;
//            
//            }
//            if(flag)
//                num.erase(num.size() -1 , 1);
//        }
//    }
//
//    return num.size() == 0 ? "0" : num;
//}
string removeKdigits(string num, int k){
    string res;
    int keep = num.size() - k;
    for(int i = 0; i < num.size(); i++){
        while(k&&!res.empty()&&res.back() >num[i]){
            res.pop_back();
            k--;
        }
        num.push_back(num[i]);
    }
    if(res.size() > keep)
        res = res.substr(0, keep);
    int trim = 0;
    while(trim < res.size() && res[trim] =='0')
        trim++;
    res.erase(0, trim);
    return res == "" ? "0" : res;
}
int main(int argc, const char * argv[]) {
cout <<removeKdigits("1432219",3);

    std::cout << "Hello, World!\n";
    return 0;
}
