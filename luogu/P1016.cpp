#include <cstdio>
#include<algorithm>
using namespace std;

const double INF = 10000.0;


struct node{
    double d,p;
};
bool cmp (const node &a,const node &b){
    return  a.d<b.d;
}
int main(){
    double dist,perDist,container,P0;
    int N;
    scanf("%lf%lf%lf%lf%d",&dist,&container,&perDist,&P0,&N);

    double MAX_DIST = container * perDist;
    node arr[N+2];
    arr[0].d = 0.0;arr[0].p = P0;
    arr[N+1].d = dist;arr[N+1].p = INF;

    for(int i = 1; i <= N; i++){
        scanf("%lf%lf",&arr[i].d,&arr[i].p);
    }
    sort(arr,arr+N+1,cmp);
    for(int i = 1; i < N+2; i++){
        if(arr[i].d - arr[i-1].d > MAX_DIST){
            printf("No Solution\n");
            return 0;
        }
    }


    double minFee = INF;
    int minIdx = 0;
    int loc  = 1;

    double result = 0;
    double curContainer = 0.0;
    int curIdx = 0;

    while(curIdx <= N){
        while(loc <= N && arr[curIdx].d + MAX_DIST >= arr[loc].d){
            if(arr[curIdx].p > arr[loc].p){
                result += ((arr[loc].d - arr[curIdx].d) - curContainer * perDist) / perDist * arr[curIdx].p;//加到正好到
                curIdx = loc;
                loc += 1;
                curContainer = 0.0;
                minFee = INF;
                continue;
            }
            if(minFee >= arr[loc].p){//同价格到远的那个
                minFee = arr[loc].p;
                minIdx = loc;
            }
            loc++;
        }

        if(arr[curIdx].d + MAX_DIST >= dist){
            result += ((dist - curContainer * perDist - arr[curIdx].d) / perDist) * arr[curIdx].p;//加到正好到重点
            break;
        }else{
            result += (container - curContainer) * arr[curIdx].p;//加满
            curContainer = curContainer - (arr[minIdx].d - arr[curIdx].d) / perDist;
            curIdx = minIdx;
            curDist = arr[minIdx].d;
            minFee = INF;
            loc = minIdx + 1;
        }


        //走到最小的点

    }
    printf("%.2lf",result);

    return 0;
}
