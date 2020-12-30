#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

typedef struct _state{
    int loc[2];
    int num;
    int smell;
    int dir;
}state;

state map[2][20][20];

bool compare_asc(state a, state b){
    if(a.num < b.num){
        return true;
    }
    else{
        return false;
    }
}

bool compare_des(state a, state b){
    if(a.num > b.num){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n,m,k;
    cin >> n >> m >> k;

    vector<state> fishes;
    for(int r = 0 ;r < n ; r++){
        for(int c = 0 ; c < n ;c++){
            cin >> map[0][r][c].num;
            map[0][r][c].loc[0] = r;
            map[0][r][c].loc[1] = c;
            map[0][r][c].dir = -1;
            map[0][r][c].smell = 0;
            if(map[0][r][c].num >= 1){
                map[0][r][c].smell = k;
                fishes.push_back(map[0][r][c]);
            }
        }
    }

    sort(fishes.begin(), fishes.end(),compare_asc);
    for(int i = 0 ; i < m ; i++){
        cin >> fishes[i].dir;
        fishes[i].dir--;
        map[0][fishes[i].loc[0]][fishes[i].loc[1]] = fishes[i];
    }

    vector<vector<vector<int> > > priority(m+1);
    for(int i = 1 ; i <= m ; i++){
        for(int p = 0 ; p < 4 ; p++){
            vector<int> dirs(4);
            cin >> dirs[0] >> dirs[1] >> dirs[2] >> dirs[3];
            dirs[0]--;
            dirs[1]--;
            dirs[2]--;
            dirs[3]--;
            priority[i].push_back(dirs);
        }
    }

    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int time = 0;
    int now = 0;
    while(time < 1000){
        //  sync
        for(int r= 0 ;r < n ; r++){
            for(int c= 0 ;c < n ;c++){
                map[1-now][r][c] = map[now][r][c];
            }
        }
        // move
        sort(fishes.begin(), fishes.end(), compare_des);
        for(int i = 0 ; i < fishes.size() ; i++){
            state cur = fishes[i];
            vector<state> mine;
            bool found = false;
            for(int p = 0 ; p < 4 ; p++){
                int nr = cur.loc[0] + dir[priority[cur.num][cur.dir][p]][0];
                int nc = cur.loc[1] + dir[priority[cur.num][cur.dir][p]][1];
                if(nr < 0 || nr >= n || nc < 0 || nc >=n)   continue;
                if(map[now][nr][nc].num==cur.num){
                    map[1-now][nr][nc].dir = priority[cur.num][cur.dir][p];
                    mine.push_back(map[1-now][nr][nc]);
                    continue;
                }
                else{
                    if(map[now][nr][nc].smell<k&&map[now][nr][nc].smell>0){
                        continue;
                    }
                    else{
                        if(map[now][nr][nc].num==0){
                            cur.dir = priority[cur.num][cur.dir][p];
                            cur.loc[0] = nr;
                            cur.loc[1] = nc;
                            cur.smell = k+1;
                            map[1-now][cur.loc[0]][cur.loc[1]] = cur;
                            found = true;
                            break;
                        }
                    }
                }

            }

            if(found)   continue;
            found = false;
            for(int p = 0;  p < 4 ; p++){
                if(found)   break;
                for(int j = 0 ; j < mine.size() ; j++){
                    if(priority[cur.num][cur.dir][p]==mine[j].dir){
                        cur.dir = mine[j].dir;
                        cur.loc[0] = mine[j].loc[0];
                        cur.loc[1] = mine[j].loc[1];
                        cur.num = mine[j].num;
                        cur.smell = k+1;
                        map[1-now][cur.loc[0]][cur.loc[1]] = cur;
                        found = true;
                        break;
                    }
                }
            }
        }

        for(int r= 0 ;r < n ; r++){
            for(int c= 0 ; c < n ; c++){
                if(map[1-now][r][c].smell > 0){
                    map[1-now][r][c].smell--;  
                    if(map[1-now][r][c].smell==0){
                        map[1-now][r][c].num = 0;
                    }
                }
            }
        }

        // smell down
        // new_fishes
        vector<state> new_fishes;
        for(int r= 0 ;r < n ; r++){
            for(int c= 0 ; c < n ; c++){
                if(map[1-now][r][c].smell==k){
                    new_fishes.push_back(map[1-now][r][c]);
                }
            }
        }
        // cout << "time >> " << time << endl;
        // for(int r= 0 ; r < n ; r++){
        //     for(int c= 0 ; c <n ;c++){
        //         cout << map[1-now][r][c].smell << " ";
        //     }
        //     cout << endl;
        // }
        fishes = new_fishes;
        time++;
        now = 1-now;
        if(fishes.size()<=1){
            // cout << "           only on \n";
            cout << time << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';

    return 0;



    


    

    

}