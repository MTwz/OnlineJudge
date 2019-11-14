#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX_VALUE = 10;

int numMap[MAX_VALUE][MAX_VALUE];
int dp[MAX_VALUE][MAX_VALUE][MAX_VALUE][MAX_VALUE];

//״̬ת�Ʒ��̵Ľ��ͣ�
//80������Ϊ�ȼ�·��ѡ������⣬�������������ε������ڸ�ά�ռ��dp�У����Ա�֤�����ȼ�·������ѡ����û���Ⱥ�˳�򣬼�
//dp[i-1][j][k][l-1]��dp[i][j-1][k-1][l] > dp[i-1][j][k-1][l]��dp[i][j-1][k][l-1]

// �����ָ�άdp��������һ�����ϵ�״̬
int getAns(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                for(int l = 1; l <= n; l++){
                    dp[i][j][k][l] = max(max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1]),
                                         max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1])) + numMap[i][j] + numMap[k][l];
                    if(i == k && j == l)
                        dp[i][j][k][l] -= numMap[i][j];
                }
            }
        }
    }

    return dp[n][n][n][n];
}

int main(){
    int n = 0;
    scanf("%d",&n);
    int row,col,val;
    while(1){
        scanf("%d%d%d",&row,&col,&val);
        if(!row && !col && !val)break;
        numMap[row][col] = val;
    }
    int result = getAns(n);
    printf("%d",result);
    return 0;
}
