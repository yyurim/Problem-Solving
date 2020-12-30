#include<iostream>
#include<queue>

using namespace std;

int bfs(vector<vector<int> > &map, vector<vector<bool> > &check, int n, int m){
    deque< pair<pair<int, int>,int > > visited;
    int count = 0;
    check[0][0] = true;
    visited.push_back(make_pair(make_pair(0,0),count));
    
    int move[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    while(!visited.empty()){
        pair<int, int> now = visited.front().first;
        count = visited.front().second;
        
        if(now.first == n-1 && now.second == m-1){
            return count;
        }
        visited.pop_front();

        for(int d = 0 ; d < 4 ; d++){
            int nr = now.first + move[d][0];
            int nc = now.second + move[d][1];
        

            if(nr < 0 || nr >= map.size() || nc < 0 || nc >= map[0].size() || check[nr][nc]) continue;
            check[nr][nc] = true;
            if(map[nr][nc] == 1){
                visited.push_back(make_pair(make_pair(nr, nc), count+1));
            }
            else if(map[nr][nc] == 0){
                visited.push_front(make_pair(make_pair(nr,nc), count));
            }
        }
        

    }

    return count;


}

int main(){
    int n, m;
    cin >> m >> n;

    vector<int> rows(m);
    vector<vector<int> > map(n, rows);
    
    vector<bool> rows_check(m, false);
    vector<vector<bool> > check(n, rows_check);


    for(int r = 0 ; r < n ; r++){
        string input;
        cin >> input;
        for(int c = 0 ; c < m ; c++){
            map[r][c] = input[c] - '0';
        }
    }

    cout << bfs(map, check, n,m) <<'\n';
    return 0;

}


/*
#include <cstdio>
#include <queue>
using namespace std;
int d[555][555];
int a[555][555];
int n,m;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main() {
    scanf("%d %d",&m,&n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d",&a[i][j]);
            d[i][j] = -1;
        }
    }
    queue<pair<int,int>> q;
    queue<pair<int,int>> next_queue;
    q.push(make_pair(0,0));
    d[0][0] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (d[nx][ny] == -1) {
                    if (a[nx][ny] == 0) {
                        d[nx][ny] = d[x][y];
                        q.push(make_pair(nx,ny));
                    } else {
                        d[nx][ny] = d[x][y]+1;
                        next_queue.push(make_pair(nx,ny));
                    }
                }
            }
        }
        if (q.empty()) {
            q = next_queue;
            next_queue = queue<pair<int,int>>();
        }
    }
    printf("%d\n",d[n-1][m-1]);
    return 0;
}
*/