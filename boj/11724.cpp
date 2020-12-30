#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dfs(vector<vector<int> > &adjacent, int v, vector<bool> &check){
    check[v] = true;

    for(int i = 0 ; i < adjacent[v].size() ; i++){
        if(check[adjacent[v][i]])    continue;
        dfs(adjacent, adjacent[v][i], check);
    }

    return;

}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > adjacent(n);
    vector<bool> check(n, false);
    for(int i = 0 ; i < m ; i++){
        int v1, v2;
        cin >> v1 >> v2;
        adjacent[v1-1].push_back(v2-1);
        adjacent[v2-1].push_back(v1-1);
    }

    for(int i = 0 ; i < n ; i++){
        sort(adjacent[i].begin(), adjacent[i].end());
    }

    int count = 0;
    int visited;
    int starting = 0;
    do{
        dfs(adjacent, starting, check);
        visited = 0;
        for(int i = 0 ; i < n ; i++){
            if(check[i])    visited++;
            else{
                starting = i;
            }
        }
        count++;
    }while(visited < n);
    // for(int i = 0 ; i < n ; i++){
    //     if(check[i])    continue;
    //     dfs(adjacent, i, check);
    //     count++;
    // }
    

    cout << count << '\n';
    return 0;
}


/*
##############################
정답
    연결요소 찾기
    모든 노드에 대해 dfs를 수행한다.
    이미 방문한 적이 있는 노드는 첫번째 노드가 될 수 없다. 
##############################
*/


/*
#include <cstdio>
#include <vector>
using namespace std;
vector<int> a[1001];
bool check[1001];
void dfs(int node) {
    check[node] = true;
    for (int i=0; i<a[node].size(); i++) {
        int next = a[node][i];
        if (check[next] == false) {
            dfs(next);
        }
    }
}
int main() {
    int n, m;
    scanf("%d %d",&n,&m);
    for (int i=0; i<m; i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int components = 0;
    for (int i=1; i<=n; i++) {
        if (check[i] == false) {
            dfs(i);
            components += 1;
        }
    }
    printf("%d\n",components);
    return 0;
}
*/