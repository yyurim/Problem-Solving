#include<iostream>

using namespace std;

int map[500][500];

int tiles[19][4][2] = {
    {{0,0},{0,1},{0,2},{0,3}},
    {{0,0},{-1,0},{-2,0},{-3,0}},

    {{0,0},{0,1},{1,0},{1,1}},

    {{0,0},{1,0},{2,0},{2,1}},
    {{0,0},{0,1},{0,2},{-1,2}},
    {{0,0},{-1,0},{-2,0},{-2,-1}},
    {{0,0},{0,-1},{0,-2},{1,-2}},
    {{0,0},{1,0},{2,0},{2,-1}},
    {{0,0},{0,1},{0,2},{1,2}},
    {{0,0},{-1,0},{-2,0},{-2,1}},
    {{0,0},{0,-1},{0,-2},{-1,-2}},

    {{0,0},{1,0},{1,1},{2,1}},
    {{0,0},{0,1},{-1,1},{-1,2}},
    {{0,0},{1,0},{1,-1},{2,-1}},
    {{0,0},{0,1},{1,1},{1,2}},

    {{0,0},{0,1},{0,2},{1,1}},
    {{0,0},{-1,0},{-2,0},{-1,1}},
    {{0,0},{0,-1},{0,-2},{-1,-1}},
    {{0,0},{1,0},{2,0},{1,-1}},  
};


int main(){
    int n,m;
    cin >> n >> m;

    for(int r = 0 ; r < n ; r++){
        for(int c = 0 ; c < m ; c++){
            cin >> map[r][c];
        }
    }

    int max = -1;

    for(int r = 0 ; r < n; r++){
        for(int c = 0 ; c < m; c++){
            for(int i = 0 ; i < 19 ; i++){
                int sum = 0;

                bool flag = false;
                for(int t = 0 ; t<4 ; t++){
                    if(tiles[i][t][0]+r >=n || tiles[i][t][1]+c>=m || tiles[i][t][0]+r < 0 || tiles[i][t][1]+c<0 ){
                        flag = true;
                        break;
                    }
                    sum += map[tiles[i][t][0]+r][tiles[i][t][1]+c];
                }

                if(flag){
                    continue;
                }

                if(sum>max){
                    max = sum;
                }
            } 
        }
    }

    cout << max << '\n';

    return 0;
}


/*
####################
# 정답
#   기준을 명확히해라
#   도형을 돌리는데 기준이 어디냐? 한 점을 고정시키고 돌리는 거다 근본없는 돌리기 하지마라
####################
*/




/*
#include <iostream>
using namespace std;
int a[500][500];
int block[19][3][2] = {
    {{0,1}, {0,2}, {0,3}},
    {{1,0}, {2,0}, {3,0}},
    {{1,0}, {1,1}, {1,2}},
    {{0,1}, {1,0}, {2,0}},
    {{0,1}, {0,2}, {1,2}},
    {{1,0}, {2,0}, {2,-1}},
    {{0,1}, {0,2}, {-1,2}},
    {{1,0}, {2,0}, {2,1}},
    {{0,1}, {0,2}, {1,0}},
    {{0,1}, {1,1}, {2,1}},
    {{0,1}, {1,0}, {1,1}},
    {{0,1}, {-1,1}, {-1,2}},
    {{1,0}, {1,1}, {2,1}},
    {{0,1}, {1,1}, {1,2}},
    {{1,0}, {1,-1}, {2,-1}},
    {{0,1}, {0,2}, {-1,1}},
    {{0,1}, {0,2}, {1,1}},
    {{1,0}, {2,0}, {1,1}},
    {{1,0}, {2,0}, {1,-1}},
};
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for (int k=0; k<19; k++) {
                bool ok = true;
                int sum = a[i][j];
                for (int l=0; l<3; l++) {
                    int x = i+block[k][l][0];
                    int y = j+block[k][l][1];
                    if (0 <= x && x < n && 0 <= y && y < m) {
                        sum += a[x][y];
                    } else {
                        ok = false;
                        break;
                    }
                }
                if (ok && ans < sum) {
                    ans = sum;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
*/