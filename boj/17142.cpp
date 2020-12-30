#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

int map[50][50];
bool virus_check[50][50];
int exp[50][50];
bool check[50][50];

int main(){
    int n, m;
    cin >> n >> m;

    vector<pair<int, int> > virus;
    int safe = 0;
    for(int r= 0 ; r < n ; r++){
        for(int c = 0 ; c < n ; c++){
            cin >> map[r][c];
            if(map[r][c]==2){
                virus.push_back(make_pair(r,c));
                virus_check[r][c] = true;
            }
            else if(map[r][c]==1){
                virus_check[r][c] = true;
            }
            else{
                virus_check[r][c] = false;
                safe++;
            }
        }
    }

    vector<bool> permutation(virus.size()-m,0);
    for(int i = 0 ; i < m ; i++){
        permutation.push_back(1);
    }

    int min = 987654321;    
    do{
        int safe_loc = safe;
        memcpy(exp, map, sizeof(exp));
        memcpy(check, virus_check, sizeof(check));

        queue<pair<int, int> > active;
        for(int i = 0 ; i < permutation.size() ; i++){
            if(permutation[i]){
                active.push(virus[i]);
            }
            else{
                exp[virus[i].first][virus[i].second] = 3;
                check[virus[i].first][virus[i].second] = false;
            }
        }

        int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

        int time=0;
        while(!active.empty()){
            if(safe_loc==0){
                if(time < min){
                    min = time;
                }
                break;
            };

            queue<pair<int, int> > next;
            while(!active.empty()){
                pair<int, int> cur = active.front();
                active.pop();

                for(int d = 0 ; d < 4 ; d++){
                    int nr = cur.first + dir[d][0];
                    int nc = cur.second + dir[d][1];

                    if(nr < 0 || nr >= n || nc < 0 || nc >= n || check[nr][nc]){
                        continue;
                    }

                    check[nr][nc] = true;
                    next.push(make_pair(nr,nc));
                    if(exp[nr][nc]==0)  safe_loc--;
                    exp[nr][nc] = 2;
                                 
                }

            }
            time++;

            active = next;          
        }

    }while(next_permutation(permutation.begin(), permutation.end()));

    if(min >= n*n){
        cout << -1 << '\n';
    }
    else{
        cout << min << '\n';
    }

    return 0;

    
}

/*
문제에서 요구하는 것
진짜 안되면 무식한 방법 써도 돼
*/