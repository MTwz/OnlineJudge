#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>

#define MAX_VALUE 110
#define MOD 1000007
using namespace std;
//DP：
//（1）dp[i][j]:从第1种到第i种花，如果有j个盆的时候，有多少种方案
//（2）dp[i][j] += dp[i-1][j-k];第i种花出k盆，那么他应该加上j-k盆时的方案数
//（3）初始化见下方【初始化】
//（4）终点dp[n][m]
int dp[MAX_VALUE][MAX_VALUE];

int maxNumber[MAX_VALUE];


int main()
{
    int m,n;
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; i++){
        scanf("%d",&maxNumber[i]);
    }
    //【初始化】包括0个盆时，含义是第1种花不摆
    for(int i = 0;i <= maxNumber[1]; i++){
        dp[1][i] = 1;
    }
    for(int i = 2; i <= n; i++){
        for(int j = 0;j <= m; j++){//j=0的含义是直到第i种花时，一盆都没有摆出来
            for(int k = maxNumber[i]; k >= 0; k--){
                if(j - k >= 0){
                    dp[i][j] += dp[i-1][j - k];
                    if(dp[i][j] >= MOD){
                        dp[i][j] %= MOD;
                    }
                }
            }

        }
    }
    printf("%d",dp[n][m]);
    return 0;
}
