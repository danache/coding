#include <iostream>
using namespace std;

#include <algorithm>
#include <map>
#include <vector>

int main() {
    int n, x,t;
    map<int,vector<int>> mp;
    cin >> n;
    int m = n;
    while(m--){
        cin >> x >> t;
        if(mp.count(t) == 0){
            vector<int> tmp = {x};
            mp[t] = tmp;
        } else{
            mp[t].push_back(x);
        }
    }

    vector<vector<int>> dp(2,vector<int>(n,0));
    for(map<int,vector<int>>::iterator iter = mp.begin();iter != mp.end(); iter++) {
        for(int j = 0; j < n; j++){
            int res = 0;
            if(j - 1 >= 0)
                res += dp
        }
        std::cout << "Hello, World!" << std::endl;
    }
    return 0;
}