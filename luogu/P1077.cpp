#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>

#define MAX_VALUE 110
#define MOD 1000007
using namespace std;
//DP��
//��1��dp[i][j]:�ӵ�1�ֵ���i�ֻ��������j�����ʱ���ж����ַ���
//��2��dp[i][j] += dp[i-1][j-k];��i�ֻ���k�裬��ô��Ӧ�ü���j-k��ʱ�ķ�����
//��3����ʼ�����·�����ʼ����
//��4���յ�dp[n][m]
int dp[MAX_VALUE][MAX_VALUE];

int maxNumber[MAX_VALUE];


int main()
{
    int m,n;
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; i++){
        scanf("%d",&maxNumber[i]);
    }
    //����ʼ��������0����ʱ�������ǵ�1�ֻ�����
    for(int i = 0;i <= maxNumber[1]; i++){
        dp[1][i] = 1;
    }
    for(int i = 2; i <= n; i++){
        for(int j = 0;j <= m; j++){//j=0�ĺ�����ֱ����i�ֻ�ʱ��һ�趼û�аڳ���
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
