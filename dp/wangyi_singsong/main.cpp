#include <iostream>
#include <vector>
using namespace std;
/*
 *
小Q和牛博士合唱一首歌曲,这首歌曲由n个音调组成,每个音调由一个正整数表示。
对于每个音调要么由小Q演唱要么由牛博士演唱,对于一系列音调演唱的难度等于所有相邻音调变化幅度之和, 例如一个音调序列是8, 8, 13, 12, 那么它的难度等于|8 - 8| + |13 - 8| + |12 - 13| = 6(其中||表示绝对值)。
现在要对把这n个音调分配给小Q或牛博士,让他们演唱的难度之和最小,请你算算最小的难度和是多少。
如样例所示: 小Q选择演唱{5, 6}难度为1, 牛博士选择演唱{1, 2, 1}难度为2,难度之和为3,这一个是最小难度和的方案了。
输入描述:
输入包括两行,第一行一个正整数n(1 ≤ n ≤ 2000) 第二行n个整数v[i](1 ≤ v[i] ≤ 10^6), 表示每个音调。


输出描述:
输出一个整数,表示小Q和牛博士演唱最小的难度和是多少。

输入例子1:
5
1 5 6 2 1

输出例子1:
3
 */

//思路，使用dp，定义dp[i][j]为A唱i字符，B唱j字符的最小值
int n;
vector<int> vec = {-1};

int solve(vector<vector<int>>& dp, int x, int y){
    int nexepos  = max(x, y) + 1;
    if (nexepos > n)
        return 0;
    if(dp[x][y] != -1)
        return dp[x][y];
    dp[x][y] = min(solve(dp,x,nexepos) + y > 0 ? abs(vec[nexepos] - vec[y]):0, solve(dp,nexepos, y) + x > 0 ? abs(vec[nexepos] - vec[x]):0);
    return dp[x][y];
}
int main() {

    cin >> n;
    vector<vector<int>> dp(n, vector<int>(n,-1));
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }

    cout << solve(dp,0,0)<<endl;
    return 0;

}