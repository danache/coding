#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

int dp[25][25][25];

int dfs(int a,int b,int c)
{
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;
    if(a > 20 || b > 20 || c > 20)
        return dfs(20,20,20);
    if(dp[a][b][c])
        return dp[a][b][c];
    if(a<b && b<c)
        dp[a][b][c] = dfs(a,b,c-1)+dfs(a,b-1,c-1)-dfs(a,b-1,c);
    else
        dp[a][b][c] = dfs(a-1,b,c)+dfs(a-1,b-1,c)+dfs(a-1,b,c-1)-dfs(a-1,b-1,c-1);
    return dp[a][b][c];
}

int main()
{
    int a,b,c;
    memset(dp,0,sizeof(dp));
    while(cin >> a >> b >> c)
    {
        if(a == -1 && b == -1 && c == -1)
            break;
        printf("w(%d, %d, %d) = %d\n",a,b,c,dfs(a,b,c));
    }
    
    return 0;
}