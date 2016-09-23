//
//  main.cpp
//  POJ1657
//
//  Created by dan on 16/9/16.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;
void getRes(string s1, string s2){
    int kingStep, queenStep, carStep, eleStep;
    kingStep = queenStep = carStep = eleStep = 0;
    bool eleflag = true;
    
    int dx = abs(double(s1[0] - s2[0]));
    int dy = abs(double(s1[1] - s2[1]));
    if(int(abs(double(dx + dy))) % 2 != 0)
        eleflag = false;
    if (dx == 0 || dy == 0)
    {
        carStep = 1;
        queenStep = 1;
    }
    else if (dx == dy){
        carStep = 2;
        queenStep = 1;
        if(eleflag)
            eleStep = 1;
    }
    else{
        carStep = 2;
        queenStep = 2;
        if(eleflag)
            eleStep = 2;
    }
    
    if(dx < dy)
        kingStep = dy;
    else
        kingStep = dx;;
    dx = s1[0] - s2[0];
    dy = s1[1] - s2[1];
    
    if(dx == 0 && dy == 0)
        cout << "0 0 0 0" << endl;
    else{
        cout << kingStep << " " << queenStep << " " << carStep << " ";
        if(eleflag){
            cout << eleStep << endl;
        }
        else
            cout <<"Inf" << endl;
    }
}
map<char, int > dictionary;
int main(int argc, const char * argv[]) {
   
    
    
    int ncase;
    cin >> ncase;
    string s1, s2;
    while(ncase--){
        cin >> s1 >> s2;
        getRes(s1, s2);
    }
}
