//
//  main.cpp
//  POJ2503
//
//  Created by dan on 16/9/20.
//  Copyright © 2016年 dan. All rights reserved.
//
//POJ C++可以过，G++不行。学到了t = getchar() == '\n'读入空行的办法
//以及getchar吃掉空行。
#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
using namespace std;
char english[12];
map<string, string> dict;
map<string, bool> appear;
int main(int argc, const char * argv[]) {
    while(true){
        char english[12];
        char foreign[12];
        char t;
        t = getchar();
        if(t == '\n')
        {
            break;
        }
        else{
            int i = 1;
            english[0] = t;
            while(true){
                t = getchar();
                if(t == ' '){
                    english[i] = '\0';
                    break;
                }
                else
                    english[i++] = t;
            }
        }
        cin >> foreign;
        getchar();
        dict[foreign] = english;
        appear[foreign] = true;
    }
    char tmp[11];
    while(cin >> tmp){
        if (appear[tmp] == true){
            cout << dict[tmp] << endl;
        }
        else
            cout << "eh" << endl;
    }
    return 0;
}

