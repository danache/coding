//
//  main.cpp
//  POJ2109
//
//  Created by dan on 16/9/15.
//  Copyright © 2016年 dan. All rights reserved.
//

/***************************************************************************
 这个题有两种解法，一种是正常的高精度乘法+2分，先猜测对应位数在一个一个试验，另外一个利用了
 double的精度可以达到
 
 类型          长度 (bit)           有效数字          绝对值范围
 float             32                      6~7                  10^(-37) ~ 10^38
 double          64                     15~16               10^(-307) ~10^308
 long double   128                   18~19                10^(-4931) ~ 10 ^ 4932
 
 接下来就是直接用pow(n,1/p)就可以了。
 指数k除了使用对数log，还能使用指数的倒数开n次方，这时就可以用pow函数了。
 代码中写的是高精度计算。
 技巧：假设k^n=p;(k的n次方)，那么p的位数/n得到的是k的位数！例如：n=7，p=4357186184021382204544，p的位数为22，用22/7的结果向上取整，得到4，即为k的位数，也就是说k的取值范围是1000~9999。（引自code_pang）不利用这一点，高精度+直接二分，也会超时。用这一个技巧合理缩小二分的范围。
 */
#include <iostream>
#include <cmath>
using namespace std;

int res[111];
int middle[111];


void multi(int *a, int *b){
    for(int i = 0; i < 110; i++)
        for (int j =0; j < 10; j++){
            res[i + j] = a[i] * b[j];
        }
    for(int i = 0; i < 110; i++){
        res[i + 1] += res[i] /10;
        res[i] %= 10;
    }
}

void rev(char *p, int end){
    int mid = end / 2;
    for (int i = 0; i < mid; i++)
    {
        int tmp = p[i];
        p[i] = p[end - i];
        p[end - i] = tmp;
    }
    
}

int com(int *res, int *middle){
    
    return 1;
}

int main(int argc, const char * argv[]) {
    char p[111];
    int n;
    cin >> n >> p;
    int index = 0;
    while (p[index] != '\0' && index < 111)
        index++;
    rev(p, index);
    int k = (int)ceil((double)index / n);
    int minedge = 1;
    int maxedge = 9;
    
    for(int i = 0; i < k; i++){
        minedge *= 10;
        maxedge *= 10;
        maxedge += 9;
    }
    while(maxedge - minedge > 0){
        int mid = (maxedge - minedge) / 2;
        int rest = com(res, middle);
        if (rest == 0)
            break;
        else if(rest == 1)
            minedge = mid + 1;
        else
            maxedge = mid - 1;
    }
}
