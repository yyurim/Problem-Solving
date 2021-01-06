#include<iostream>

using namespace std;

int map[22][22];
int check[22][22];

int main(){
    int tc;
    scanf("%d",&tc);
    for(int test_case = 1; test_case <= tc ; test_case++){
        int N,X;
        scanf("%d %d",&N, &X);
        for(int r = 0 ; r < 22; r++){
            for(int c = 0 ; c < 22 ; c++){
                map[r][c] = 0;
                check[r][c] = 0;
            }
        }

        for(int r = 1 ; r <=N ; r++){
            for(int c = 1 ; c <= N ; c++){
                scanf("%d",&map[r][c]);
            }
        }

        int count = 0;
        for(int r = 1; r<=N ;r++){
            int invalid = 0;
            int flat = 0;
            for(int c = 1 ; c< N ;c++){
                if(map[r][c] == (1+map[r][c+1])){
                    int flag = 1;
                    for(int i = 1; i <=X; i++){
                        int nc = c+i;
                        if(nc > N){
                            invalid = 1;
                            flag = 0;
                            break;
                        }
                        if(map[r][c] != (1+map[r][nc])){
                            invalid = 1;
                            flag = 0;
                            break;
                        }
                    }

                    if(flag){
                        for(int i = 1; i <=X; i++){
                            int nc = c+i;
                            check[r][nc]++;          
                        }
                    }
                }
                else if(map[r][c]==map[r][c+1]){
                    flat++;
                }
            }
            

            for(int c = N ; c > 0 ;c--){
                if(map[r][c] == (1+map[r][c-1])){
                    int flag = 1;
                    for(int i = 1; i <=X; i++){
                        int nc = c-i;
                        if(nc < 1){
                            invalid = 1;
                            flag = 0;
                            break;
                        }

                        if(map[r][c] != (1+map[r][nc])){
                            invalid = 1;
                            flag = 0;
                            break;
                        }
                    }

                    if(flag){
                        int no = 1;
                        for(int i = 1; i <=X; i++){
                            int nc = c-i;
                            if(check[r][nc]){
                                invalid = 1;
                                no = 0;
                                break;
                            }
                                    
                        }
                        if(no){
                            for(int i = 1; i <=X; i++){
                                int nc = c-i;
                                check[r][nc]++;       
                            }
                        }
                    }
                }
            }
            int is_valid = 1;
            int zero_count = 0;
            for(int c = 1; c<=N ;c++){
                if(check[r][c]>1){
                    is_valid = 0;
                    break;
                }
                else if(check[r][c]==0){
                    zero_count++;
                }
            }
            if((invalid==0)&&(is_valid==1)&&(zero_count<N) || (flat==N-1)){
                printf("%d\n",r);
                count++;
            }
        }

        for(int r = 0 ; r < 22; r++){
            for(int c = 0 ; c < 22 ; c++){
                check[r][c] = 0;
            }
        }

        for(int c = 1; c<=N ;c++){
            int invalid = 0;
            int flat = 0;
            for(int r = 1 ; r< N ;r++){
                if(map[r][c] == (1+map[r+1][c])){
                    int flag = 1;
                    for(int i = 1; i <=X; i++){
                        int nr = r+i;
                        if(nr > N){
                            invalid = 1;
                            flag = 0;
                            break;
                        }

                        if(map[r][c] != (1+map[nr][c])){
                            invalid = 1;
                            flag = 0;
                            break;
                        }
                    }

                    if(flag){
                        for(int i = 1; i <=X; i++){
                            int nr = r+i;
                            check[nr][c]++;          
                        }
                    }
                }
                else if(map[r][c]==map[r+1][c]){
                    flat++;
                }
            }
            

            for(int r = N ; r > 0 ;r--){
                if(map[r][c] == (1+map[r-1][c])){
                    int flag = 1;
                    for(int i = 1; i <=X; i++){
                        int nr = r-i;
                        if(nr < 1){
                            invalid = 1;
                            flag = 0;
                            break;
                        }

                        if(map[r][c] != (1+map[nr][c])){
                            invalid = 1;
                            flag = 0;
                            break;
                        }
                    }

                    if(flag){
                        for(int i = 1; i <=X; i++){
                            int nr = r-i;
                            check[nr][c]++;          
                        }
                    }
                }
            }
            int is_valid = 1;
            int zero_count = 0;
            for(int r = 1; r<=N ;r++){
                if(check[r][c]>1){
                    is_valid = 0;
                    break;
                }
                else if(check[r][c]==0){
                    zero_count++;
                }
            }
            if((invalid==0)&&(is_valid==1)&&(zero_count<N) || (flat==N-1)){
                printf("%d\n",c);
                count++;
            }
        }

        printf("#%d %d\n",test_case, count);
    }

}