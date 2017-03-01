//
//  main.cpp
//  POJ1013
//
//  Created by dan on 16/9/18.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int p[12];
bool istrue[12];
int main(int argc, const char * argv[]) {
    int ncase;
    cin >> ncase;
    string s1, s2, s3;
    while(ncase--){
        memset(istrue, false, sizeof(istrue));
        memset(p, 0, sizeof(p));
        for (int i = 0; i < 3; i++){
            cin >> s1 >> s2 >> s3;
            if(s3 == "even")
                for (int i = 0; i < s1.size(); i++){
                    istrue[s1[i] - 'A'] = true;
                    p[s1[i] - 'A'] = 0;
                    istrue[s2[i] - 'A'] = true;
                    p[s2[i] - 'A'] = 0;
                }
            else if(s3 == "up"){
                for(int i = 0; i < s1.size(); i++){
                    if (!istrue[s1[i] - 'A']){
                        p[s1[i] - 'A']++;
                    }
                    if(!istrue[s2[i] - 'A']){
                        p[s2[i] - 'A']--;
                    }
                }
            }
            else if (s3 == "down"){
                for(int i = 0; i < s1.size(); i++){
                    if (!istrue[s1[i] - 'A']){
                        p[s1[i] - 'A']--;
                    }
                    if(!istrue[s2[i] - 'A']){
                        p[s2[i] - 'A']++;
                    }
                }
            }
        }
        
        int nmax = -9999;
        int maxnum = 0;
        int nmin = 9999;
        int minnum = 0;
        for (int i = 0; i < 12; i++){
            if (p[i] > nmax){
                nmax = p[i];
                maxnum = i;
            }
            if (p[i] < nmin){
                nmin = p[i];
                minnum = i;
            }
            
        }
        if (nmax >= abs(nmin)){
            cout << char('A' + maxnum) << " is the counterfeit coin and it is heavy." << endl;
        }
        else if (nmax < abs(nmin)){
            cout << char('A' + minnum) << " is the counterfeit coin and it is light." << endl;
        }
        
    }
}
