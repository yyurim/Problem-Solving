#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

typedef struct _state{
    int loc[2];
    int num;
    int dir;
}state;


int dir[8][2] = {{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};

bool compare(state a,  state b){
    if(a.num < b.num){
        return true;
    }
    else{
        return false;
    }
}

int dfs(vector<vector<state> > &map_loc, state shark, int sum){
    vector<state>fishes;
    for(int r= 0 ; r < 4 ; r++){
        for(int c = 0 ; c< 4 ;c++){
            if(map_loc[r][c].num>0){
                fishes.push_back(map_loc[r][c]);
            }
        }
    }
    if(fishes.size() <=0){
        return sum;
    }

    sort(fishes.begin(), fishes.end(), compare);
    for(int i = 0 ; i < fishes.size() ; i++){
        state fish = fishes[i];

        for(int d = 0 ; d < 8 ; d++){
            int nr = fish.loc[0] + dir[(fish.dir+d)%8][0];
            int nc = fish.loc[1] + dir[(fish.dir+d)%8][1];
            if(nr < 0 || nr >=4 || nc < 0 || nc >= 4)   continue;

            if(map_loc[nr][nc].num >=0){
                if(map_loc[nr][nc].num > fish.num){
                    for(int f=  i ; f < fishes.size() ; f++){
                        if(fishes[f].num==map_loc[nr][nc].num){
                            fishes[f].loc[0] = fish.loc[0];
                            fishes[f].loc[1] = fish.loc[1];
                            break;
                        }
                    }
                }
                int temp_num = map_loc[nr][nc].num;
                int temp_dir = map_loc[nr][nc].dir;

                map_loc[nr][nc].num = fish.num;
                map_loc[nr][nc].dir = (fish.dir+d)%8;

                map_loc[fish.loc[0]][fish.loc[1]].num = temp_num;
                map_loc[fish.loc[0]][fish.loc[1]].dir = temp_dir;
                
                break;
            }
        }

    }

    int nr = shark.loc[0];
    int nc = shark.loc[1];
    vector<state> possible;
    while(1){
        nr += dir[shark.dir][0];
        nc += dir[shark.dir][1];
        if(nr < 0 || nr >= 4 || nc < 0 || nc >= 4) break;
        if(map_loc[nr][nc].num == 0)    continue;
        possible.push_back(map_loc[nr][nc]);
    }

    if(possible.size() <= 0){
        return sum;
    }

    int max_sum = sum;
    for(int i = 0 ; i < possible.size() ; i++){
        vector<vector<state> > next_map = map_loc;
        next_map[shark.loc[0]][shark.loc[1]].num = 0;

        int new_sum = sum + possible[i].num;

        state new_shark;
        new_shark.loc[0] = possible[i].loc[0];
        new_shark.loc[1] = possible[i].loc[1];
        new_shark.num = -1;
        new_shark.dir = possible[i].dir;

        next_map[new_shark.loc[0]][new_shark.loc[1]].num = new_shark.num;
        next_map[new_shark.loc[0]][new_shark.loc[1]].dir = new_shark.dir;

        int temp = dfs(next_map, new_shark, new_sum);
        if(temp > max_sum){
            max_sum = temp;
        }
    }

    return max_sum;
}


int main(){
    vector<state> rows(4);
    vector<vector<state> > map(4,rows);
    for(int r = 0 ;r < 4 ; r++){
        for(int c=  0 ; c < 4 ; c++){
            cin >> map[r][c].num >> map[r][c].dir;
            map[r][c].loc[0] = r;
            map[r][c].loc[1] = c;
            map[r][c].dir--;
        }
    }


    // shark init
    state shark;
    int eat = 0;

    shark.dir = map[0][0].dir;
    shark.loc[0] = 0;
    shark.loc[1] = 0;
    eat += map[0][0].num;
    map[0][0].num = -1;      //sharnum -1

    cout << dfs(map,shark,eat) << '\n';

    return 0;
    
}

/*
배열의 요소를 swap 할건데, 그전에 배열 요소로 구성된 벡터를 생성했다.
그리고 벡터 요소들을 iterate시키면서 배열 자체를 swap하여 업데이트했다.
이때 벡터 구성 원소들도 함께 업데이트해주어야한다.
*/