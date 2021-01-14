#include<iostream>

using namespace std;

int N, W, H;
int answer;

int init[15][12];

int map[15][12];

void ans(){
    answer = 987654321;
}

void block_init(){
    for(int r = 0 ; r < H ; r++){
        for(int c = 0 ; c < W ;c++){
            map[r][c] = init[r][c];
        }
    }
}

int bomb_1(){
    for(int r = 0 ; r < H ; r++){
        for(int c = 0 ; c < W ; c++){
            if(map[r][c] > 10){
                int d = map[r][c] - 10;
                map[r][c] = 0;
                int sx = c - d + 1;
                int ex = c + d - 1 ;
                if(sx < 0 ) sx = 0;
                if(ex >= W ) ex = W-1;

                int flag = 0;

                for(int x = sx ; x <= ex ; x++){
                    if(map[r][x] == 1)  map[r][x] = 0;
                    else if(map[r][x] > 1 && map[r][x] < 10){
                        map[r][x] += 10;
                        flag = 1;
                    }
                }

                int sy = r - d + 1;
                int ey = r + d - 1 ;
                if(sy < 0 ) sy = 0;
                if(ey >= H ) ey = H-1;
                for(int y = sy ; y <= ey ; y++){
                    if(map[y][c] == 1)  map[y][c] = 0;
                    else if(map[y][c] > 1 && map[y][c] < 10){
                        map[y][c] += 10;
                        flag = 1;
                    }
                }

                if(flag) return 1;
            }
        }
    }

    return 0;
}

void bomb(int x){
    for(int y = 0 ; y < H ;y++){
        if(map[y][x] == 1){
            map[y][x] = 0;
            return;
        }
        else if(map[y][x]>1){
            map[y][x] += 10;
            break;
        }
    }
    int flag = 1;

    while(flag) flag = bomb_1();
    
}

void down(){

    for(int c = 0 ; c < W ; c++){
        for(int r = H-1; r >=0; r--){

            if(map[r][c]==0){
                for(int nr = r-1 ; nr >=0 ; nr--){
                    if(map[nr][c] > 0){
                        map[r][c] = map[nr][c];
                        map[nr][c] = 0;
                        break;
                    }                    
                }
            }
        }
    }
}

void block_check(){
    int cnt = 0 ;
    for(int r = 0 ; r < H ;r++){
        for(int c = 0 ; c < W ; c++){
            if(map[r][c] > 0) cnt++;
        }
    }

    if(answer > cnt) answer = cnt;
}

void solve(){
    int B[4];
    for(B[0] = 0 ; B[0] < W ;B[0]++){
        for(B[1] = 0 ; B[1] < W ;B[1]++){
            for(B[2] = 0 ; B[2] < W ;B[2]++){
                for(B[3] = 0 ; B[3] < W ;B[3]++){
                    block_init();
                    for(int i = 0 ; i < N ;i++){
                        bomb(B[i]);
                        down();
                    }
                    block_check();
                    if(answer == 0) return;
                    if( N < 4)  break;

                }
                if( N < 3)  break;
            }
            if( N < 2)  break;
        }
    }
}

int main(){
    int tc;
    scanf("%d",&tc);
    for(int test_case = 1;  test_case <= tc ; test_case++){
        scanf("%d %d %d",&N, &W, &H);
        for(int r = 0 ; r < H ;r++){
            for(int c = 0 ; c < W ; c++){
                scanf("%d",&init[r][c]);
            }
        }

        ans();
        solve();

        printf("#%d %d\n",test_case, answer);
    }
}