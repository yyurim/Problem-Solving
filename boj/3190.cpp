#include<iostream>
#include<queue>

using namespace std;

int map[102][102];

int main(){
    int n, k;
    scanf("%d",&n);

    for(int r= 0 ;r < n+2 ; r++){
        for(int c= 0 ; c < n+2 ; c++){
            map[r][c] = 0;
            if((r==0 )|| (r==(n+1)) || (c == 0) || (c==(n+1))){
                map[r][c] = 1;
            }
        }
    }

    scanf("%d",&k);
    for(int i = 0 ; i < k ; i++){
        int r,c;
        scanf("%d %d",&r,&c);
        map[r][c] = 2;
    }

    int m;
    scanf("%d",&m);
    vector<pair<int, char> > inst(m);
    int total = 0;
    for(int i = 0 ; i  < m ; i++){
        scanf("%d %c",&inst[i].first, &inst[i].second);
        // inst[i].first -=total;
        // total+= inst[i].first;
    }

    deque<pair<int,int > > snake;
    snake.push_back(make_pair(1,1));
    
    int time = 0;
    int head = 0;
    int idx = 0;
    int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
    while(!snake.empty()){
        
        pair<int, int> cur = snake.front();

        int nr = cur.first+dir[head][0];
        int nc = cur.second+dir[head][1];

        if(map[nr][nc]==1){
            printf("%d\n",time+1);
            return 0;
        }
        else if(map[nr][nc]==2){
            map[cur.first][cur.second] = 1;
            map[nr][nc] = 1;

            snake.push_front(make_pair(nr,nc));
        }
        else{

            map[nr][nc] = 1;
            map[snake.back().first][snake.back().second] = 0;
            snake.push_front(make_pair(nr,nc));
            snake.pop_back();
        }

        time++;
        if(inst[idx].first==time){
            if(inst[idx].second=='D'){
                head = ((head-1)%4);
                if(head < 0){
                    head += 4;
                }

            }
            else{
                head = (head+1)%4;
            }
            idx++;
        }
    }

    printf("%d\n",time);
    return 0;

}