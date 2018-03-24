#include <iostream>
#include <map>
#include <vector>
using namespace std;

int x,y,z;
int solve(int now, int aim,map<int,int>& mp){
    if (now == aim){
        return 0;
    }
    if(now < 0 ||  now % 2 != 0){
        mp[now] = INT32_MAX;
        return mp[now];
    }
    if(mp.count(now) > 0){

        return mp[now];
    }
    if(now-aim > 10000) {
        mp[now] = INT32_MAX;
        return INT32_MAX;
    }
    mp[now] = INT32_MAX;
    int val1 = solve(now + 2, aim,  mp) ;
    if (val1 != INT32_MAX)
        val1 += x;
    int val2 = solve(now * 2, aim,  mp) ;
    if (val2 != INT32_MAX)
        val2 += y;
    int val3 = solve(now - 2, aim,  mp);
    if (val3 != INT32_MAX)
        val3 += z;
    mp[now] = min(val1,min(val2,val3));
    return mp[now];
}
int getRes(int start,int end){
    map<int,int> mp;
   return solve(start,end,mp);
}
int main() {
    int start,end;
    cin >> x >> y>>z>> start >> end;

    cout << getRes(start,end);
}