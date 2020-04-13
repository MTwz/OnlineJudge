#include <cstdio>
#include <algorithm>

#include <queue>

#define N 52

using namespace std;


//(1)�������ȶ��У�ÿһ����չʱ��val+1�����б�Ȼ����
//(2)ע�������᷽��x�������꣬y�Ǻ�����
//(3)��������
//(4)Q:��ת���ǰ��
struct node {
    int towardIdx;
    int x;
    int y;
    int val;
    node(int _towardIdx,int _x,int _y,int _val):towardIdx(_towardIdx),x(_x),y(_y),val(_val){}
};

int mazeMap[N][N];
int visit[N][N][4];
//��������
int towardStateX[4] = {0,-1,0,1};
int towardStateY[4] = {1,0,-1,0};


int turn(int idx,int type){
    // ��ת��-1����ת��+1
    return (idx + 4 + type)%4;
}
int isAllow(int x, int y){
    return !(mazeMap[x-1][y-1] || mazeMap[x-1][y] || mazeMap[x][y-1] || mazeMap[x][y]);
}


int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d",&mazeMap[i][j]);
        }
    }
    int srcX,srcY,tgtX,tgtY;
    scanf("%d%d%d%d",&srcX,&srcY,&tgtX,&tgtY);
    char toward;int towardIdx = -1;
    scanf("%*c%c",&toward);
    switch(toward){
    case 'E':
        towardIdx = 0;
        break;
    case 'N':
        towardIdx = 1;
        break;
    case 'W':
        towardIdx = 2;
        break;
    case 'S':
        towardIdx = 3;
        break;
    }
    node startNode(towardIdx,srcX,srcY,0);
    queue<node> nodeQueue;
    if(isAllow(srcX,srcY)){
        nodeQueue.push(startNode);
        visit[srcX][srcY][towardIdx] = 1;
    }
    node * ptr;
    while(!nodeQueue.empty()){
        ptr = &nodeQueue.front();
        nodeQueue.pop();
        if(ptr->x == tgtX && ptr->y ==tgtY){
            printf("%d\n",ptr->val);
            return 0;
        }
        int tempX = 0,tempY = 0;

        for(int i = -1; i < 2; i+=2){//��Ӧ����type
            if(!visit[ptr->x][ptr->y][turn(ptr->towardIdx,i)]){
                node curNode(turn(ptr->towardIdx,i),ptr->x,ptr->y,ptr->val + 1);
                visit[ptr->x][ptr->y][turn(ptr->towardIdx,i)] = 1;
                nodeQueue.push(curNode);
            }
        }
        for(int i = 1; i <= 3; i++){
            tempX = ptr->x + i * towardStateX[ptr->towardIdx];
            tempY = ptr->y + i * towardStateY[ptr->towardIdx];
            if(tempX>=1 && tempX<n && tempY>=1 && tempY<m &&
               isAllow(tempX,tempY) && !visit[tempX][tempY][ptr->towardIdx]){
                node curNode(ptr->towardIdx,tempX,tempY,ptr->val + 1);
                visit[tempX][tempY][ptr->towardIdx] = 1;
                nodeQueue.push(curNode);
            }else{//�����������ϰ����ʱ�򴩹�ȥ
                if(tempX >=0 && tempY >= 0)//Q:Ϊʲô��ô��������ж�Ҳ�У�
                    visit[tempX][tempY][ptr->towardIdx] = 1;
                break;
            }
        }


    }
    printf("-1");
    return 0;
}
