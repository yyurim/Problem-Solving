#include<iostream>
#include<vector>

using namespace std;

typedef struct _cell{
    int loc[2];
    int num;
    int s;
    int d;
    int z;
}cell;

cell map[100][100];

int catch_fish(int n, int col){
    for(int r = 0 ;r < n ; r++){
        if(map[r][col].num != -1){
            int z = map[r][col].z;
            map[r][col].num = -1;
            map[r][col].s = map[r][col].d = map[r][col].z = 0;
            return z;
        }
    }
    return 0;
}

int main(){
    int n,m,k;
    

    cin >> n >> m >> k;
    for(int r= 0 ; r < n ; r++){
        for(int c = 0 ; c < m ; c++){
            map[r][c].loc[0] = r;
            map[r][c].loc[1] = c;
            map[r][c].num = -1;
            map[r][c].s = map[r][c].d = map[r][c].z = 0;
        }
    }
    for(int i = 0 ; i < k ; i++){
        int r, c, s, d,z;
        cin >> r >> c >> s >> d >> z;
        map[r-1][c-1].num = i;
        map[r-1][c-1].s = s;
        map[r-1][c-1].d = d-1;
        map[r-1][c-1].z = z;
    }

    int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
    int sum = 0;
    for(int col = 0 ; col < m ; col++){
        // cout << col << "   before\n";
        // for(int r= 0 ; r < n ; r++){
        //     for(int c= 0 ; c < m ; c++){
        //         cout << map[r][c].num << ' ';
        //     }
        //     cout << endl;
        // }
        sum += catch_fish(n,col);

        vector<cell> fishes;
        for(int r= 0 ; r< n ; r++){
            for(int c =0 ; c < m ; c++){
                if(map[r][c].num >= 0){
                    fishes.push_back(map[r][c]);
                }
                map[r][c].num = -1;
                map[r][c].s = map[r][c].d = map[r][c].z = 0;
            }
        }

        for(int i = 0 ; i < fishes.size() ; i++){
            
            cell f = fishes[i];
            int nr = f.loc[0];
            int nc = f.loc[1];

            if(dir[f.d][1]==0){
                for(int s = 0 ; s < f.s ; s++){
                    if(nr+dir[f.d][0]<0 || nr+dir[f.d][0]>(n-1)){
                        f.d = 1-f.d;
                    }
                    nr += dir[f.d][0];  
                }
            }
            else{
                for(int s = 0 ; s < f.s ; s++){
                    if(nc+dir[f.d][1]<0 || nc+dir[f.d][1]>(m-1)){
                        f.d = 5-f.d;
                    }
                    nc += dir[f.d][1];  
                }

            }

            f.loc[0] = nr;
            f.loc[1] = nc;

            if(map[nr][nc].z < f.z){
                map[nr][nc].num = f.num;
                map[nr][nc].d = f.d;
                map[nr][nc].s = f.s;
                map[nr][nc].z = f.z;
            }


        }
        
        // cout << col << "   after\n";
        // for(int r= 0 ; r < n ; r++){
        //     for(int c= 0 ; c < m ; c++){
        //         cout << map[r][c].num << ' ';
        //     }
        //     cout << endl;
        // }

    }

    cout << sum << '\n';
    return 0;
}

/*
브루트포스
경우의 수 계산해보기..
최단거리 이런말 없으면 그냥 구현이니 일단 경우의수 계산하기
*/