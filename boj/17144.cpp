#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int map[50][50];

typedef struct _state{
    int val;
    int r;
    int c;
    int t;
}state;

int main(){
    int n,m,t;
    cin >> n >> m >> t;

    int air[2][2] = {-1,-1,-1,-1};
    queue<state> visit;
    for(int r = 0 ; r < n ; r++){
        for(int c= 0 ; c < m ; c++){
            cin >> map[r][c];
            if(map[r][c] > 0 ){
                state s;
                s.val = map[r][c];
                s.r = r;
                s.c = c;
                s.t = 0;
                visit.push(s);
            }
            else if(map[r][c]==-1){
                if(air[0][0]==-1){
                    air[0][0] = r;
                    air[0][1] = c;
                }
                else{
                    air[1][0] = r;
                    air[1][1] = c;
                }
            }
        }
    }

    for(int i = 0; i < t ; i++){
    
        int move[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
        while(!visit.empty()){
            state cur = visit.front();
            visit.pop();

            // int count = 0;
            for(int d = 0 ; d < 4 ; d++){
                int nr = cur.r + move[d][0];
                int nc = cur.c + move[d][1];
                if(nr < 0 || nr >= n || nc < 0 || nc >=m){
                    continue;
                }
                if(map[nr][nc]==-1){
                    continue;
                }
                // count++;
                map[nr][nc] += int(cur.val/5);
                map[cur.r][cur.c] -= int(cur.val/5);

            }

        }

        for(int r = air[0][0] ; r > 0 ; r--){
            if(r == air[0][0]){
                map[r][0] = -1;
            }
            else{
                map[r][0] = map[r-1][0];
            }
        }

        for(int c = 0 ; c < m-1 ; c++){
            map[0][c] = map[0][c+1];
        }

        for(int r = 0 ; r < air[0][0] ; r++){
            map[r][m-1] = map[r+1][m-1];
        }

        for(int c = m-1 ; c > 0 ; c--){
            if(c-1==0){
                map[air[0][0]][c] = 0;
            }
            else{
                map[air[0][0]][c] = map[air[0][0]][c-1];
            }
        }

        for(int r = air[1][0] ; r < n-1  ; r++){
            if(r == air[1][0]){
                map[r][0] = -1;
            }
            else{
                map[r][0] = map[r+1][0];
            }
        }

        for(int c = 0 ; c < m-1 ; c++){
            map[n-1][c] = map[n-1][c+1];
        }
        
        for(int r = n-1 ; r >= air[1][0] ; r--){
            map[r+1][m-1] = map[r][m-1];
        }

        for(int c = m-1 ; c > 0 ; c--){
            if(c-1==0){
                map[air[1][0]][c] = 0;
            }
            else{
                map[air[1][0]][c] = map[air[1][0]][c-1];
            }
        }

        map[air[1][0]][0] = -1;

        for(int r = 0 ;r < n ; r++){
            for(int c= 0 ;c < m ; c++){
                if(map[r][c] > 0){
                    state togo;
                    togo.val = map[r][c];
                    togo.r = r;
                    togo.c = c;
                    togo.t = i+1;
                    visit.push(togo);
                }
                // cout << map[r][c] << ' ';
            }
            // cout <<endl;
        }
        // cout << endl;

    }
    
    


    int ans = 0;
    for(int r= 0 ; r < n ; r++){
        for(int c= 0 ; c< m ; c++){
            if(map[r][c]==-1){
                continue;
            }
            ans += map[r][c];
        }
    }

    cout << ans << '\n';

    return 0;

}