//
//  main.cpp
//  POJ3630
//
//  Created by dan on 16/10/17.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
using namespace std;
struct Node{
    char num;
    bool isfull;
    Node* next[10];
    Node(char _num){
        num = _num;
        isfull = false;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

void insert(Node* now, char *p){
    
    now -> num = p[0];
    if (p[1] != '\0'){
        char c = p[1];
        if (now ->next[c - '0']){
            insert(now ->next[c - '0'], p+1);
        }
        else{
            now->next[c - '0'] = new Node(c);
        }
    }
    else{
        now ->isfull = true;
}