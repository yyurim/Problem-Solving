#include<iostream>
#include<vector>

using namespace std;

int map[20][20];
int dice[2][7];
int state[7];

int main(){
    int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};

    
    int n, m, x, y, k;
    cin >> n >> m >> y >> x >> k;
    

    for(int r= 0 ; r < n ; r++){
        for(int c= 0; c< m ; c++){
            cin >> map[r][c];
        }
    }

    vector<int> inst(k);
    for(int i = 0  ; i < k ; i++){
        cin >> inst[i];
        inst[i]--;
    }

    int now = 0;
    for(int i = 0 ; i < k ; i++){
        
        int nx = x + dir[inst[i]][1];
        int ny = y + dir[inst[i]][0];
        if(nx < 0 || nx >= m || ny < 0 || ny >=n )  continue;
        x = nx;
        y = ny;

        if(inst[i]==0){
            dice[1-now][1] = dice[now][4];
            dice[1-now][2] = dice[now][2];
            dice[1-now][3] = dice[now][1];
            dice[1-now][4] = dice[now][6];
            dice[1-now][5] = dice[now][5];
            dice[1-now][6] = dice[now][3];
        }
        else if(inst[i]==1){
            dice[1-now][1] = dice[now][3];
            dice[1-now][2] = dice[now][2];
            dice[1-now][3] = dice[now][6];
            dice[1-now][4] = dice[now][1];
            dice[1-now][5] = dice[now][5];
            dice[1-now][6] = dice[now][4];
        }
        else if(inst[i]==3){
            dice[1-now][1] = dice[now][2];
            dice[1-now][2] = dice[now][6];
            dice[1-now][3] = dice[now][3];
            dice[1-now][4] = dice[now][4];
            dice[1-now][5] = dice[now][1];
            dice[1-now][6] = dice[now][5];
        }
        else if(inst[i]==2){
            dice[1-now][1] = dice[now][5];
            dice[1-now][2] = dice[now][1];
            dice[1-now][3] = dice[now][3];
            dice[1-now][4] = dice[now][4];
            dice[1-now][5] = dice[now][6];
            dice[1-now][6] = dice[now][2];
        }

        if(map[y][x]==0){
            map[y][x] = dice[1-now][6];
        }
        else{
            dice[1-now][6] = map[y][x];
            map[y][x] = 0;
        }

        cout << dice[1-now][1] << '\n';
        now = 1-now;
        

    }

    return 0;

}