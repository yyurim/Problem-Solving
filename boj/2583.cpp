#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

bool check[101][101];
bool map[101][101];


int main(){
    int m, n, k;
    
    scanf("%d %d %d",&m ,&n, &k);

    for(int i = 0 ; i < k ; i++){
        int lx, ly, rx, ry;
        scanf("%d %d %d %d", &lx, &ly, &rx, &ry);

        for(int r= ly ; r< ry ; r++){
            for(int c = lx ; c < rx ; c++){
                check[r][c] = true;
                map[r][c] = true;
            }
        }
    }

    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<int> ans;
    for(int r = 0 ; r < m ;r++){
        for(int c= 0 ; c < n ;c++){
            if(check[r][c]) continue;
            
            queue<pair<int, int> > visited;
            visited.push(make_pair(r,c));
            check[r][c] = true;

            int cnt = 1;

            while(!visited.empty()){
                pair<int, int> now = visited.front();
                visited.pop();
                for(int d = 0 ; d < 4; d++){
                    int nr = now.first+dir[d][0];
                    int nc = now.second+dir[d][1];
                    if(nr < 0 || nr >= m || nc <0 || nc>=n || check[nr][nc]) continue;

                    visited.push(make_pair(nr,nc));
                    check[nr][nc] = true;
                    cnt++;
                }
            }

            ans.push_back(cnt);     

        }
    }

    sort(ans.begin(),ans.end());

    printf("%d\n", ans.size());
    for(int i = 0 ; i < ans.size() ; i++){
        printf("%d ",ans[i]);
    }

    printf("\n");

    return 0;
}