//
//  main.cpp
//  POJ1028
//
//  Created by dan on 16/9/12.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <stack>
#include <cstdio>
#include <string>

using namespace std;
enum oper {BACK, FORWARD, VISIT, QUIT};
stack<string> foorward;
stack<string> baackward;

int main(int argc, const char * argv[]) {
    
    string tmp;
    string url;
    string currentPage = "http://www.acm.org/";
    while(cin >> tmp){
        if (tmp =="QUIT")
            break;
        else if (tmp == "VISIT"){
            cin >> url;
            baackward.push(currentPage);
            currentPage = url;
            while(foorward.size() != 0)
                foorward.pop();
        }
        else if (tmp == "BACK"){
            if(baackward.size() == 0){
                cout << "Ignored" << endl;
                continue;
            }
            else{
            foorward.push(currentPage);
            currentPage = baackward.top();
            baackward.pop();
            }
        }
        else if (tmp == "FORWARD"){
            if(foorward.size() == 0){
                cout << "Ignored" << endl;
                continue;
            }
            else{
                baackward.push(currentPage);
                currentPage = foorward.top();
                foorward.pop();
            }
        }
        cout << currentPage << endl;
    }
}
