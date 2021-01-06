#include<iostream>
#include<vector>

using namespace std;

/*
***********************************
DFS...
언제 visited에 추가해야할지
언제 visit했다고 check해야할지
***********************************
*/



int main(){
    for(int tc = 1; tc<=10 ; tc++){
        int t;
        cin >>t;
        cin.ignore(256, '\n');
        int move[2][4] = {{0,0,1,-1},{1,-1,0,0}};
        int maze[16][16];
        int check[16][16];

        int now_r, now_c;

        for(int r = 0 ; r < 16 ; r++){
            string input;
            getline(cin, input);
            for(int c = 0 ; c < 16 ; c++){
                maze[r][c] = input[c]-'0';
                check[r][c] = 0;

                if(maze[r][c]==2){
                    maze[r][c] = 0;
                    now_r =r;
                    now_c = c;
                }
            }
        }


        vector<pair<int, int> > path;
        int answer = 1;

        while(maze[now_r][now_c]!=3){
            int deeper = 0;
            
            for(int i = 0 ; i < 4 ; i++){
                if(((now_c < 15) && (i==0))||((now_c>0 )&& (i==1))||((now_r <15) && (i==2))||((now_r >0) && (i==3))){
                    int tmp_r = now_r + move[0][i];
                    int tmp_c = now_c + move[1][i];
                    if(((maze[tmp_r][tmp_c] == 0 )||(maze[tmp_r][tmp_c] == 3))&& (check[tmp_r][tmp_c]==0)){
                        check[now_r][now_c] = 1;
                        path.push_back(make_pair(now_r,now_c));
                        now_r  = tmp_r;
                        now_c = tmp_c;
                        deeper = 1;
                        break;
                    }
                }
            }
            

            if(deeper){
                continue;
            }

            if(path.empty()){
                answer = 0;
                break;
            }
            else{
                maze[now_r][now_c] = 1;
                pair<int, int> now = path.back();
                now_r = now.first;
                now_c = now.second;
                path.pop_back();
            }
            
        }

        printf("#%d %d\n",tc, answer);

    }
}