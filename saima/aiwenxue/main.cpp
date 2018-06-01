#include <iostream>
#include <vector>
#include <map>
using namespace std;

void dfs(map<int,int> mp,map<int,int>::iterator it, int nowleft,int nowcost, int& mincost){
    if(it == mp.end())
        return;
    if(nowleft < it -> first)
        return;
    int thisleft = nowleft - it->first;
    if(thisleft == 0){
        mincost = min(mincost, nowcost);
        return;
    }
    map<int,int>::iterator nextit = it;
    nextit++;
    dfs(mp,nextit,thisleft,nowcost+it->second,mincost);

}

int main() {
    int n,m,tmp;

    cin >> n;
    vector<int> back;
    for(int i = 0; i < n;i++){
        cin >> tmp;
        back.push_back(tmp);
    }
    map<int,int>mp;
    cin >> m;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        mp[a] = b;
    }
    int allmin = INT32_MAX;
    for(auto c : back){
        int mincost = INT32_MAX;
        map<int,int>::iterator it = mp.begin();
        dfs(mp,it,c,0,mincost);
        allmin = min(allmin,mincost);
    }
    if(allmin == INT32_MAX)
        cout << "It is not true!" << endl;
    else
        cout << allmin << endl;
    return 0;
}