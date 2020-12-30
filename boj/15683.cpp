#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int map[8][8];
int check[8][8];
int check_loc[8][8];

typedef struct _state{
    int loc[2];
    int type;
    int dir_type;
}state;

int dir1[4][1][2] = {{{0,1}},{{-1,0}},{{0,-1}},{{1,0}}};
int dir2[2][2][2] = {{{0,1},{0,-1}},{{-1,0},{1,0}}};
int dir3[4][2][2] = {{{0,1},{-1,0}},{{-1,0},{0,-1}},{{0,-1},{1,0}},{{1,0},{0,1}}};
int dir4[4][3][2] = {{{0,1},{-1,0},{0,-1}},{{-1,0},{0,-1},{1,0}},{{0,1},{0,-1},{1,0}},{{0,1},{-1,0},{1,0}}};
int dir5[1][4][2] = {{{0,1},{-1,0},{0,-1},{1,0}}};

void dfs(int n, int m, pair<int, int> now,int cctv_type,int dir_type, int head){
    if(now.first < 0 || now.first >=n || now.second < 0 || now.second >= m || map[now.first][now.second]==6){
        return;
    }

    check_loc[now.first][now.second] = cctv_type;
    int nr,nc;
    switch(cctv_type){
        case 1:
            nr = now.first + dir1[dir_type][head][0];
            nc = now.second + dir1[dir_type][head][1];
            break;
        case 2:
            nr = now.first + dir2[dir_type][head][0];
            nc = now.second + dir2[dir_type][head][1];
            break;
        case 3:
            nr = now.first + dir3[dir_type][head][0];
            nc = now.second + dir3[dir_type][head][1];
            break;
        case 4:
            nr = now.first + dir4[dir_type][head][0];
            nc = now.second + dir4[dir_type][head][1];
            break;
        case 5:
            nr = now.first + dir5[dir_type][head][0];
            nc = now.second + dir5[dir_type][head][1];
            break;
        default:
            cout << " no such cctv\n";
            break;
    }

    dfs(n, m, make_pair(nr,nc),cctv_type, dir_type, head);

    return;
}

void light(int n, int m, vector<state> &cctv, int idx){
    if(idx >= cctv.size()){
        return;
    }
    state now = cctv[idx];
    int h_max;
    switch(now.type){
        case 1:
            h_max = 1;
            break;
        case 2:
            h_max = 2;
            break;
        case 3:
            h_max = 2;
            break;
        case 4:
            h_max = 3;
            break;
        case 5:
            h_max = 4;
            break;
    }
    for(int h = 0 ; h < h_max ; h++){
        dfs(n, m, make_pair(now.loc[0],now.loc[1]),now.type,now.dir_type,h);
    }
    light(n,m,cctv,idx+1);
    return;
}

void bruteforce(vector<vector<int> > &total, vector<int> &now_permute,vector<state> &cctv, int idx){
    if(idx >= cctv.size()){
        total.push_back(now_permute);
        return;
    }
    state now = cctv[idx];
    int dir_max;
    switch(now.type){
        case 1:
            dir_max = 4;
            break;
        case 2:
            dir_max = 2;
            break;
        case 3:
            dir_max = 4;
            break;
        case 4:
            dir_max = 4;
            break;
        case 5:
            dir_max = 1;
            break;
    }
    for(int d = 0 ;d < dir_max ; d++){
        now_permute[idx] = d;
        bruteforce(total,now_permute,cctv,idx+1);
    }

    return;
    

}

int main(){
    int n,m;
    cin >> n >> m;

    vector<state> cctv;
    for(int r= 0 ; r <  n ;r++){
        for(int c= 0 ; c< m ; c++){
            cin >> map[r][c];
            check[r][c] = map[r][c];
            if(map[r][c]>0 && map[r][c] < 6){
                state tv;
                tv.loc[0] = r;
                tv.loc[1] = c;
                tv.type = map[r][c]; 
                tv.dir_type = 0; 
                cctv.push_back(tv);
            }
        }
    }

    vector<vector<int> > total;
    vector<int> now_permute(cctv.size());

    bruteforce(total,now_permute,cctv,0);

    int min = n*m;
    for(int i = 0 ; i < total.size() ; i++){
        memcpy(check_loc, check, sizeof(check));

        vector<int> now_total = total[i];
        for(int j = 0; j < cctv.size() ; j++){
            cctv[j].dir_type = now_total[j];
        }

        light(n,m,cctv,0);
        int temp = 0;
        for(int r= 0 ;r < n ; r++){
            for(int c= 0 ; c< m  ;c++){
                if(check_loc[r][c]==0)  temp++;
            }
        }
        if(temp < min){
            min = temp;
        }
    }

    cout << min << '\n';

    return 0;

}

/*
방향 만들때 복사하지말고 되도록 직접 쳐서해
*/