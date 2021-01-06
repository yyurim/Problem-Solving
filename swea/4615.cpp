#include<iostream>

/*
***************************************

초기화!!!!!!!!

시작 점이 어디니? 프로그램상 원점 -> 좌상
              직관적인 원점 -> 좌하


***************************************
*/

using namespace std;

int main(){
    int move[2][8] = {{0, 1, 1, 1, 0, -1, -1 ,-1},{1, 1, 0, -1, -1, -1, 0, 1}};
    int t;
    scanf("%d",&t);
    for(int test_case = 1; test_case <= t ; test_case++){
        int N, M;
        scanf("%d %d",&N, &M);
        int board[N+4][N+4];
        
        for(int i = 0 ; i < N+4 ; i++){
            for(int j = 0 ; j < N+4 ; j++){
                board[i][j] = 0;
            }
        }
        board[1+(N/2)][1+(N/2)] = 2;
        board[2+(N/2)][2+(N/2)] = 2;
        board[2+(N/2)][1+(N/2)] = 1;
        board[1+(N/2)][2+(N/2)] = 1;
        
        for(int l = 0 ; l < M ; l++){
            int r, c, p;
            scanf("%d %d %d",&c, &r, &p);
            r--;
            c--;
            board[2+r][2+c] = p;

            for(int m = 0 ; m < 8 ; m++){             
                if(board[2+r+move[0][m]][2+c+move[1][m]] != p && board[2+r+move[0][m]][2+c+move[1][m]] != 0){
                    int i = 1;
                    int count = 0;
                    while(board[2+r+i*move[0][m]][2+c+i*move[1][m]] !=p && board[2+r+i*move[0][m]][2+c+i*move[1][m]] != 0){
                        count++;
                        i++;
                    }

                    if(board[2+r+i*move[0][m]][2+c+i*move[1][m]]==p){
                        for(int flip = 1 ; flip <= count ; flip++){
                            board[2+r+flip*move[0][m]][2+c+flip*move[1][m]] = p;
                        }                     
                    }
                   
                }          
            }                
        }
        int b = 0;
        int w = 0;
        for(int i = 0 ; i < N+4 ; i++){
            for(int j = 0 ; j < N+4 ; j++){
                if(board[i][j]==1)
                    b++;
                else if(board[i][j]==2)
                    w++;
            }
        }
        printf("#%d %d %d\n", test_case, b, w);
    }
}