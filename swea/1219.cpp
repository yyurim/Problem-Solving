#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
*****************************************************
방향성이 없는 그래프
*****************************************************
*/




int main(){
    for(int test_case = 1; test_case <= 1; test_case++){
        int t, e;
        scanf("%d %d",&t, &e);

        int maps[100][100];
        int visited[100];
        vector<int> next;

        for(int i = 0 ; i < 100 ; i++){
            visited[i] = 0;
            for(int j = 0 ; j < 100 ; j++){
                maps[i][j] = 0;
            }
        }

        for(int i = 0 ; i < e ; i++){
            int from, to;
            scanf("%d %d",&from, &to);
            //printf("%d %d\n",from,to);
            maps[from][to] = maps[to][from] = 1;
        }

        int now = 0;
        visited[now] = 1;
        next.push_back(now);
        int finished = 0;
        while(visited[99]!=1){
            int deeper = 0;
            
            for(int v = now+1 ; v < 100 ; v++){
                if(maps[now][v] && !visited[v]){
                    visited[v] = 1;
                    next.push_back(v);
                    now = v;
                    deeper = 1;
                    //cout << now << " ";
                    break;
                }
            }

            if(deeper)	continue;

            if(next.empty()){
                finished = 1;
                break;
            }
            else{
                now = next.back();
                next.pop_back();
                //cout <<"\n"<< now << " ";
            }

        }

        if(finished){
            printf("#%d %d\n",test_case,0);
        }
        else{
            printf("#%d %d\n",test_case,1);
        }
    }
}