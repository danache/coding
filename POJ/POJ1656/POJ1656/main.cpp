//
//  main.cpp
//  POJ1656
//
//  Created by dan on 16/9/17.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <string>
#include <string.h>
#define MAXN 101

using namespace std;
bool p[MAXN][MAXN];
void show(){
    for (int i = 1; i <= 10; i++){
        for (int j = 1; j <= 10; j++){
            if(p[i][j])
                cout << 1 << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
    
}
void paint(int x, int y, int l, bool color){
    for (int i = x; i < x + l; i++)
        for (int j = y; j < y + l; j++)
            p[i][j] = color;
}
int sum(int x, int y, int l){
    int num = 0;
    for (int i = x; i < x + l; i++)
        for (int j = y; j < y + l; j++)
            if(p[i][j])
                num++;
    return num;
    
}
void execute(string command, int x, int y, int l){
    if (command == "WHITE"){
        paint(x, y, l, false);
        
    }
    
    else if (command == "BLACK"){
        paint(x, y, l, true);
        //show();
    }
    else if (command == "TEST"){
        cout << sum(x, y, l) << endl;
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    memset(p, false, sizeof(p));
    string command;
    int x, y, l;
    int ncase;
    cin >> ncase;
    while(ncase -- ){
        cin  >> command >> x >> y >> l;
        execute(command, x, y, l);
    }
    return 0;
}
