//
//  RPN.cpp
//  stack
//
//  Created by dan on 16/8/31.
//  Copyright © 2016年 dan. All rights reserved.
//

#include "RPN.hpp"
#include <iostream>
#include <stack>
using namespace std;
typedef enum{ADD, MINUS, MUL, DIV, POW, FAC, L_P, R_P ,EOE} oper;
const int optrnum = 9;
char pri[optrnum][optrnum] = {
    /*   +  */   '>', '>', '<', '<', '<', '<', '<', '>', '>',
    /*   -  */   '>', '>', '<', '<', '<', '<', '<', '>', '>',
    /*   *  */   '>', '>', '>', '>', '<', '<', '<', '>', '>',
    /*   /  */   '>', '>', '<', '<', '<', '<', '<', '>', '>',
    /*   ^  */   '>', '>', '<', '<', '<', '<', '<', '>', '>',
    /*   !  */   '>', '>', '<', '<', '<', '<', ' ', '>', '>',
    /*   (  */   '<', '<', '<', '<', '<', '<', '<', '=', ' ',
    /*   )  */   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    /*   /0  */  '<', '<', '<', '<', '<', '<', '<', ' ', '='
    
};

float readNum(char *&S){
    int res = 0;
    while(isdigit(*S))
    {
        res = res * 10 + (*S -'0');
        S++;
    }
    if ('.' == *S){
        float fraction = 1;
        while(isdigit(*(++S))){
            res += (*S -'0') *(fraction /= 10);
        }
    }
        
    
    return res;
};

char getPre(char S, char top){
    return ' ';
}

void append(char *& RPN, float num){
    
}

void append(char *& RPN, char optr){
    
}

float calu(float num, char optr){
    int res = 1;
    for (int i = 0; i < num; i++){
        res *= i;
    }
    return res;
};

float calu(float leftnum, char optr, float rightnum){
    switch (optr) {
        case '+':
            return leftnum + rightnum;
        case '-':
            return leftnum - rightnum;
        case '*':
            return leftnum * rightnum;
        case '/':
            if (rightnum == 0)
                exit(-1);
            return leftnum / rightnum;
        case '^':
            int tmp = 1;
            for (int i = 0;i < rightnum; i++){
                tmp *= leftnum;
            };
            return tmp;
    }
    exit(-1);
};


float excute(char *S, char*& RPN){
    stack<float> numstack;
    stack<char> optr;
    optr.push('\0');
    while(!optr.empty()){
        if (isdigit(*S)){
            float num = readNum(S);
            numstack.push(num);
            append(RPN, num);
        }
        else{
            switch (getPre(optr.top(), *S)) {
                case '<':
                    optr.push(*S);
                    S++;
                    break;
                case '=':
                    optr.pop();
                    S++;
                    break;
                case '>':
                    char caloptr = optr.top();
                    optr.pop();
                    append(RPN, caloptr);
                    if(caloptr == '!'){
                        float calnum = numstack.top();
                        numstack.pop();
                        numstack.push(calu(calnum, caloptr));
                        S++;
                    }
                    else{
                        float leftnum = numstack.top();
                        numstack.pop();
                        float rightnum = numstack.top();
                        numstack.pop();
                        numstack.push(calu(leftnum, caloptr, rightnum));
                        S++;
                    }
                    break;
            }
        }
    }
    return numstack.top();
}