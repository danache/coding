//
//  main.cpp
//  POJ1503
//
//  Created by dan on 16/9/13.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
using namespace std;
#define MAXN 105
string p[MAXN];
void reversal(string &s){
    int len = s.length();
    for (int i = 0; i < len/ 2; i++)
    {
        //前后交换
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }

}
int main(int argc, const char * argv[]) {

    int index = 0;
    string s;
    char res[MAXN];
    int wei = 0;
    while(cin >> s){
        if (s == "0")
            break;
        p[index] = s;
        reversal(p[index++]);
    }
    
    int carry = 0;
    int single;
    bool flag = false;
    for(int i = 0; i < 101; i++){
        flag = false;
        single = carry;
        for(int j = 0; j < index; j++){
            if( i < p[j].size()){
                single += p[j][i] - '0';
                flag = true;
            }
        }

        res[i] = (single % 10 + '0');
        wei++;
        if(carry !=0)
            flag = true;
        if(!flag)
            break;
        carry = single / 10;
        single = 0;
    }
    for (int i = wei - 1; i >= 0; i--)
    {
        if(i == wei - 1 && res[i] == '0')
            continue;
        cout << res[i];
    }
    cout << endl;
    
}
