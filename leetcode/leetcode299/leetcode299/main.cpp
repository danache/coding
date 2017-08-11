//
//  main.cpp
//  leetcode299
//
//  Created by 萧天牧 on 17/6/29.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
string getHint(string secret, string guess) {
    vector<int> s(10,0);
    vector<int> g(10,0);
    int A = 0, B = 0;
    if(secret.empty() || secret.size() != guess.size())
        return "0A0B";
    for(int i = 0; i < secret.size(); i++){
        if(secret[i] == guess[i])
            A++;
        else{
            s[secret[i] - '0']++;
            g[guess[i] - '0']++;
        }
    }
    for(int i = 0; i < 10; i++){
        B += min(s[i], g[i]);
    }
    char buf[500] = {0};
    sprintf(buf,"%dA%dB" , A,B);
    string str = buf;
    return str;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << getHint("1122","2211");
    return 0;
}
