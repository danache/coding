//
//  main.cpp
//  POJ2350
//
//  Created by dan on 16/9/17.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;
int a[100];
int main(int argc, const char * argv[]) {
    int ncase;
    scanf("%d", &ncase);
    int num;
    while(ncase --){
        int sum = 0;
        scanf("%d", &num);
        for (int i = 0; i < num; i++){
            scanf("%d", &a[i]);
            sum += a[i];
        }
        
        float average = float(sum / num);

        int above = 0;
        for (int i = 0; i < num; i++){
            if (a[i] > average)
                above++;
        }
        double tmp = (above * 1.0) / (num * 1.0 );
        printf("%.3f%%\n", tmp * 100);
        
    }
}
