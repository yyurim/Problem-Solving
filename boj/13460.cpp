#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;

int map[10][10];
bool check[10][10][10][10];

typedef struct _state{
    int blue[2];
    int red[2];
    int count;
}state;

int main(){
    int n, m;
    cin >> n >> m;

    state init;
    init.count = 0;

    for(int r = 0 ; r < n ; r++){
        string input;
        cin >> input;
        for(int c= 0 ; c < m ; c++){
            check[r][c][r][c] = false;
            switch(input[c]){
                case '#':
                    map[r][c] = 1;
                    break;
                case '.':
                    map[r][c] = 0;          
                    break;
                case 'B':
                    map[r][c] = 0;
                    init.blue[0] = r;
                    init.blue[1] = c;
                    break;
                case 'R':
                    map[r][c] = 0;
                    init.red[0] = r;
                    init.red[1] = c;
                    break;
                case 'O':
                    map[r][c] = 2;
                    break;
            }
        }
    }

    queue<state> visit;
    visit.push(init);
    check[init.red[0]][init.red[1]][init.blue[0]][init.blue[1]] = true;


    
    while(!visit.empty()){
        state now = visit.front();
        visit.pop();

        if(now.count > 10 ){
            cout << -1 << '\n';
            return 0;
        }
        if(map[now.red[0]][now.red[1]]==2){
            if(map[now.blue[0]][now.blue[1]]!=2){
                cout << now.count << '\n';
                return 0;
            }
            
        }

        int move[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int d = 0 ; d < 4 ; d++){
            int n_red[2];
            n_red[0] = now.red[0];
            n_red[1] = now.red[1];

            while(1){
                n_red[0] += move[d][0];
                n_red[1] += move[d][1];
                if(n_red[0] <0 || n_red[0] >= n || n_red[1] < 0 || n_red[1] >= m){
                    n_red[0] -= move[d][0];
                    n_red[1] -= move[d][1];
                    break;
                }

                if(map[n_red[0]][n_red[1]]==1){
                    n_red[0] -= move[d][0];
                    n_red[1] -= move[d][1];
                    break;
                }

                if(map[n_red[0]][n_red[1]]==2){
                    break;
                }

            }


            int n_blue[2];
            n_blue[0] = now.blue[0];
            n_blue[1] = now.blue[1];

            while(1){
                n_blue[0] += move[d][0];
                n_blue[1] += move[d][1];
                if(n_blue[0] <0 || n_blue[0] >= n || n_blue[1] < 0 || n_blue[1] >= m){
                    n_blue[0] -= move[d][0];
                    n_blue[1] -= move[d][1];
                    break;
                }

                if(map[n_blue[0]][n_blue[1]]==1){
                    n_blue[0] -= move[d][0];
                    n_blue[1] -= move[d][1];
                    break;
                }

                if(map[n_blue[0]][n_blue[1]]==2){
                    break;
                }

            }

        

            if((n_blue[0] == n_red[0]) && (n_blue[1] == n_red[1]) ){

                if(d==0){
                    if(now.red[0] > now.blue[0]){
                        n_blue[0] -= move[d][0];
                    }
                    else if(now.red[0] < now.blue[0]){
                        n_red[0] -= move[d][0];
                    }

                }
                else if(d==1){
                    if(now.red[0] < now.blue[0]){
                        n_blue[0] -= move[d][0];
                    }
                    else if(now.red[0] > now.blue[0]){
                        n_red[0] -= move[d][0];
                    }

                }
                else if(d==2){
                    if(now.red[1] > now.blue[1]){
                        n_blue[1] -= move[d][1];
                    }
                    else if(now.red[1] < now.blue[1]){
                        n_red[1] -= move[d][1];
                    }

                }
                else if(d==3){
                    if(now.red[1] < now.blue[1]){
                        n_blue[1] -= move[d][1];
                    }
                    else if(now.red[1] > now.blue[1]){
                        n_red[1] -= move[d][1];
                    }

                }

                if(map[n_blue[0]][n_blue[1]]==2)    continue;
                if(map[n_red[0]][n_red[1]]==2){
                    if(map[n_blue[0]+move[d][0]][n_blue[1]+move[d][1]]==2){
                        continue;
                    }
                }

            }



            if(check[n_red[0]][n_red[1]][n_blue[0]][n_blue[1]]){
                continue;
            }

            check[n_red[0]][n_red[1]][n_blue[0]][n_blue[1]] = true;

            if(map[n_blue[0]][n_blue[1]]==2){
                continue;
            }



            state new_state;
            new_state.blue[0] = n_blue[0];
            new_state.blue[1] = n_blue[1];
            new_state.red[0] = n_red[0];
            new_state.red[1] = n_red[1];
            new_state.count = now.count + 1;


            visit.push(new_state);
        }


    }

    cout << -1 << '\n';

    return 0;

}