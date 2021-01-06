#include<iostream>
#include<vector>


using namespace std;

bool map[10001][10001];
bool visited[10001];
bool check[2];
int ans = -1;

void DFS(int from, int child1, int child2, int size){
    if(child1 == from){
        check[0] = 1;
    }
    else if(child2 == from){
        check[1] = 1;
    }

    visited[from] = 1;
    for(int to =  0 ; to < 10001 ; to++){
        if(map[from][to] && visited[to]==0){
            DFS(to, child1, child2,1+size);
            if(check[0] && check[1] && ans==-1){
                ans = from;
            }
        }
    }


}



int main(){
    int tc;
    scanf("%d",&tc);
    for(int test_case = 1; test_case <= tc ; test_case++){
        for(int i = 0 ; i < 10001 ; i++){
            for(int j = 0 ; j < 10001 ; j++){
                map[i][j] = 0;
            }
            visited[i] = 0;
        }

        check[0] = check[1] = 0;

        int v, e, child1,child2;
        int start;
        scanf("%d %d %d %d",&v,&e, &child1, &child2);
        for(int i = 0  ; i < e ; i++){
            
            int from, to;
            scanf("%d %d",&from, &to);
            if(i==0)    start = from;
            map[from][to] = 1;
        }

        DFS(start,child1,child2,0);

        printf("#%d %d %d\n");

    }
}