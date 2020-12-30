#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int map[50][50];
bool check[50][50];

int main(){
    int n, left,right;
    cin >> n >> left >> right;
    for(int r = 0 ;r < n ; r++){
        for(int c= 0 ; c< n;c++){
            cin >> map[r][c];
        }
    }

    int now = 0;
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int ans = 0;

    while(1){
        bool check_loc[50][50];
        memcpy(check_loc, check, sizeof(check_loc));
        int map_loc[50][50];
        memcpy(map_loc, map, sizeof(map_loc));

        vector<pair<vector<pair<int, int> >, int > > unions;
        for(int r= 0 ;r < n ; r++){
            for(int c= 0 ;c < n ;c++){
                bool happened = false;
                if(check_loc[r][c]) continue;
                check_loc[r][c] = true;

                int sum_loc = 0;
                int num_loc = 0;

                vector<pair<int, int> > forafter;
                queue<pair<int, int> > state;
                forafter.push_back(make_pair(r,c));
                state.push(make_pair(r,c));

                while(!state.empty()){
                    pair<int, int> cur = state.front();
                    state.pop();

                    sum_loc += map[cur.first][cur.second];
                    num_loc++;

                    for(int d = 0 ;d < 4 ;d++){
                        int nr = cur.first + dir[d][0];
                        int nc = cur.second + dir[d][1];
                        if(nr < 0 || nr >= n || nc < 0 || nc >=n || check_loc[nr][nc]){
                            continue;
                        }
                        
                        int dist = abs(map[nr][nc] - map[cur.first][cur.second]);
                        if(dist >= left && dist <= right){
                            check_loc[nr][nc] = true;
                            state.push(make_pair(nr,nc));
                            forafter.push_back(make_pair(nr,nc));
                        }

                    }

                }

                unions.push_back(make_pair(forafter,int(sum_loc/num_loc)));

            }
        }
        


        for(int i = 0 ; i < unions.size();  i++){
            for(int j = 0 ; j < unions[i].first.size() ; j++){
                int r = unions[i].first[j].first;
                int c = unions[i].first[j].second;
                map[r][c] = unions[i].second;
            }
        }

        bool finished = true;
        for(int r = 0 ;r <  n ;r++){
            for(int c = 0 ; c < n ;c++){
                if(map_loc[r][c]!=map[r][c]){
                    finished = false;
                    break;
                }
            }
        }

        if(finished){
            cout<< ans << '\n';
            return 0;
        }
        ans++;
    }

    return 0;

}

/*
문제 읽어 다 맞아놓고 틀리지마
*/