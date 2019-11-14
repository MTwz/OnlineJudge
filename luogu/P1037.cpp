#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;


int n;
char number[40];
int visit[10];
int cnt[10];
int rule[10][10];
int change[10];
int num[101];
unsigned long long dfs(int cur){
    unsigned long long sum = 0;
    for(int i = 0;i < 10; i++){
        if(!visit[i] && rule[cur][i]){
            visit[i] = 1;
            sum++;
            sum+=dfs(i);
        }
    }
    return sum;
}


int main()
{
    scanf("%s",number);
    scanf("%d",&n);
    int ori,tgt;
    for(int i = 0; i< n;i++){
        scanf("%d %d",&ori,&tgt);
        rule[ori][tgt] = 1;
    }

    for(int i = 0; i < 10; i++){//dfs��ǰ���ֿɱ任�����ָ�����Ҳ�ɲ���Floyd�㷨��
        memset(visit,0,sizeof(visit));
        visit[i] = 1;
        change[i] = dfs(i)+1;//��1�Ǽ�������
    }

    int numberLen = strlen(number);//�߾��ȹ���
    int len = 2;
    num[1] = 1;
    for(int i = 0;i < numberLen; i++) {
        for(int j = 1;j <= 100; j++) num[j] *= change[number[i]-'0'];//��number[i]�����������
        for(int j = 1;j <= 100; j++) {
            num[j+1] += num[j] / 10;
            num[j] %= 10;
        }
        while(num[len]) len++;
    }
    for(int i = len - 1;i >= 1; i--)
        printf("%d",num[i]);
    return 0;
}
