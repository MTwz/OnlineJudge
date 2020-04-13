#include <cstdio>
#include <algorithm>

#define N 210
#define MAX_VALUE 0x7fffffff
using namespace std;


int arr[N];
int visit[N];
int minCnt = MAX_VALUE;
void dfs(int n,int dep,int cur,int tgt){
    if(cur == tgt){
        if(minCnt > dep){
            minCnt = dep;
        }
        return ;
    }
    if(dep >= minCnt)return ;
    if(cur + arr[cur] <= n && !visit[cur + arr[cur]]){
        visit[cur + arr[cur]] = 1;
        dfs(n,dep+1,cur+arr[cur],tgt);
        visit[cur + arr[cur]] = 0;
    }
    if(cur - arr[cur] > 0 && !visit[cur - arr[cur]]){
        visit[cur - arr[cur]] = 1;
        dfs(n,dep+1,cur-arr[cur],tgt);
        visit[cur - arr[cur]] = 0;
    }
}

int main(){
    int n = 0,src,tgt;
    scanf("%d%d%d",&n,&src,&tgt);
    for(int i = 1; i <= n; i++){
        scanf("%d",&arr[i]);
    }
    dfs(n,0,src,tgt);
    if(minCnt == MAX_VALUE){
        printf("-1");
    }else{
        printf("%d",minCnt);
    }
    return 0;
}
