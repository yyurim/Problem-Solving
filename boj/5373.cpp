#include<iostream>
#include<vector>

using namespace std;

// {0:w, 1:y, 2:r, 3:o, 4:g, 5:b}
int cube[2][6][9];

void rotate(int now, int s,char c){
    if(c=='-'){
        cube[1-now][s][0] = cube[now][s][2];
        cube[1-now][s][1] = cube[now][s][5];
        cube[1-now][s][2] = cube[now][s][8];
        cube[1-now][s][3] = cube[now][s][1];
        cube[1-now][s][4] = cube[now][s][4];
        cube[1-now][s][5] = cube[now][s][7];
        cube[1-now][s][6] = cube[now][s][0];
        cube[1-now][s][7] = cube[now][s][3];
        cube[1-now][s][8] = cube[now][s][6];

    }
    else{
        cube[1-now][s][0] = cube[now][s][6];
        cube[1-now][s][1] = cube[now][s][3];
        cube[1-now][s][2] = cube[now][s][0];
        cube[1-now][s][3] = cube[now][s][7];
        cube[1-now][s][4] = cube[now][s][4];
        cube[1-now][s][5] = cube[now][s][1];
        cube[1-now][s][6] = cube[now][s][8];
        cube[1-now][s][7] = cube[now][s][5];
        cube[1-now][s][8] = cube[now][s][2];

    }
    return;
}

int main(){
    int n;
    scanf("%d",&n);
    
    for(int i = 0 ; i < n ; i++){
        int m;
        scanf("%d",&m);
        int color = 0;
        int now = 0;
        for(int r= 0 ; r < 6 ; r++){
            for(int c= 0 ; c < 9 ; c++){
                cube[now][r][c] = color;
                cube[1-now][r][c] = color;
            }
            color++;
        }

        for(int j = 0 ; j < m ; j++){
            for(int r = 0 ; r < 6 ; r++){
                for(int c= 0 ; c < 9 ; c++){
                    cube[1-now][r][c] = cube[now][r][c];
                }
            }
            char inst[3];
            scanf("%s",inst);
            switch(inst[0]){
                //0
                case 'U':
                    rotate(now,0,inst[1]);
                    if(inst[1]=='-'){
                        

                        // 앞 <- 왼
                        cube[1-now][2][0] = cube[now][4][2];
                        cube[1-now][2][1] = cube[now][4][5];
                        cube[1-now][2][2] = cube[now][4][8];

                        // 뒤 <- 오
                        cube[1-now][3][8] = cube[now][5][6];
                        cube[1-now][3][7] = cube[now][5][3];
                        cube[1-now][3][6] = cube[now][5][0];

                        // 왼 <- 뒤
                        cube[1-now][4][2] = cube[now][3][8];
                        cube[1-now][4][5] = cube[now][3][7];
                        cube[1-now][4][8] = cube[now][3][6];

                        // 오 <- 앞
                        cube[1-now][5][6] = cube[now][2][0];
                        cube[1-now][5][3] = cube[now][2][1];
                        cube[1-now][5][0] = cube[now][2][2];
                        
                    }
                    else{

                    
                        // 앞 <- 오
                        cube[1-now][2][0] = cube[now][5][6];
                        cube[1-now][2][1] = cube[now][5][3];
                        cube[1-now][2][2] = cube[now][5][0];

                        // 뒤 <- 왼
                        cube[1-now][3][8] = cube[now][4][2];
                        cube[1-now][3][7] = cube[now][4][5];
                        cube[1-now][3][6] = cube[now][4][8];

                        // 왼 <- 앞
                        cube[1-now][4][2] = cube[now][2][0];
                        cube[1-now][4][5] = cube[now][2][1];
                        cube[1-now][4][8] = cube[now][2][2];

                        // 오 <- 뒤
                        cube[1-now][5][6] = cube[now][3][8];
                        cube[1-now][5][3] = cube[now][3][7];
                        cube[1-now][5][0] = cube[now][3][6];
                    }
                break;
                //1
                case 'D':
                    rotate(now,1,inst[1]);
                    if(inst[1]=='+'){

                        // 앞 <- 왼
                        cube[1-now][2][6] = cube[now][4][0];
                        cube[1-now][2][7] = cube[now][4][3];
                        cube[1-now][2][8] = cube[now][4][6];

                        // 뒤 <- 오
                        cube[1-now][3][2] = cube[now][5][8];
                        cube[1-now][3][1] = cube[now][5][5];
                        cube[1-now][3][0] = cube[now][5][2];

                        // 왼 <- 뒤
                        cube[1-now][4][0] = cube[now][3][2];
                        cube[1-now][4][3] = cube[now][3][1];
                        cube[1-now][4][6] = cube[now][3][0];

                        // 오 <- 앞
                        cube[1-now][5][8] = cube[now][2][6];
                        cube[1-now][5][5] = cube[now][2][7];
                        cube[1-now][5][2] = cube[now][2][8];

                    }
                    else{

                        // 앞 <- 오
                        cube[1-now][2][6] = cube[now][5][8];
                        cube[1-now][2][7] = cube[now][5][5];
                        cube[1-now][2][8] = cube[now][5][2];

                        // 뒤 <- 왼
                        cube[1-now][3][2] = cube[now][4][0];
                        cube[1-now][3][1] = cube[now][4][3];
                        cube[1-now][3][0] = cube[now][4][6];

                        // 왼 <- 앞
                        cube[1-now][4][0] = cube[now][2][6];
                        cube[1-now][4][3] = cube[now][2][7];
                        cube[1-now][4][6] = cube[now][2][8];

                        // 오 <- 뒤
                        cube[1-now][5][8] = cube[now][3][2];
                        cube[1-now][5][5] = cube[now][3][1];
                        cube[1-now][5][2] = cube[now][3][0];
                    }
                break;
                //2
                case 'F':
                    rotate(now,2,inst[1]);
                    if(inst[1]=='-'){

                        // 위 <- 오
                        cube[1-now][0][6] = cube[now][5][6];
                        cube[1-now][0][7] = cube[now][5][7];
                        cube[1-now][0][8] = cube[now][5][8];

                        // 아래
                        cube[1-now][1][6] = cube[now][4][6];
                        cube[1-now][1][7] = cube[now][4][7];
                        cube[1-now][1][8] = cube[now][4][8];

                        // 왼
                        cube[1-now][4][6] = cube[now][0][6];
                        cube[1-now][4][7] = cube[now][0][7];
                        cube[1-now][4][8] = cube[now][0][8];

                        // 오
                        cube[1-now][5][6] = cube[now][1][6];
                        cube[1-now][5][7] = cube[now][1][7];
                        cube[1-now][5][8] = cube[now][1][8];

                    }
                    else{


                        cube[1-now][0][6] = cube[now][4][6];
                        cube[1-now][0][7] = cube[now][4][7];
                        cube[1-now][0][8] = cube[now][4][8];

                        cube[1-now][1][6] = cube[now][5][6];
                        cube[1-now][1][7] = cube[now][5][7];
                        cube[1-now][1][8] = cube[now][5][8];

                        cube[1-now][4][6] = cube[now][1][6];
                        cube[1-now][4][7] = cube[now][1][7];
                        cube[1-now][4][8] = cube[now][1][8];

                        cube[1-now][5][6] = cube[now][0][6];
                        cube[1-now][5][7] = cube[now][0][7];
                        cube[1-now][5][8] = cube[now][0][8];
                    }
                break;
                //3
                case 'B':
                    rotate(now,3,inst[1]);
                    if(inst[1]=='+'){

                        // 위 <- 오
                        cube[1-now][0][0] = cube[now][5][0];
                        cube[1-now][0][1] = cube[now][5][1];
                        cube[1-now][0][2] = cube[now][5][2];

                        // 아래
                        cube[1-now][1][0] = cube[now][4][0];
                        cube[1-now][1][1] = cube[now][4][1];
                        cube[1-now][1][2] = cube[now][4][2];

                        // 왼
                        cube[1-now][4][0] = cube[now][0][0];
                        cube[1-now][4][1] = cube[now][0][1];
                        cube[1-now][4][2] = cube[now][0][2];

                        // 오
                        cube[1-now][5][0] = cube[now][1][0];
                        cube[1-now][5][1] = cube[now][1][1];
                        cube[1-now][5][2] = cube[now][1][2];

                    }
                    else{
                        // 위 <- 왼
                        cube[1-now][0][0] = cube[now][4][0];
                        cube[1-now][0][1] = cube[now][4][1];
                        cube[1-now][0][2] = cube[now][4][2];

                        // 아래
                        cube[1-now][1][0] = cube[now][5][0];
                        cube[1-now][1][1] = cube[now][5][1];
                        cube[1-now][1][2] = cube[now][5][2];

                        // 왼
                        cube[1-now][4][0] = cube[now][1][0];
                        cube[1-now][4][1] = cube[now][1][1];
                        cube[1-now][4][2] = cube[now][1][2];

                        // 오
                        cube[1-now][5][0] = cube[now][0][0];
                        cube[1-now][5][1] = cube[now][0][1];
                        cube[1-now][5][2] = cube[now][0][2];
                    }
                break;
                //4
                case 'L':
                    rotate(now,4,inst[1]);
                    if(inst[1]=='-'){
                        // 위 <- 앞
                        cube[1-now][0][0] = cube[now][2][0];
                        cube[1-now][0][3] = cube[now][2][3];
                        cube[1-now][0][6] = cube[now][2][6];

                        // 아래 <- 뒤
                        cube[1-now][1][8] = cube[now][3][0];
                        cube[1-now][1][5] = cube[now][3][3];
                        cube[1-now][1][2] = cube[now][3][6];

                        // 앞 <- 아래
                        cube[1-now][2][0] = cube[now][1][8];
                        cube[1-now][2][3] = cube[now][1][5];
                        cube[1-now][2][6] = cube[now][1][2];

                        // 뒤 <- 위
                        cube[1-now][3][0] = cube[now][0][0];
                        cube[1-now][3][3] = cube[now][0][3];
                        cube[1-now][3][6] = cube[now][0][6];

                    }
                    else{
                        // 위 <- 뒤
                        cube[1-now][0][0] = cube[now][3][0];
                        cube[1-now][0][3] = cube[now][3][3];
                        cube[1-now][0][6] = cube[now][3][6];

                        // 아래 <- 앞
                        cube[1-now][1][8] = cube[now][2][0];
                        cube[1-now][1][5] = cube[now][2][3];
                        cube[1-now][1][2] = cube[now][2][6];


                        // 앞 <- 위
                        cube[1-now][2][0] = cube[now][0][0];
                        cube[1-now][2][3] = cube[now][0][3];
                        cube[1-now][2][6] = cube[now][0][6];

                        // 뒤 <- 아래
                        cube[1-now][3][0] = cube[now][1][8];
                        cube[1-now][3][3] = cube[now][1][5];
                        cube[1-now][3][6] = cube[now][1][2];
                        
                    }
                break;
                //5
                case 'R':
                    rotate(now,5,inst[1]);
                    if(inst[1]=='-'){
                        // 위 <- 뒤
                        cube[1-now][0][2] = cube[now][3][2];
                        cube[1-now][0][5] = cube[now][3][5];
                        cube[1-now][0][8] = cube[now][3][8];

                        // 아래 <- 앞
                        cube[1-now][1][6] = cube[now][2][2];
                        cube[1-now][1][3] = cube[now][2][5];
                        cube[1-now][1][0] = cube[now][2][8];

                        // 앞 <- 위
                        cube[1-now][2][2] = cube[now][0][2];
                        cube[1-now][2][5] = cube[now][0][5];
                        cube[1-now][2][8] = cube[now][0][8];

                        // 뒤 <- 아래
                        cube[1-now][3][2] = cube[now][1][6];
                        cube[1-now][3][5] = cube[now][1][3];
                        cube[1-now][3][8] = cube[now][1][0];

                    }
                    else{
                        // 위 <- 앞
                        cube[1-now][0][2] = cube[now][2][2];
                        cube[1-now][0][5] = cube[now][2][5];
                        cube[1-now][0][8] = cube[now][2][8];

                        // 아래 <- 뒤
                        cube[1-now][1][6] = cube[now][3][2];
                        cube[1-now][1][3] = cube[now][3][5];
                        cube[1-now][1][0] = cube[now][3][8];

                        // 앞 <- 아래
                        cube[1-now][2][2] = cube[now][1][6];
                        cube[1-now][2][5] = cube[now][1][3];
                        cube[1-now][2][8] = cube[now][1][0];

                        // 뒤 <- 위
                        cube[1-now][3][2] = cube[now][0][2];
                        cube[1-now][3][5] = cube[now][0][5];
                        cube[1-now][3][8] = cube[now][0][8];

                    }
                break;
            }
            now = 1-now;

        }
        for(int i = 0 ; i < 9 ; i++){
            char c;
            switch(cube[now][0][i]){
                
                case 0:
                    c = 'w';
                break;
                case 1:
                    c = 'y';
                break;
                case 2:
                    c = 'r';
                break;
                case 3:
                    c = 'o';
                break;
                case 4:
                    c = 'g';
                break;
                case 5:
                    c = 'b';
                break;
            }
            printf("%c",c);
            if(i%3==2){
                printf("\n");
            }
        }

        
    }

    return 0;
}

/*
이런 하드코딩은 인덱스.........인덱스!!!!!!
*/