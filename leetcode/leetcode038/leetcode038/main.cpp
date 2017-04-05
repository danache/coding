//
//  main.cpp
//  leetcode038
//
//  Created by 萧天牧 on 17/3/1.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <sstream>
using namespace std;

string countAndSay(int n) {
    string last = "1";
    if (n == 1)
        return "1";
    string result = "";
    while(n > 1){
        result = "";
        char c = last[0];
        int count = 0;
        for (int i = 0; i < last.size(); i++){
            if (i == 0 || last[i - 1] == last[i]){
                count++;
            }
            else{
                result += count + '0';
                result += c;
                c = last[i];
                count = 1;
            }
        }
        result += count + '0';
        result += c;
        if (n == 2)
            return result;
        else{
            last = result;
            n --;
        }
    }
    return result;
}
int main(int argc, const char * argv[]) {
    int n;
    while(cin >> n){
    cout << countAndSay(n)<<endl;
    }
    return 0;
}
