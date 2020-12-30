#include<iostream>
#include<queue>
#include<utility>

using namespace std;

int map[100][100];
int check[100][100];

void bfs(int rows, int cols, int r, int c){
    int move[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    queue<pair<int, int> > togo;
    check[r][c] = true;
    togo.push(make_pair(r,c));

    while(!togo.empty()){
        pair<int, int> cur = togo.front();
        check[cur.first][cur.second] = true;
        togo.pop();

        for(int m = 0 ; m < 4 ; m++){
            int nr = cur.first + move[m][0];
            int nc = cur.second + move[m][1];
            if(nr < 0 || nr >= rows || nc < 0 || nc >= cols)    continue;
            if(check[nr][nc])   continue;

            map[nr][nc] = map[cur.first][cur.second] + 1;

            check[nr][nc] = true;
            togo.push(make_pair(nr,nc));
        }
    }

    return;

}

int main(){
    int n , m;
    cin >> n >> m;
    for(int r = 0 ; r < n ; r++){
        string input;
        cin >> input;
        for(int c = 0 ; c < m ; c++){
            map[r][c] = input[c]-'0';
            if(map[r][c])   check[r][c] = false;
            else    check[r][c] = true;
        }
    }

    bfs(n, m, 0, 0);
    cout << map[n-1][m-1] << '\n';

    return 0;

}


/*
정답
    BFS는 큐에 push할 때!!!!! 방문했음을 체크해야한다.
    push와 체크는 단일 블락이라 생각해라!!!!!!!!!
*/


/*
#include <cstdio>
#include <queue>
using namespace std;
int n,m;
int a[100][100];
bool check[100][100];
int dist[100][100];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main() {
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d",&a[i][j]);
        }
    }
    queue<pair<int,int>> q;
    q.push(make_pair(0, 0));
    check[0][0] = true;
    dist[0][0] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (check[nx][ny] == false && a[nx][ny] == 1) {
                    q.push(make_pair(nx, ny));
                    dist[nx][ny] = dist[x][y] + 1;
                    check[nx][ny] = true;
                }
            }
        }
    }
    printf("%d\n",dist[n-1][m-1]);
    return 0;
}
*/