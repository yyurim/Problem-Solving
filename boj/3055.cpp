#include<iostream>
#include<queue>

using namespace std;

void bfs(vector<vector<int> > &map, vector<vector<bool> > &check,queue<pair<pair<int, int>, int> > &water){
    int move[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int time;

    while(!water.empty()){
        pair<int, int> now = water.front().first;
        time = water.front().second;

        water.pop();

        for(int i = 0 ; i < 4 ; i++){
            int nr = now.first + move[i][0];
            int nc = now.second + move[i][1];

            if(nr < 0 || nr >= map.size() || nc < 0 || nc >= map[0].size() || check[nr][nc])    continue;
            if(map[nr][nc]==-1) continue;

            check[nr][nc] = true;
            water.push(make_pair(make_pair(nr,nc),time+1));
            map[nr][nc] = time + 1;
        }
    }

    return;

}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> rows(m,0);
    vector<vector<int> > map(n, rows);

    vector<bool> check_rows(m, false);
    vector<vector<bool> > check(n, check_rows);


    pair<int, int> dest;
    pair<int, int> start;

    queue<pair<pair<int, int>, int> > water;
    for(int r = 0 ; r < n ; r++){
        string input;
        cin >> input;
        for(int c = 0 ; c < m ; c++){
            if(input[c]=='*'){
                // map[r][c] = 1;
                
                water.push(make_pair(make_pair(r,c), 0));
                check[r][c] = true;
            }
            else if(input[c]=='X'){
                map[r][c] = -1;
                check[r][c] = true;
            }
            else if(input[c]=='S'){
                start.first = r;
                start.second = c;
            }
            else if(input[c]=='D'){
                map[r][c] = -1;
                check[r][c] = true;
                dest.first = r;
                dest.second = c;

            }
        }
    }
    int water_count = water.size();

    bfs(map, check, water);

    map[dest.first][dest.second] = 987654321;

    bool check_bibier[n][m][3000];

    for(int r = 0 ; r < n ; r++){
        for(int c = 0 ;c < m ; c++){
            if(map[r][c] == 0)  map[r][c] = 987654321;
            for(int k = 0 ; k < 3000 ; k++){
                check_bibier[r][c][k] = false;
            }
        }
    }

    queue<pair<pair<int, int>,int> > visited;
    int time = 0;
    check_bibier[start.first][start.second][time] = true;
    visited.push(make_pair(start,time));

    int move[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    while(!visited.empty()){
        pair<int, int> now = visited.front().first;
        time = visited.front().second;
        visited.pop();

        if(now.first==dest.first && now.second==dest.second){
            cout << time << "\n";
            return 0;
        }

        for(int i = 0 ; i < 4 ; i++){
            int nr = now.first + move[i][0];
            int nc = now.second + move[i][1];

            if(nr < 0 || nr >= map.size() || nc < 0 || nc >= map[0].size() || check_bibier[nr][nc][time+1])    continue;
            if(map[nr][nc]==-1 || map[nr][nc] <= time+1 ) continue;

            check_bibier[nr][nc][time+1] = true;
            visited.push(make_pair(make_pair(nr,nc),time+1));
        }

    }

    cout << "KAKTUS\n";

    return 0;

}

/*
물의 영향을 받지 않은 곳은 여전히 0이다.
갈 수 있음에도 갈 수 없다고하는것
예외 상황...!!!!!!
*/

/*
#include <iostream>
#include <tuple>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
using namespace std;
int water[50][50];
int d[50][50];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    memset(water,-1,sizeof(water));
    queue<pair<int,int>> q;
    int sx,sy,ex,ey;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == '*') {
                q.push(make_pair(i,j));
                water[i][j] = 0;
            } else if (a[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (a[i][j] == 'D') {
                ex = i;
                ey = j;
            }
        }
    }
    while (!q.empty()) {
        int x, y;
        tie(x,y) = q.front(); q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (water[nx][ny] != -1) continue;
            if (a[nx][ny] == 'X') continue;
            if (a[nx][ny] == 'D') continue;
            water[nx][ny] = water[x][y] + 1;
            q.push(make_pair(nx,ny));
        }
    }
    memset(d,-1,sizeof(d));
    q.push(make_pair(sx,sy));
    d[sx][sy] = 0;
    while (!q.empty()) {
        int x, y;
        tie(x,y) = q.front(); q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (d[nx][ny] != -1) continue;
            if (a[nx][ny] == 'X') continue;
            if (water[nx][ny] != -1 && d[x][y]+1 >= water[nx][ny]) continue;
            d[nx][ny] = d[x][y] + 1;
            q.push(make_pair(nx,ny));
        }
    }
    if (d[ex][ey] == -1) {
        cout << "KAKTUS\n";
    } else {
        cout << d[ex][ey] << '\n';
    }
    return 0;
}
*/


















// #include<iostream>
// #include<queue>

// using namespace std;

// #define MAX 50

// int map[MAX][MAX];
// bool check[MAX][MAX];

// int main(){
//     int n,m;
//     cin >> n >> m;

//     queue<pair<int, int> > waters;
//     pair<int, int> start;
//     pair<int, int> dest;

//     for(int r = 0 ; r < n ; r++){
//         string input;
//         cin >> input;
//         for(int c = 0 ; c < m ; c++){
//             char temp = input[c];
//             map[r][c] = 0;
//             check[r][c] = false;
//             if(temp=='*'){
//                 // map[r][c] = 1;
//                 waters.push(make_pair(r,c));
//                 check[r][c] = true;
//             }
//             else if(temp == 'S'){
//                 start = make_pair(r, c);
                
//             }
//             else if(temp == 'D'){
//                 dest = make_pair(r,c);
//                 check[r][c] = true;
//             }
//             else if(temp =='X'){
//                 map[r][c] = -1;
//                 check[r][c] = true;
//             }
//         }
//     }

//     int move[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
//     while(!waters.empty()){
//         pair<int, int> now = waters.front();
//         waters.pop();

//         for(int i = 0 ; i < 4 ; i++){
//             int nr = now.first + move[i][0];
//             int nc = now.second + move[i][1];

//             if(nr < 0 || nr >= n || nc < 0 || nc >= m || check[nr][nc]) continue;

//             check[nr][nc] = true;
//             waters.push(make_pair(nr,nc));
//             map[nr][nc] = map[now.first][now.second] + 1;
//         }
//     }

//     map[dest.first][dest.second] = 987654321;

//     vector<bool> times(10000,false);
//     vector<vector<bool> > rows_check(m, times);
//     vector<vector<vector<bool> > > check_state(n, rows_check);

//     for(int r = 0 ; r < n ; r++){
//         for(int c = 0 ; c < m ; c++){
//             if(map[r][c]==-1){
//                 for(int i = 0 ; i < 10000 ; i++){
//                     check_state[r][c][n] = true;
//                 }
//             }
//         }
//     }


//     queue<pair<pair<int ,int>, int > > biber;
//     int time = 0;
//     check_state[start.first][start.second][time] = true;
//     biber.push(make_pair(start,time));

//     while(!biber.empty()){
//         pair<int, int> now = biber.front().first;
//         time = biber.front().second;
//         // cout << now.first << "   " << now.second << "   " << time << endl;
//         if(now.first == dest.first && now.second == dest.second){
//             cout << time << '\n';
//             return 0;
//         }
//         biber.pop();

//         for(int i = 0 ; i < 4 ; i++){
//             int nr = now.first + move[i][0];
//             int nc = now.second + move[i][1];

//             if(nr < 0 || nr >= n || nc < 0 || nc >= m || check_state[nr][nc][time+1] || map[nr][nc]==-1) continue;

//             if(map[nr][nc] > time+1 ){
//                 check_state[nr][nc][time+1] = true;
//                 biber.push(make_pair(make_pair(nr,nc),time+1));
//             }

            
//         }
        
//     }

//     cout << "KAKTUS";
//     return 0;
    

// }