#include <iostream>
using namespace std;

#define MAX_N 20

int map[MAX_N][MAX_N];
int height[MAX_N];

int N,X;

int abs(int a){
    return a>0 ? a: -a;
}

bool is_flat_between(int s, int e){
    if(s<0 || e >= N){
        return false;
    }

    for(int i = s; i < e ; i++){
        if(height[i] != height[i+1]){
            return false;
        }
    }

    return true;
}

bool can_runway(){
    for(int i = 0 ; i < N-1 ;i++){
        if(abs(height[i] - height[i+1]) >= 2){
            return false;
        }
    }

    bool* up_slope = new bool[N];
    bool* down_slope = new bool[N];

    for(int i = 0 ; i < N ;i++){
        up_slope[i] = down_slope[i] = false;
    }

    for(int i = 0 ; i < N-1 ;i++){
        if(height[i] + 1 == height[i+1]){
            int s = i -X +1;
            int e = i;
            if(is_flat_between(s,e)){
                for(int j = s ; j <= e ; j++){
                    up_slope[j] = true;
                }
            }
            else{
                return false;
            }
        }
        else if(height[i] - 1 == height[i+1]){
            int s = i+1;
            int e = i+X;
            if(is_flat_between(s,e)){
                for(int j = s ; j <=e ; j++){
                    down_slope[j] = true;
                }
            }
            else{
                return false;
            }
        }
    }

    for(int i = 0 ; i < N ;i++){
        if(up_slope[i]&&down_slope[i]){
            return false;
        }
    }

    return true;
}

int main(){
    int tc;
    scanf("%d",&tc);
    for(int test_case = 1; test_case <= tc ; test_case++){
        scanf("%d %d",&N,&X);
        for(int r = 0 ; r < N ;r++){
            for(int c = 0 ; c< N ;c++){
                scanf("%d",&map[r][c]);
            }
        }

        int row_count, col_count;
        row_count = col_count = 0;

        for(int r = 0 ; r < N ;r++){
            for(int c = 0 ; c<N ; c++){
                height[c] = map[r][c];
            }

            if(can_runway()){
                row_count++;
            }
        }

        for(int r = 0 ; r < N ;r++){
            for(int c = 0 ; c<N ; c++){
                height[c] = map[c][r];
            }

            if(can_runway()){
                col_count++;
            }
        }
        printf("#%d %d\n",test_case, row_count+col_count);

    }
}