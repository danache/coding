//
//  main.cpp
//  string2int
//
//  Created by 萧天牧 on 17/5/14.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
bool legal(char s){
    if (('0' <= s && s <= '9') || (s == '+') || (s == '-') || (s =='.') || (s == 'e') || (s == 'E'))
        return true;
    else
        return false;
}
bool isNumeric(char* string)
{
    if (!string)
        return false;
    int i = 0;
    bool firstsign = false;
    bool secondsign = false;
    bool exp = false;
    bool dot = false;
    while(string[i] != '\0'){
        char tmp = string[i];
        if(!legal(tmp))
            return false;
        if(tmp == '+' || tmp == '-'){
            if(i == 0)
                firstsign = true;
            else if (string[i - 1] == 'e' || string[i - 1] == 'E')
                secondsign = true;
            else
                return false;
        }
        if (tmp == '.'){
            if(exp || dot)
                return false;
            else
                dot = true;
        }
        if (tmp == 'e' || tmp == 'E'){
            if(exp)
                return false;
            else if (string[i + 1] == '\0')
                return false;
            else
                exp = true;
        }
        i++;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    char *s[] = {"+100","5e2","-123","3.1416","-1E-16"};
    char *b[] = {"12e","1a3.14","1.2.3","+-5","12e+4.3"};
    for(int i =0; i < 5; i++){
        cout << isNumeric(b[i])<<endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
