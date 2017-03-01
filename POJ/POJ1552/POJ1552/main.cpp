//
//  main.cpp
//  POJ1552
//
//  Created by dan on 16/9/14.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int p[16];
int getNum(int *p, int index){
    int res = 0;
    for(int i = 0; i < index; i++){
        for(int j = i + 1; j < index; j++){
            if (p[j] == 2 * p[i])
                res++;
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string s;
    while(getline(cin, s)){
        istringstream iss(s);
        int num, index = 0;
        while(iss >> num)
        {
            p[index++] = num;
        }
        if(p[0] == -1)
            break;
        sort(p, p + index);
        cout << getNum(p, index) << endl;;
        memset(p, 0, sizeof(p));
        
    }
    
}
