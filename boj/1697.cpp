#include<iostream>
#include<queue>

using namespace std;

vector<bool> check(100001, false);

int bfs(int from, int to){

    int time = 0;

    queue<pair<int, int> > visit;
    visit.push(make_pair(from,time));
    check[from] = true;

    while(!visit.empty()){
        int now = visit.front().first;
        time = visit.front().second;
        visit.pop();
        if(now==to) return time;
        
        if(now-1 >=0 && now-1 <= 100000){
            if(!check[now-1]){
                visit.push(make_pair(now-1, time+1));
                check[now-1] = true;
            }
        }

        if(now+1 >=0 && now+1 <= 100000){
            if(!check[now+1]){
                visit.push(make_pair(now+1,time+1));
                check[now+1] = true;
            }
        }

        if(now*2 >=0 && now*2 <= 100000){
            if(!check[now*2]){
                visit.push(make_pair(now*2,time+1));
                check[now*2] = true;
            }
        }   

    }

    return time;

}

int main(){
    int from, to;
    cin >> from >> to;

    cout << bfs(from,to) << '\n';

}


/*
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 200000;
bool check[MAX+1];
int dist[MAX+1];
int main() {
    int n, m;
    cin >> n >> m;
    check[n] = true;
    dist[n] = 0;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now-1 >= 0) {
            if (check[now-1] == false) {
                q.push(now-1);
                check[now-1] = true;
                dist[now-1] = dist[now] + 1;
            }
        }
        if (now+1 < MAX) {
            if (check[now+1] == false) {
                q.push(now+1);
                check[now+1] = true;
                dist[now+1] = dist[now] + 1;
            }
        }
        if (now*2 < MAX) {
            if (check[now*2] == false) {
                q.push(now*2);
                check[now*2] = true;
                dist[now*2] = dist[now] + 1;
            }
        }
    }
    cout << dist[m] << '\n';
    return 0;
}
*/