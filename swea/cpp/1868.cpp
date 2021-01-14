#include<iostream>
#include<vector>

using namespace std;

char map[302][302];
int check[2][302][302];

int main(){
    int tc;
    scanf("%d",&tc);
    int move[8][2] = {{0,1},{1,1},{0,1},{-1,1},{0,-1},{-1,-1},{-1,0},{1,-1}};
    for(int test_case = 1; test_case <= tc ; test_case++){
        int n;
        scanf("%d",&n);

        for(int r = 0; r < 302 ; r++){
            for(int c = 0; c < 302 ; c++){
                map[r][c] = '.';
                check[0][r][c] = 0;
                check[1][r][c] = 0;
            }
        }

        for(int r = 1; r <=n ; r++){
            for(int c = 1; c<=n ; c++){
                scanf("%c",%map[r][c]);
                if(map[r][c]=='*'){
                    check[0][r][c] = -1;
                    for(int m = 0 ; m < 8 ; m++){
                        int nr = r+move[m][0];
                        int nc = c+move[m][1];
                        if(check[0][nr][nc] == -1)  continue;
                        check[0][nr][nc]++;
                    }
                }
            }
        }

    }
}