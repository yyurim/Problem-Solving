#include<iostream>
#include<queue>

using namespace std;

int map[1001][1001];
bool check[1001][1001][2];

typedef struct _state{
    pair<int, int> point;
    int path;
    bool used;
}state;

int bfs(int n, int m){
    int move[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    queue<state> visited;
    check[0][0][0] = true;
    state now;
    now.point = make_pair(0,0);
    now.path = 1;
    now.used = false;

    visited.push(now);

    while(!visited.empty()){
        now = visited.front();
        // cout << now.point.first << " " << now.point.second << " " << now.path << endl;
        visited.pop();
        if((now.point.first == n-1) && (now.point.second == m-1) ){
            return now.path;
        }

        for(int i = 0 ; i < 4 ; i++){
            int nr = now.point.first + move[i][0];
            int nc = now.point.second + move[i][1];


            if(nr < 0 || nr >= n || nc < 0 || nc >= m || check[nr][nc][now.used]) continue;
            
            state new_state;
            if(map[nr][nc] == 1){
                if(now.used)    continue;
                check[nr][nc][true] = true;
                new_state.point = make_pair(nr, nc);
                new_state.path = now.path + 1;
                new_state.used = true;
            }
            else if(map[nr][nc] == 0){
                check[nr][nc][now.used] = true;
                new_state.point = make_pair(nr, nc);
                new_state.path = now.path + 1;
                new_state.used = now.used;
            }

            visited.push(new_state);

            
        }

    }

    return -1;
}

int main(){
    int n , m;

    cin >> n >> m;

    for(int r = 0 ; r < n ; r++){
        string input;
        cin >> input;
        for(int c = 0 ; c < m ; c++){
            map[r][c] = input[c]-'0';
            check[r][c][0] = false;
            check[r][c][1] = false;
        }
    }

    cout << bfs(n,m) << '\n';

    return 0;


}


/*
정답
    벽을 부수고 해당 점에 도달한 것과 부수지 않고 도달한 것은 다른 경우이다!!!!!!!!!
    state이 뭔지 해당 state이었던 적이 있는지를 확인해야하는것
*/


/*
#include <iostream>
#include <queue>
#include <cstdio>
#include <tuple>
using namespace std;
int a[1000][1000];
int d[1000][1000][2];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main() {
    int n, m;
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d",&a[i][j]);
        }
    }
    queue<tuple<int,int,int>> q;
    d[0][0][0] = 1;
    q.push(make_tuple(0,0,0));
    while (!q.empty()) {
        int x, y, z;
        tie(x,y,z) = q.front(); q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (a[nx][ny] == 0 && d[nx][ny][z] == 0) {
                d[nx][ny][z] = d[x][y][z] + 1;
                q.push(make_tuple(nx,ny,z));
            }
            if (z == 0 && a[nx][ny] == 1 && d[nx][ny][z+1] == 0) {
                d[nx][ny][z+1] = d[x][y][z] + 1;
                q.push(make_tuple(nx,ny,z+1));
            }
        }
    }
    if (d[n-1][m-1][0] != 0 && d[n-1][m-1][1] != 0) {
        cout << min(d[n-1][m-1][0], d[n-1][m-1][1]);
    } else if (d[n-1][m-1][0] != 0) {
        cout << d[n-1][m-1][0];
    } else if (d[n-1][m-1][1] != 0) {
        cout << d[n-1][m-1][1];
    } else {
        cout << -1;
    }
    cout << '\n';
    return 0;
}
*/