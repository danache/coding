//
//  main.cpp
//  leetcode006
//
//  Created by 萧天牧 on 16/12/5.
//  Copyright © 2016年 萧天牧. All rights reserved.
//

#include <iostream>
#include <string.h>
#define MAXN 1000
using namespace std;
enum {down, line} ;
int dx[] = {0, 1};
int dy[] = {1, -1};

class Solution {
public:
    string convert(string s, int numRows) {
        char tmp[MAXN][numRows - 1];
        int n = s.length();
        int di = 0, dj = 0;
        int direction = 0;
        for (int step = 0; step < n; step++){
            tmp[di][dj] = s[step];
            if (dj >= numRows - 1)
                direction = line;
            if (dj <= 0)
                direction = down;
            di += dx[direction];
            dj += dy[direction];
        }
        string res = "";
        for(int i = 0; i < di; i++){
            for(int j = 0; j < numRows; j++){
                if (tmp[i][j] != NULL){
                    
                }
            }
        }
        return "s";
    }
};
int main(int argc, const char * argv[]) {
    
}
