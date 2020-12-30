#include<iostream>
#include<queue>

using namespace std;

int map[1000][1000];
int check[1000][1000];

void bfs(int rows, int cols, queue<pair<int,int> > &togo){
    int move[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};


    while(!togo.empty()){
        pair<int, int> cur = togo.front();
        togo.pop();

        for(int m = 0 ; m < 4 ; m++){
            int nr = cur.first + move[m][0];
            int nc = cur.second + move[m][1];
            if(nr < 0 || nr >= rows || nc < 0 || nc >= cols)    continue;
            if(check[nr][nc])   continue;

            map[nr][nc] = map[cur.first][cur.second] + 1;

            togo.push(make_pair(nr, nc));
            check[nr][nc] = true;
        }

    }

    return;


}

int main(){
    int rows, cols;
    cin >> cols >> rows;

    int ones = 0;
    queue<pair<int, int> > togo;
    
    for(int r = 0 ; r < rows ; r++){
        for(int c = 0 ; c < cols ; c++){
            cin >> map[r][c];
            if(map[r][c]==-1)   check[r][c] = true;
            else{
                check[r][c] = false;
                if(map[r][c] == 1){
                    togo.push(make_pair(r,c));
                    check[r][c] = true;
                }
            }
        }
    }

    bfs(rows, cols, togo);

    int max = -1;
    for(int r = 0 ; r < rows ; r++){
        for(int c = 0 ; c < cols ; c++){
            if(!check[r][c]){
                cout << -1 << '\n';
                return 0;
            }

            if(map[r][c] > 0 && max < map[r][c]){
                max = map[r][c];
            }
    
        }
    }

    cout << max-1 << '\n';

    return 0;

}


/*
정답을 출력할 때, goal state이 아니면 바로 프로그램을 끝내버려라.

BFS을 시작할 때,
초기 state들을 모두 큐에 push해라 그렇다면 맞닿게 되는 위치를 구할 수 있다.
t -> t+1 큐의 모든 state에 동일하게 적용되기때문이다!!
*/



/*

#include <cstdio>
#include <queue>
using namespace std;
int a[1000][1000];
int d[1000][1000];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main() {
    int n,m;
    scanf("%d %d",&m,&n);
    queue<pair<int,int>> q;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d",&a[i][j]);
            d[i][j] = -1;
            if (a[i][j] == 1) {
                q.push(make_pair(i,j));
                d[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (a[nx][ny] == 0 && d[nx][ny] == -1) {
                    d[nx][ny] = d[x][y] + 1;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (ans < d[i][j]) {
                ans = d[i][j];
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == 0 && d[i][j] == -1) {
                ans = -1;
            }
        }
    }

    printf("%d\n",ans);
    return 0;
}
*/