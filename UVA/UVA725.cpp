#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;


int flag = 0;
int control = 0;
void bf(int input){
    int num1,num2,tmp,check;
    for(int i = 0;i <= 9; i++){
        for(int j = 0; j <= 9; j++){
            for(int k = 0; k <= 9; k++){
                for(int n = 0; n <= 9; n++){
                    for(int m = 0; m <=9; m++){
                        num1 = i*10000 + j*1000 + k*100 + n*10 + m;
                        check |= (1<<i);
                        check |= (1<<j);
                        check |= (1<<k);
                        check |= (1<<m);
                        check |= (1<<n);
                        if((num2 = num1 * input)>99999){
                            check = 0;
                            continue;
                        }else{
                            tmp = num2;
                            while(tmp){
                                check |= (1<<(tmp%10));
                                tmp /= 10;
                            }
                            if(check == 0x3FF){
                                flag = 1;
                                printf("%d / %05d = %d\n",num2,num1,input);
                            }
                            check = 0;
                        }
                    }
                }
            }
        }
    }


}

int main(){
    //freopen("exp.out","w",stdout);
    int input;
    while(scanf("%d",&input),input){
        if(!control){
            control = 1;
        }else{
            printf("\n");
        }
        flag = 0;
        bf(input);
        if(!flag){
            printf("There are no solutions for %d.\n",input);
        }

    }
    return 0;
}
