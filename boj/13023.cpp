#include<iostream>
#include<vector>

using namespace std;

bool connected(vector<vector<int> > &friends, int count, int person, vector<bool> &check){
    bool exists = false;
    if(count >= 4){
        exists = true;
        return exists;
    }

    check[person] = true;
    for(int i = 0 ; i < friends[person].size() ; i++){
        if(exists){
            check[person] = false;
            break;
        }
        if(check[friends[person][i]])   continue;
        check[friends[person][i]] = true;
        exists = connected(friends, count+1, friends[person][i], check);
        check[friends[person][i]] = false;
    }
    check[person] = false;

    return exists;

}

int main(){
    int n , m;
    cin >> n >> m;
    
    vector<vector<int> > friends(n);
    vector<bool> check(n, false);

    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    bool result = false;

    for(int i = 0 ; i < n ; i++){
        if(result)  break;
        result = connected(friends, 0, i, check);
    }

    cout << result << endl;

    return 0;

}


/*
인접리스트
    양방향에 추가해야한다!!!!!!
*/



/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool a[2000][2000];
vector<int> g[2000];
vector<pair<int,int>> edges;
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int from, to;
        cin >> from >> to;
        edges.push_back({from, to});
        edges.push_back({to, from});
        a[from][to] = a[to][from] = true;
        g[from].push_back(to);
        g[to].push_back(from);
    }
    m *= 2;
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            // A -> B
            int A = edges[i].first;
            int B = edges[i].second;
            // C -> D
            int C = edges[j].first;
            int D = edges[j].second;
            if (A == B || A == C || A == D || B == C || B == D || C == D) {
                continue;
            }
            // B -> C
            if (!a[B][C]) {
                continue;
            }
            // D -> E
            for (int E : g[D]) {
                if (A == E || B == E || C == E || D == E) {
                    continue;
                }
                cout << 1 << '\n';
                return 0;
            }
        }
    }
    cout << 0 << '\n';
    return 0;
}
*/