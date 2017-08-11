//
//  main.cpp
//  leetcode091
//
//  Created by 萧天牧 on 17/6/30.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
bool isvalid(char a, char b){
    return a == '1' || (a == '2' && b <= '6');
}
bool isvalid(char a){
    return a != '0';
}
int numDecodings(string s) {
    if(s.size() == 0 || s[0] == '0')
        return 0;
    int res = 0;
    int fn_1 = 1, fn_2 = 1;
    
    for(int i = 1; i < s.size(); i++){
        if(s[i] == '0'){
            if(s[i - 1] == '1' || s[i - 1] == '2')
                res += fn_2;
            else
                return 0;
        }
        if(isvalid(s[i - 1], s[i]) && isvalid(s[i]))
           res += fn_1 + fn_2;
        if(!isvalid(s[i - 1], s[i]) && isvalid(s[i]))
            res += fn_1 ;
        fn_2 = fn_1;
        fn_1 = res;
        res = 0;
    }
    
    return fn_1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string s;
    while(cin >> s)
        cout << numDecodings(s)<<endl;
    return 0;
}
