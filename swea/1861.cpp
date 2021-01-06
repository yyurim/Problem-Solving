#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

/*

방문했는지를 확인하는 이유가 뭐야?
다시 방문하지 않으려고
그런데 내가 확인하지 않아도 당연히 다시 방문 안할 경우가 있잖아
-> 더 깊이 들어갈때 통과해야하는 조건문 !!

코드는 알아보기 쉽게
변수 많이 써도 메모리 괜찮아

이 문제의
DFS에서 의미 있는 노드가 뭐야
루트노드뿐 -> 최장 거리 물어보는거니까
루트노드들만 문제 답을 구하기 위한 벡터에 추가시켜

*/

using namespace std;

int rooms[1002][1002];

vector<int> paths;

void DFS(int r, int c, int path){
    if(r < 1 || r > 1000 || c < 1 || c > 1000)
    return;
    int move[2][4] = {{0,1,0,-1},{1,0,-1,0}};
    for(int m = 0 ; m < 4 ; m++){
        int nr = r + move[0][m];
        int nc = c + move[1][m];
        if((rooms[nr][nc] == (1+rooms[r][c]))){
            DFS(nr,nc,path+1);
        }
    }
    paths.push_back(path);
}

int main(){
    int t;
    scanf("%d",&t);
    
    for(int test_case = 1 ;test_case <= t ; test_case++){
        int N;
        scanf("%d",&N);

        for(int i = 0 ; i < 1002 ;i++){
            for(int j = 0 ; j < 1002 ; j++){
                rooms[i][j] = -1;
            }
        }

        for(int i = 1 ; i <= N ;i++){
            for(int j = 1 ; j <= N ; j++){
                int temp;
                scanf("%d", &temp);
                rooms[i][j] = temp;
            }
        }
        
        pair<int,int> max_path;
        max_path.first = 1002000;
        max_path.second = 0;
        int previous = 1002000;
        
        int path_board[2+N][2+N];
        for(int r = 1 ; r <= N ;r++){
            for(int c = 1 ; c <= N ;c++){
                DFS(r,c,1);
                int loc_max = *max_element(paths.begin(),paths.end());
                previous = max_path.second;
                
                if(loc_max >= previous){
                    max_path.second = loc_max;
                    max_path.first = rooms[r][c];
                }
                
                path_board[r][c] = loc_max;
                paths.clear();

            }
        }
        
        for(int r = 1 ; r <= N; r++){
            for(int c= 1; c<=N ;c++){
                if(max_path.second == path_board[r][c])
                    if(max_path.first >= rooms[r][c])
                        max_path.first = rooms[r][c];
            }
        }
        
        printf("#%d %d %d\n",test_case,max_path.first,max_path.second);
        paths.clear();
    }
}