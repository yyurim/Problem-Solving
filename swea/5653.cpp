#include<iostream>
#include<vector>

using namespace std;

#define MAX 352

typedef struct _cell{
    int state;
    int hp;
    int lt;
}cell;

cell map[2][MAX][MAX];

int main(){
    int move[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int tc;
    scanf("%d",&tc);
    for(int test_case = 1 ; test_case <=tc ; test_case++){
        int N, M, K;
        scanf("%d %d %d",&N,&M,&K);

        for(int r = 0 ; r < MAX ; r++){
            for(int c = 0 ; c < MAX ; c++){
                cell temp;
                temp.state = 0;
                temp.hp = 0;
                temp.lt = 0;
                map[0][r][c] = map[1][r][c] = temp;
            }
        }

        for(int r = 1+K/2 ;  r < 1+K/2+N ; r++){
            for(int c = 1+K/2 ; c< 1+K/2+M ;c++){
                int lt;
                scanf("%d",&lt);
                if(lt != 0){
                    map[1][r][c].state = map[0][r][c].state = 1;
                    map[1][r][c].lt = map[0][r][c].lt = lt;
                }

            }
        }

        int now = 0;
        N = 1+K+N;
        M = 1+K+M;
        for(int t= 0 ; t<K ;t++){
            for(int r= 0 ; r < N ; r++){
                for(int c = 0 ; c < M ; c++){
                    if(map[now][r][c].state == 3){
                        map[1-now][r][c].state = map[now][r][c].state;
                        continue;
                    }
                    else if(map[now][r][c].state == 1){
                        map[1-now][r][c].hp = map[now][r][c].hp + 1;
                        map[1-now][r][c].lt = map[now][r][c].lt;

                        if(map[1-now][r][c].hp == map[now][r][c].lt){
                            map[1-now][r][c].state = 2;
                        }
                        else{
                            map[1-now][r][c].state = 1;
                        }
                        
                    }
                    else if(map[now][r][c].state == 2){
                        if(map[now][r][c].hp == map[now][r][c].lt){
                            for(int m = 0 ; m < 4 ; m++){
                                int nr = r + move[m][0];
                                int nc = c + move[m][1];
                                if(map[now][nr][nc].state == 0){
                                    if(map[1-now][nr][nc].state == 0){
                                        map[1-now][nr][nc].state = 1;
                                        map[1-now][nr][nc].lt = map[now][r][c].lt;
                                        map[1-now][nr][nc].hp = 0;                                    
                                    }
                                    else if((map[1-now][nr][nc].state == 1) && (map[1-now][nr][nc].hp == 0)){
                                        if(map[1-now][nr][nc].lt < map[now][r][c].lt){
                                            map[1-now][nr][nc].lt = map[now][r][c].lt;
                                        }
                                    }
                                }
                            }
                        }

                        map[1-now][r][c].hp = map[now][r][c].hp - 1;
                        map[1-now][r][c].lt = map[now][r][c].lt;


                        if(map[1-now][r][c].hp <= 0){
                            map[1-now][r][c].state = 3;
                        }
                        else{
                            map[1-now][r][c].state = 2;
                        }

                    }
                    


                }
            }

            now = 1 - now;

            // for(int r= 0 ; r< MAX; r++){
            //     for(int c = 0 ; c < MAX ;c++){
            //         printf("%2d ",map[now][r][c].lt);
            //     }
            //     printf("\n");
            // }
            // printf("\n");
            
        }

        int count = 0;

        for(int r= 0 ; r< MAX; r++){
            for(int c = 0 ; c < MAX ;c++){
                if((map[now][r][c].state == 1) || (map[now][r][c].state == 2)){
                    count++;
                }
            }
        }

        printf("#%d %d\n",test_case,count);
        
    }
}