#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int map[50][50];
int check[50][50];

void dfs(int rows, int cols, int r, int c, int count){
    check[r][c] = true;
    map[r][c] = count;

    int move[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}};
    for(int m = 0 ; m < 8 ; m++){
        int nr = r + move[m][0];
        int nc = c+ move[m][1];
        if(nr < 0 || nr >= rows || nc < 0 || nc >= cols)    continue;
        if(check[nr][nc])   continue;
        dfs(rows, cols, nr, nc, count);
    }

    return;
}

int main(){
    int rows = 0;
    int cols = 0;

    while(1){
        cin >> cols >> rows;
        if(rows == 0 && cols == 0)  break;
        for(int r = 0 ; r < rows ; r++){
            for(int c = 0 ; c < cols ; c++){
                cin >> map[r][c];
                if(map[r][c])   check[r][c] = false;
                else    check[r][c] = true;
            }
        }

        int islands = 0;
        for(int r = 0 ; r < rows ; r++){
            for(int c = 0 ; c < cols ; c++){
                if(check[r][c]) continue;
                dfs(rows, cols, r, c, ++islands);
            }
        }

        
        cout << islands << '\n';

    }

    return 0;

}


/*
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int a[100][100];
int d[100][100];
int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};
int n,m;
void bfs(int x, int y, int cnt) {
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    d[x][y] = cnt;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int k=0; k<8; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (a[nx][ny] == 1 && d[nx][ny] == 0) {
                    q.push(make_pair(nx,ny));
                    d[nx][ny] = cnt;
                }
            }
        }
    }
}
int main() {
    while (true) {
        scanf("%d %d",&m,&n);
        if (n == 0 && m == 0) break;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                scanf("%1d",&a[i][j]);
                d[i][j] = 0;
            }
        }
        int cnt = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j] == 1 && d[i][j] == 0) {
                    bfs(i, j, ++cnt);
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
*/