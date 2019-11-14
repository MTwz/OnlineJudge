#include <iostream>
#include <cstdio>
#include <string>

#define MAX_VALUE 30

using namespace std;

string words[MAX_VALUE];
int visit[MAX_VALUE];
int nextWords[MAX_VALUE][MAX_VALUE];
int result = 0;

///矩阵：记录前一个单词i后接单词j时，串增加的长度
//例如：beast和astonish，该值为5；ast和yuyu，该值为0

void buildMartix(int n){
    int nextWordsIdx,firstWordIdx;
    bool match;
    for(int i = 0; i<n;i++){
        for(int j = 0;j < n;j++){
            for(int startIdx = words[i].size() - 1;startIdx >= 0; startIdx--){
                nextWordsIdx = 0;
                match = true;
                for(firstWordIdx = startIdx; firstWordIdx < words[i].size(); firstWordIdx++){

                    if(words[i][firstWordIdx] != words[j][nextWordsIdx]){
                        match = false;
                        break;
                    }
                    nextWordsIdx++;
                }
                if(match && nextWordsIdx){
                    nextWords[i][j] = words[j].size() - nextWordsIdx;
                    break;
                }
            }
        }
    }

}
void dfs(int len,int before,int n,int idx){
    if(visit[idx] > 2){
        if(result < len - before)result = len - before;
        return ;
    }
    bool hasNext = false;
    for(int i = 0;i < n; i++){
        if(nextWords[idx][i]){
            hasNext = true;
            visit[i]++;
            dfs(len+nextWords[idx][i],nextWords[idx][i],n,i);
            visit[i]--;
        }
    }
    if(!hasNext){
        if(result < len)result = len;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        cin>>words[i];
    }
    char startWord;
    cin>>startWord;
    buildMartix(n);

    for(int i = 0; i < n; i++){
        if(words[i][0] == startWord){
            visit[i]++;
            dfs(words[i].size(),0,n,i);
            visit[i]--;
        }
    }
    printf("%d\n",result);
    return 0;
}
