#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define HEIGHT 17
#define WIDTH 14

int map[HEIGHT][WIDTH];
int board[4][HEIGHT][WIDTH];
bool check[4][HEIGHT][WIDTH];
int tops[WIDTH];



void update_top(int W, int depth){
    for(int c = 1 ; c <= W ; c++){
        for(int r = 1; r <= HEIGHT ;r++){
            if(board[depth][r][c] > 0){
                tops[c] = r;
                break;
            }
        }
    }
    
    // for(int i = 1 ; i<=W;i++){
    //     cout << tops[i] << " ";
    // }
    // cout << endl;
}

void update_map(int pre, int now){
    for(int r = 1 ; r <=HEIGHT ; r++){
        for(int c = 1 ; c<=WIDTH ; c++){
            if((pre==0)&&(now==0)){
                board[now][r][c] = map[r][c];
                check[now][r][c] = 0;
            }
            else{
                board[now][r][c] = board[pre][r][c];
                check[now][r][c] = check[pre][r][c];
            }
        }
    }
}



void crash(int depth,int r, int c){
    int move[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int bomb = board[depth][r][c];
    
    
    if(bomb == 1){
        board[depth][r][c] = 0;
        check[depth][r][c] = 2;
    }
    else if(bomb > 1){
        board[depth][r][c] = 0;
        check[depth][r][c] = 2;
        for(int m = 0 ; m < 4 ; m++){
            int nr, nc;
            for(int b = 0 ; b < bomb ; b++){
                nr = r + b*move[m][0];
                nc = c + b*move[m][1];
                if((board[depth][nr][nc] > 1) && (check[depth][nr][nc]==0)){
                    crash(depth, nr, nc);
                }
                else if(board[depth][nr][nc] == 1 && (check[depth][nr][nc]==0)){
                    board[depth][nr][c] = 0;
                    check[depth][nr][c] = 2;
                }
                else if(board[depth][nr][nc] < 1 && (check[depth][nr][nc]==1)){
                    board[depth][nr][c] = 0;
                    check[depth][nr][c] = 1;
                }
                
            }

        }

    }
}

int down(int H, int W, int depth){
    for(int c = 1 ; c <=W ; c++){
        for(int r = H; r > 0; r--){
            if(check[depth][r][c] == 1) continue;
            if(board[depth][r][c]==0){
                for(int nr = r ; nr > 0 ; nr--){
                    if(board[depth][nr][c] > 0){
                        board[depth][r][c] = board[depth][nr][c];
                        board[depth][nr][c] = 0;
                        break;
                    }                    
                }
            }

        }
    }
}

int count_two(int leaf,int W, int H){
    int count2 = 0;
    for(int r = 1 ; r <=H ; r++){
        for(int c = 1 ; c<=W ; c++){
            if(check[leaf][r][c]==2){
                cout << "oppj " <<endl;
                count2++;
            }
        }
    }
    return count2;
}


int main(){
    int tc;
    scanf("%d",&tc);
    for(int test_case = 1 ; test_case <= tc ; test_case++){
        int N, H, W;
        scanf("%d %d %d",&N,&H,&W);
        vector<int> count;
        count.push_back(100);
        for(int r = 0 ; r < HEIGHT ; r++){
            for(int c= 0 ; c< WIDTH ; c++){
                map[r][c] = 0;
                for(int n = 0 ; n < 4 ; n++){
                        board[n][r][c] = 0;
                        check[n][r][c] = 0;
                }
            }
        }

        for(int r = 1 ; r <= H ; r++){
            for(int c= 1; c<= W ; c++){
                scanf("%d",&map[r][c]);
                for(int n = 0 ; n < N ; n++){

                    board[n][r][c] = map[r][c];
                    if(map[r][c]==1){
                        check[n][r][c] = 1;
                    }

                }
                

            }
        }
        
        int hack[4];
        for(hack[0] = 1 ; hack[0] <=W ; hack[0]++){
            for(hack[1] = 1 ; hack[1] <=W ; hack[1]++){
                for(hack[2] = 1 ; hack[2] <=W ; hack[2]++){
                    for(hack[3] = 1 ; hack[3] <=W ; hack[3]++){
                        int pre, now;
                        pre = now = 0;
                        cout << "wh"<<endl;
                        cout << hack[0] << hack[1] << hack[2]<<hack[3]<<endl;


                        for(int i = 0 ; i < N ;i++){
                            
                            now = i;
                            if(now == 0){
                                pre = 0;
                            }
                            else{
                                pre = now - 1;
                            }
                            update_map(pre, now);
                            update_top(W,now);
                            cout << tops[hack[i]] << hack[i] <<endl;
                            
                            crash(now,tops[hack[i]],hack[i]);
                            down(H,W,now);

                        }

                        count_two(N-1,W,H);

                        if(N < 4)  break;
                        
                    }
                    if(N < 3)  break;
                }
                if(N < 2)  break;

            }

        }

        printf("#%d %d\n",test_case,*max_element(count.begin(),count.end()));
        return 0;

    }

}