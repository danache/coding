//
//  main.cpp
//  leetcode331
//
//  Created by 萧天牧 on 17/7/11.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;
bool isValidSerialization(string preorder) {
    if(preorder.empty())
        return true;
    if(preorder.size() == 1 && preorder[0] == '#')
        return true;
    stack<int> sta;
    stringstream ss(preorder);
    string tmpstr;
    getline(ss, tmpstr, ',');
    for (int i = 0; i < tmpstr.size(); i++){
        if(tmpstr[i] == ',')
            continue;
        if(tmp == "#"){
            if(sta.empty())
                return false;
            int tmp = sta.top();
            sta.pop();
            tmp--;
            if(tmp == 0)
                continue;
            sta.push(tmp);
        }
        else{
            if(!sta.empty()){
                int tmp = sta.top();
                sta.pop();
                tmp--;
                if(tmp != 0)
                    sta.push(tmp);
            }
            sta.push(2);
        }
    }
    return sta.empty();
}
int main(int argc, const char * argv[]) {
    cout <<isValidSerialization("934##1##2#6##");
    std::cout << "Hello, World!\n";
    return 0;
}
