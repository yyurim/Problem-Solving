#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

int map[20][20];
bool check[20][20];
bool check_loc[20][20];

typedef struct _state{
    int loc[2];
    int size;
    int dist;
}state;

bool compare(state a, state b){
    if(a.dist < b.dist){
        return true;
    }
    else if(a.dist > b.dist){
        return false;
    }
    else{
        if(a.loc[0] < b.loc[0]){
            return true;
        }
        else if(a.loc[0] > b.loc[0]){
            return false;
        }
        else{
            if(a.loc[1] < b.loc[1]){
                return true;
            }
            else{
                return false;
            }
        }
    }

}

bool bfs(int n, state shark, vector<state> &fishes, int idx){
    int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
    state now = fishes[idx];

    queue<pair<state, int> > visit;
    int count = 0;
    visit.push(make_pair(shark,count));
    while(!visit.empty()){
        state cur = visit.front().first;
        int now_count = visit.front().second;
        visit.pop();

        if((cur.loc[0]==fishes[idx].loc[0]) && (cur.loc[1]==fishes[idx].loc[1])){
            fishes[idx].dist = cur.dist;
            return true;
        }

        for(int d= 0 ; d < 4 ; d++){
            int nr = cur.loc[0] + dir[d][0];
            int nc = cur.loc[1] + dir[d][1];
            if(nr < 0 || nr>= n || nc < 0 || nc >= n || check_loc[nr][nc])  continue;

            state new_state;
            int new_count = now_count;
            int new_size = cur.size;

            if(map[nr][nc] > cur.size)  continue;
            else if(map[nr][nc] < cur.size && map[nr][nc]>0){
                new_count++;
                if((new_count)==cur.size){
                    new_size++;
                }
            }

            check_loc[nr][nc] = true;

            new_state.loc[0] = nr;
            new_state.loc[1] = nc;
            new_state.dist = cur.dist+1;
            new_state.size = new_size;

            visit.push(make_pair(new_state,new_count));
            
        }
    }

    fishes[idx].dist = 987654321;
    return false;
}

int main(){
    int n;
    cin >> n;

    state shark;
    vector<state> fishes;
    for(int r= 0 ;r < n ;r++){
        for(int c = 0 ; c < n ;c++){
            cin >> map[r][c];
            if(map[r][c] < 9 && map[r][c] > 0){
                state new_state;
                new_state.loc[0] = r;
                new_state.loc[1] = c;
                new_state.size = map[r][c];
                new_state.dist = 987654321;
                fishes.push_back(new_state);
            }
            else if(map[r][c]==9){
                shark.loc[0] = r;
                shark.loc[1] = c;
                shark.size = 2;
                shark.dist = 0;

            }
        }
    }

    int count = 0;
    int time = 0;
    while(!fishes.empty()){
        vector<int> eat;
        for(int i = 0 ; i < fishes.size() ; i++){
            if(fishes[i].size < shark.size){
                memcpy(check_loc, check, sizeof(check_loc));
                check_loc[shark.loc[0]][shark.loc[1]] = true;
                if(bfs(n,shark, fishes, i)){
                    eat.push_back(i);
                }
            }
            else{
                fishes[i].dist = 987654321;
            }
        }

        if(eat.size() <=0){
            cout << time << endl;
            return 0;
        }
        if(eat.size() == 1){
            count++;
            if(shark.size == count){
                count = 0;
                shark.size++;
            }

            map[shark.loc[0]][shark.loc[1]] = 0;
            map[fishes[eat[0]].loc[0]][fishes[eat[0]].loc[1]] = 0;
            

            time += fishes[eat[0]].dist;
            shark.loc[0] = fishes[eat[0]].loc[0];
            shark.loc[1] = fishes[eat[0]].loc[1];
            shark.dist = 0;
            fishes.erase(fishes.begin()+eat[0]);
            map[shark.loc[0]][shark.loc[1]] = 9;
        }else{
            
            sort(fishes.begin(), fishes.end(), compare);
            if(fishes.front().dist==987654321){
                cout << time << endl;
                return 0;
            }

            count++;
            if(shark.size == count){
                count = 0;
                shark.size++;
            }

            map[shark.loc[0]][shark.loc[1]] = 0;
            map[fishes[0].loc[0]][fishes[0].loc[1]] = 0;
            time += fishes[0].dist;
            shark.loc[0] = fishes[0].loc[0];
            shark.loc[1] = fishes[0].loc[1];
            shark.dist = 0;
            fishes.erase(fishes.begin());

            map[shark.loc[0]][shark.loc[1]] = 9;
        }
    }
    
    cout << time << '\n';

    return 0;

}

/*
아기 상어가 물고기를 먹을 조건 물고기는 0이 아니다
*/

