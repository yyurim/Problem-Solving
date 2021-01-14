#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int map[14][14];
vector<pair<int,int>> ans;
vector<pair<int,int> > cells;

int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
}


void DFS(int n, int v, int length, int hole){
    if(v >=cells.size()){
        v -=hole;
        ans.push_back(make_pair(v,length));
        return;
    }
    int r = cells[v].first;
    int c = cells[v].second;
    
    if(r==1 || r== n || c== 1 || c==n){
        DFS(n,v+1, length,hole);
        return;
    }
    
    for(int d = 0 ; d < 4 ; d++){
        int i = 1;
        int nr, nc;
        while(1){
            nr = r + i*dir[d][0];
            nc = c + i*dir[d][1];
            if(nr <1 || nr> n || nc < 1 || nc > n){
                DFS(n,v+1, length + i -1, hole);
                int rr , rc;
                    for(; i > 1 ; i--){
                        
                        rr = r + (i-1)*dir[d][0];
                        rc = c + (i-1)*dir[d][1];
                        map[rr][rc] = 0;
                     
                    }
                break;
            }
            else{
                if(map[nr][nc]!=0){
                    
                    int rr , rc;
                    for(; i > 1 ; i--){
                        
                        rr = r + (i-1)*dir[d][0];
                        rc = c + (i-1)*dir[d][1];
                        map[rr][rc] = 0;
        
                    }
                    break;
                }
                map[nr][nc] = 1;
           		i++;
            }

        }
        
    }

    DFS(n,v+1, length, ++hole);

    

}

int main(){
    int tc;
    cin >> tc;
    for(int test_case = 1; test_case <=tc ; test_case++){
        int n;
        cin >> n;
        
        for(int r = 0; r < 14 ; r++){
            for(int c = 0 ; c< 14 ; c++){
                map[r][c] = 0;
           }
        }

        for(int r = 1; r <= n ; r++){
            for(int c = 1 ; c<=n ; c++){
                scanf("%d",&map[r][c]);
                if(map[r][c]){
                    cells.push_back(make_pair(r,c));
                }
            }
        }

        DFS(n, 0,0,0);
        
        sort(ans.begin(),ans.end(),compare);
        printf("#%d %d\n",test_case,ans[0].second);
        ans.clear();
        cells.clear();

    }
}