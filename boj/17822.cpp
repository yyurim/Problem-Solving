#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

int map[2][50][50];
bool check[50][50];

int main(){
    int n ,m ,t;
    cin >> n >> m >> t;
    for(int r = 0 ; r< n ;r++){
        for(int c= 0 ; c < m ;c++){
            cin >> map[0][r][c];
        }
    }

    vector<int> inst_loc(3);
    vector<vector<int> > inst(t, inst_loc);
    for(int i = 0 ; i < t ; i++){
        cin >> inst[i][0] >> inst[i][1] >> inst[i][2];
    }

    int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
    int now = 0;
    for(int i = 0 ; i < t ; i++){
        //sync
        for(int r= 0 ; r < n ; r++){
            for(int c= 0 ; c< m ; c++){
                map[1-now][r][c] = map[now][r][c];
            }
        }

        // rotate
        for(int r = 0 ; r < n ; r++){
            int lev_loc = r+1;
            if((lev_loc%inst[i][0])==0){
                if(inst[i][1]){
                    // counter clock
                    for(int c = 0 ; c < m ; c++){
                        if(c-inst[i][2] < 0){
                            map[1-now][r][(c-inst[i][2]+m)%m] = map[now][r][c];
                        }
                        else{
                            map[1-now][r][(c-inst[i][2])%m] = map[now][r][c];
                        }
                    }
                }
                else{
                    for(int c = 0 ; c < m ;c++){
                        map[1-now][r][(c+inst[i][2])%m] = map[now][r][c];
                    }
                }
                
            }
        }

        cout << "rotate !!!" << endl;
        for(int r= 0 ; r < n ;r++){
            for(int c = 0 ; c < m ; c++){
                cout << map[1-now][r][c] << " " ;
            }
            cout << endl;
        }
        cout << "                !!!" << endl;
        //sync for same cols
        for(int r= 0 ; r < n ; r++){
            for(int c= 0 ; c< m ; c++){
                map[now][r][c] = map[1-now][r][c];
            }
        }

        bool no = true;
        for(int c = 0 ; c  < m ; c++){
            for(int r = 0 ;r < n ; r++){
                if(map[now][r][c]==0)   continue;
                bool check_loc[50][50];
                memcpy(check_loc, check, sizeof(check_loc));

                int look = map[now][r][c];
                queue<pair<int ,int> > visit;
                visit.push(make_pair(r,c));

                while(!visit.empty()){
                    pair<int, int> cur = visit.front();
                    visit.pop();
                    
                    for(int d = 0 ; d < 4 ; d++){
                        int nr = cur.first + dir[d][0];
                        int nc = cur.second + dir[d][1];

                        if(nr <0 || nr >= n)    continue;
                        if(nc <0){
                            nc = m-nc;
                        }
                        else if(nc >=m){
                            nc = nc-m;
                        }
                        if(check_loc[nr][nc])   continue;
                        if(map[now][nr][nc] != look)    continue;
                        check_loc[nr][nc] = true;
                        visit.push(make_pair(nr,nc));
                        map[1-now][nr][nc] = 0;
                        no = false;
                    }
                }
            }
        }

        int sum_loc = 0;
        int count_loc = 0;
        if(no){
            for(int r= 0 ; r < n ;r++){
                for(int c = 0 ; c < m ; c++){
                    if(map[1-now][r][c]>0){
                        sum_loc += map[1-now][r][c];
                        count_loc++;
                    }
                    cout << map[1-now][r][c] << " " ;
                }
                cout << endl;
            }

            float avg = sum_loc/count_loc;

            for(int r = 0 ; r < n ;r++){
                for(int c=  0 ; c< m ;c++){
                    if(map[1-now][r][c] >0){
                        if(map[1-now][r][c] > avg){
                            map[1-now][r][c]--;
                        }
                        else if(map[1-now][r][c] < avg){
                            map[1-now][r][c]++;
                        }
                    }
                }
            }
        }

        for(int r= 0 ; r < n ;r++){
            for(int c = 0 ; c < m ; c++){
                cout << map[1-now][r][c] << " " ;
            }
            cout << endl;
        }

        now = 1-now;

    }

    int sum = 0;
    int count = 0;
    for(int r= 0 ;r < n ; r++){
        for(int c= 0 ; c< m ; c++){
            sum += map[now][r][c];
        }
    }

    cout << sum << '\n';

    return 0;



}