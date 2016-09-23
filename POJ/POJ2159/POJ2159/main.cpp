//
//  main.cpp
//  POJ2159
//
//  Created by dan on 16/9/15.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int a1[26];
int a2[26];
int main(int argc, const char * argv[]) {
    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 0; i < s1.size(); i++){
        a1[s1[i] - 'A']++;
    }
    for(int i = 0; i < s2.size(); i++){
        a2[s2[i] - 'A']++;
    }
    sort(a1, a1 + 26);
    sort(a2, a2 + 26);
    bool flag = true;
    for(int i = 0; i < 26; i++){
        if (a1[i] != a2[i])
        {
            flag = false;
        }
    }
    if(flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
