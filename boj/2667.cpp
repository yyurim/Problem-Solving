#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int map[25][25];
bool check[25][25];


void dfs(int n, int r, int c, int count){
    int move[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    check[r][c] = true;
    map[r][c] = count;

    for(int m = 0 ; m < 4 ; m++){
        int nr = r + move[m][0];
        int nc = c + move[m][1];
        if(nr < 0 || nr >= n || nc < 0 || nc >= n)  continue;
        if(check[nr][nc]) continue;
        dfs(n, nr, nc, count);
    }

    return;
}

int main(){
    int n;
    cin >> n;
    for(int r = 0 ; r < n ; r++){
        string input;
        cin >> input;
        for(int c = 0 ; c < n ; c++){
            map[r][c] = input[c]-'0';
            if(map[r][c])   check[r][c] = false;
            else    check[r][c] = true;
        }
    }
    
    int housenums = 0;
    for(int r = 0 ; r < n ; r++){
        for(int c = 0 ; c < n ; c++){
            if(check[r][c]) continue;
            dfs(n, r, c, ++housenums);

        }
    }

    vector<int> ans(housenums, 0);
    for(int r = 0 ; r < n ; r++){
        for(int c = 0 ; c < n ; c++){
            if(map[r][c] == 0)  continue;
            ans[map[r][c]-1]++;
        }
    }

    sort(ans.begin(), ans.end());

    cout << housenums << '\n';
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << '\n';
    }

    return 0;

}

/*
정답
    플러드필 : 어떤 위치와 연결된 모든 위치를 찾는 알고리즘
    DFS / BFS 모두 사용할 수 있다.
    BFS가 더 직관적인 풀이방법이다.
    나는 DFS로 풀었다.
    DFS로 풀면 연결요소들을 찾으며 연결요소들을 구성하는 요소들의 수를 찾는 것은 어렵다.
    두 단계를 나눠서 진행해라.
    1. 연결요소를 찾는다.
    2. 각 연결요소들을 구성하는 요소들의 수를 찾는다.
*/


/*
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int a[30][30];
int d[30][30];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n;
int ans[25*25];
void dfs(int x, int y, int cnt) {
    d[x][y] = cnt;
    for (int k=0; k<4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
            if (a[nx][ny] == 1 && d[nx][ny] == 0) {
                dfs(nx, ny, cnt);
            }
        }
    }
}
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%1d",&a[i][j]);
        }
    }
    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (a[i][j] == 1 && d[i][j] == 0) {
                dfs(i, j, ++cnt);
            }
        }
    }
    printf("%d\n",cnt);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            ans[d[i][j]]+=1;
        }
    }
    sort(ans+1, ans+cnt+1);
    for (int i=1; i<=cnt; i++) {
        printf("%d\n",ans[i]);
    }
    return 0;
}
*/