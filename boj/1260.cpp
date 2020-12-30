#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

void dfs(vector<vector<int> > &nodes, int v, vector<bool> &check){
    check[v] = true;
    cout << v+1 << ' ';
    for(int i = 0 ; i < nodes[v].size() ; i++){
        if(check[nodes[v][i]])    continue;
        dfs(nodes, nodes[v][i], check);
    }

    return;
}

void bfs(vector<vector<int> > &nodes, int v, vector<bool> &check){
    queue<int> togo;
    check[v] = true;
    togo.push(v);
    while(!togo.empty()){
        v = togo.front();
        cout << v+1  << ' ';
        togo.pop();

        for(int i = 0 ; i < nodes[v].size() ; i++){
            if(check[nodes[v][i]])    continue;
            check[nodes[v][i]] = true;
            togo.push(nodes[v][i]);
        }
    }
    cout << '\n';
    return;
}

int main(){
    int n, m, starting;
    cin >> n >> m >> starting;

    vector<vector<int> > nodes(n);
    vector<bool> checkdfs(n ,false);
    vector<bool> checkbfs(n ,false);

    for(int i = 0 ; i < m ; i++){
        int v1, v2;
        cin >> v1 >> v2;

        nodes[v1-1].push_back(v2-1);
        nodes[v2-1].push_back(v1-1);
    }

    for(int i = 0 ; i < n ; i++){
        sort(nodes[i].begin(), nodes[i].end());
    }
    
    dfs(nodes, starting-1, checkdfs);
    cout <<'\n';
    bfs(nodes, starting-1, checkbfs);

    return 0;


}





/*
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector<int> a[1001];
bool check[1001];
void dfs(int node) {
    check[node] = true;
    printf("%d ",node);
    for (int i=0; i<a[node].size(); i++) {
        int next = a[node][i];
        if (check[next] == false) {
            dfs(next);
        }
    }
}
void bfs(int start) {
    queue<int> q;
    memset(check,false,sizeof(check));
    check[start] = true;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        printf("%d ",node);
        for (int i=0; i<a[node].size(); i++) {
            int next = a[node][i];
            if (check[next] == false) {
                check[next] = true;
                q.push(next);
            }
        }
    }
}
int main() {
    int n, m, start;
    scanf("%d %d %d",&n,&m,&start);
    for (int i=0; i<m; i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i=1; i<=n; i++) {
        sort(a[i].begin(), a[i].end());
    }
    dfs(start);
    puts("");
    bfs(start);
    puts("");
    return 0;
}
*/

















// #include<iostream>
// #include<vector>

// using namespace std;

// int arr[1001][1001];
// bool check[1001];

// void DFS(int v){
//     check[v] = 1;
//     cout << v << " ";
//     for(int to = 0 ; to < 1001; to++){
//         if(check[to]==0 && arr[v][to])
//             DFS(to);
//     }
        
// }
// void BFS(int v){
//     vector<int> q;
//     q.push_back(v);
//     check[v] = 1;
//     while(q.empty()==0){
//         int from = q.front();
//         cout << from << " ";
//         q.erase(q.begin());
//         for(int to = 0 ; to < 1001 ; to++){
//             if(arr[from][to] && check[to]!=1){
//                 check[to] = 1;
//                 q.push_back(to);

//             }
//         }
//     }

// }

// int main(){
//     int N,M,start;
//     scanf("%d %d %d",&N,&M,&start);

//     for(int e = 0 ; e<M;e++){
//         int to,from;
//         scanf("%d %d",&from,&to);
//         arr[from][to] = arr[to][from] = 1;
//     }

//     for(int i = 0 ; i < 1001 ; i++) check[i] = 0;

//     DFS(start);
//     cout << '\n';

//     for(int i = 0 ; i < 1001 ; i++) check[i] = 0;

//     BFS(start);



// }