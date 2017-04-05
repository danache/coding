#include<iostream>
#include<algorithm>
using namespace std;

int minCount = 99999;
int n;
int value[1000];


bool comp(int &x, int  &y)
    {
        return y<x;
    }


void dfs(int left_value,int now_index,int now_select_num){
    if(left_value < 0)
        return;
    if(now_index == n)
        return;
    if(left_value - value[now_index] < 0){
            dfs(left_value, now_index + 1, now_select_num);
    }
    else if(left_value - value[now_index] == 0){
        now_select_num += 1;
        minCount = min(now_select_num, minCount);
        return;
    }
    else{
        dfs(left_value - value[now_index], now_index, now_select_num + 1);
    }
    
    
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >>value[i];
    }
    sort(value, value + n,comp);
    int allvalue ;
    cin >>allvalue;
    dfs(allvalue, 0, 0);
    if(minCount == 99999)
        cout << -1;
    else
        cout << minCount;
    return 0;

}
