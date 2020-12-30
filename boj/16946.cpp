#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int map[1000][1000];
bool check[1000][1000];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);

    vector<pair<int,int> > walls;
    for(int r = 0 ; r < n ; r++){
        char input[1001];
        scanf("%s",input);
        for(int c = 0 ; c < m ; c++){
            map[r][c] = input[c]-'0';
            if(map[r][c]){
                check[r][c] = true;
                walls.push_back(make_pair(r,c));
            }
        }
    }

    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    for(int i = 0 ; i < walls.size() ; i++){
        bool check_loc[1000][1000];
        memcpy(check_loc, check, sizeof(check_loc));

        pair<int,int> now = walls[i];
        queue<pair<int, int> > visit;
        visit.push(now);
        int count = 0;
        while(!visit.empty()){
            count++;
            pair<int ,int> cur = visit.front();
            visit.pop();

            for(int d = 0 ; d < 4 ;d++){
                int nr = cur.first + dir[d][0];
                int nc = cur.second + dir[d][1];
                if(nr < 0  || nr >= n || nc < 0 || nc >=m || check_loc[nr][nc]){
                    continue;
                }
                check_loc[nr][nc] = true;
                visit.push(make_pair(nr, nc));
            }
        }
        map[now.first][now.second] = count;

    }

    for(int r = 0 ; r < n ; r++){
        string out;
        for(int c = 0 ; c < m ; c++){
            out.push_back((map[r][c]%10)+'0');
        }
        cout << out << '\n';
    }

    return 0;
    
}