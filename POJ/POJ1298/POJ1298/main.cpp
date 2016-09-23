//
//  main.cpp
//  POJ1298
//
//  Created by dan on 16/9/13.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;



string getTranslate(string message){
    string res;
    for (int i = 0; i < message.size(); i++){
        char c ;
        char tmp =  message[i];
        if ('F' <= tmp && tmp <= 'Z'){
            c = message[i] - 5;
        }
        else if ('A' <= tmp && tmp <'F'){
            c = message[i] + 21;
        }
        else
            c = message[i];
        res += c;
    }
    return res;
}
int main(int argc, const char * argv[]) {

    string s2;
    while(getline(cin,s2)){
        string message;
        string res;
        if (s2 == "ENDOFINPUT")
            break;
        else if (s2 == "START"){
            getline(cin, message);
        }
        getline(cin, s2);
        res =getTranslate(message);
        cout << res << endl;
    }
    
}
