//
//  main.cpp
//  ceshi
//
//  Created by 萧天牧 on 17/4/7.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

//struct line{
//    int x;
//    int l;
//    bool isLive;
//    int left,right;
//    line(int _x, int _l){
//        x = _x;
//        l = _l;
//        isLive = true;
//        left = x;
//        right = x + l;
//    }
//    line(){};
//};
//line *res[201];
//int main(int argc, const char * argv[]) {
//    int n;
//    int x,l;
//    cin >> n;
//    int maxRight = -99999;
//    for(int i = 0; i < n; i++){
//        cin >> x >>l;
//        res[i] = new line(x,l);
//        if (x + l > maxRight)
//            maxRight = x + l;
//    }
//    int maxNum = -1;
//    for(int i = 0; i < maxRight; i++){
//        line** tmp = res;
//        int firstdead = 0;
//        int secdead = 0;
//        for(int j = 0; j < n; j++){
//            if (res[j] -> left <= i && i <= res[j]->right ){
//                res[j] -> isLive = false;
//                firstdead++;
//            }
//        }
//        line** sav = res;
//        for(int k = i + 1; k < maxRight; k++){
//            for(int j = 0; j < n; j++){
//                secdead = 0;
//                if (res[j] -> left <= k && k <= res[j]->right ){
//                    res[j] -> isLive = false;
//                }
//            }
//        }
//    }
//}.
int maxn = 0;
void bfs(vector<vector<int>> car,int start,int end,int remains,int numOfcar){
    if(remains ==2){
        for(int i = start;i <= end;i++){
            int num = 0;
            //clone car
            vector<vector<int>> cloneCar = car;
            for(int k = 0;k < car.size(); k++){
                cloneCar[k][0] = car[k][0];
                cloneCar[k][1] = car[k][1];
            }
            for(int j = 0;j < cloneCar.size(); j++){
                if(cloneCar[j][0] <= i && i <= (cloneCar[j][0] + cloneCar[j][1])){
                    num++;
                    cloneCar[j][0] = -999999;
                    cloneCar[j][1] = -999999;
                }
            }
            bfs(cloneCar,i + 1,end,remains - 1,num);
        }
    }
    else if(remains == 1){
        for(int i = start;i <= end;i++){
            int num = 0;
            for(int j = 0;j<car.size();j++){
                if(car[j][0] <= i && i <= (car[j][0] + car[j][1])){
                    num++;
                }
            }
            maxn = max(maxn,num + numOfcar);
        }
    }
    else return;
}



int main(){
    int n = 0;
    cin >> n;
    
    vector<vector<int>> car;
    int x1=99999,x2=-99999;
    
    for(int i=0;i<n;i++){
        int x, l;
        cin >>x >> l;
        vector<int> tmp = {x,l};
        car.push_back(tmp);
        x1 = min(x1, car[i][0]);
        x2 = max(x2, car[i][0]+car[i][1]);
    }
    bfs(car,x1,x2,2,0);
    cout << maxn << endl;
}
