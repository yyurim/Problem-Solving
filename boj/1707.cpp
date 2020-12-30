#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dfs(vector<vector<int> > &nodes, int v, int color, vector<int> &check){
    int divided = color;
    if(check[v]==0){
        check[v] = color;
    }

    for(int i = 0 ; i < nodes[v].size() ; i++){
        if(divided <= 0)    break;
        if(check[nodes[v][i]]!=color){
            if(check[nodes[v][i]]==0){
                divided = dfs(nodes,nodes[v][i], 3-color, check);
            }
        }
        else{
            divided = 0;
        }
    }

    return divided;

}

int main(){
    int test_case;
    cin >> test_case;

    for(int tc = 0 ; tc < test_case ; tc++){
        int v, e;
        cin >> v >> e;
        vector<vector<int> > nodes(v);
        vector<int> check(v, 0);
        for(int i = 0 ; i < e ; i++){
            int v1, v2;
            cin >> v1 >> v2;
            nodes[v1-1].push_back(v2-1);
            nodes[v2-1].push_back(v1-1);
        }

        int color = 1;
        string ans = "YES\n";

        for(int i = 0 ; i < v ; i++){
            if(check[i])    continue;
            color = dfs(nodes, i, color, check);
            if(color <= 0){
                ans = "NO\n";
                break;
            }
        }

        cout << ans;

    }

    return 0;

}


/*
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector<int> a[20001];
int color[20001];
bool dfs(int node, int c) {
    color[node] = c;
    for (int i=0; i<a[node].size(); i++) {
        int next = a[node][i];
        if (color[next] == 0) {
            if (dfs(next, 3-c) == false) {
                return false;
            }
        } else if (color[next] == color[node]) {
            return false;
        }
    }
    return true;
}
int main() {
    int t;
    scanf("%d\n",&t);
    while (t--) {
        int n, m;
        scanf("%d %d",&n,&m);
        for (int i=1; i<=n; i++) {
            a[i].clear();
            color[i] = 0;
        }
        for (int i=0; i<m; i++) {
            int u,v;
            scanf("%d %d",&u,&v);
            a[u].push_back(v);
            a[v].push_back(u);
        }
        bool ok = true;
        for (int i=1; i<=n; i++) {
            if (color[i] == 0) {
                if (dfs(i, 1) == false) {
                    ok = false;
                }
            }
        }
        printf("%s\n",ok ? "YES" : "NO");
    }
    return 0;
}
*/