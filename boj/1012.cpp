#include<iostream>
#include<queue>

using namespace std;

vector<int> rows(50, 0);
vector<vector<int> > map(50, rows);

vector<bool> check_rows(50,false);
vector<vector<bool> > check(50, check_rows);

int bfs(int n, int m, int sr, int sc){
    queue<pair<int, int> > visited;
    visited.push(make_pair(sr,sc));
    check[sr][sc] = true;

    int move[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    while(!visited.empty()){
        pair<int, int> now = visited.front();
        visited.pop();

        for(int i = 0 ; i < 4 ; i++){
            int nr = now.first + move[i][0];
            int nc = now.second + move[i][1];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m || check[nr][nc]) continue;

            if(map[nr][nc]){
                check[nr][nc] = true;
                visited.push(make_pair(nr, nc));
            }
            
        }

    }

    return 1;

}

int main(){
    int tc;
    cin >> tc;

    for(int test_case = 1; test_case <= tc ; test_case++){
        int n, m, k;
        cin >> m >> n >> k;

        for(int r = 0 ; r < n ; r++){
            for(int c = 0 ; c < m ; c++){
                map[r][c] = 0;
                check[r][c] = false;
            }
        }

        for(int i = 0 ; i < k  ; i++){
            int r,c;
            cin >> c >> r;
            map[r][c] = 1;
        }

        int count = 0;
        for(int r = 0 ; r < n ; r++){
            for(int c = 0 ; c < m ; c++){
                if(map[r][c] && !check[r][c])   count += bfs(n,m, r,c);
            }
        }

        cout << count << '\n';

    }
        

    return 0;

}