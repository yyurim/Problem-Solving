#include<iostream>
#include<queue>

using namespace std;

#define MAX 100001

vector<bool> check(MAX,false);
vector<int> points(MAX);

int main(){
    int n, k;
    cin >> n >> k;

    queue<int> visited;
    queue<int> visited_next;

    int time = 0;

    check[n] = true;
    points[n] = time;
    visited.push(n);


    while(!visited.empty() || !visited_next.empty()){
        int now = visited.front();
        if(now == k){
            cout << points[now] << '\n';
            return 0;
        }
        time = points[now];
        visited.pop();

        if(now*2 >= 0 && now*2 < MAX){
            int togo = now *2;
            if(!check[togo]){
                visited.push(togo);
                check[togo] = true;
                points[togo] = time;
            }
        }

        if(now - 1 >=0 && now - 1 <MAX){
            int togo = now-1;
            if(!check[togo]){
                visited_next.push(togo);
                check[togo] = true;
                points[togo] = time+1;
            }
        }

        if(now + 1 >=0 && now + 1 <MAX){
            int togo = now + 1;
            if(!check[togo]){
                visited_next.push(togo);
                check[togo] = true;
                points[togo] = time+1;
            }
        }

        if(visited.empty()){
            queue<int> new_q;
            visited = visited_next;
            visited_next = new_q;
        }

    }

    cout << points[k] <<'\n';

    return 0;
    

}


/*
정답
    어떤 큐부터 볼것인지, 순서에 dependent한 문제임..
    근데 생각해보면 케이스별 가중치가 다른 문제 최단거리문제는 순서에 dependent한게 맞음
*/


/*
#include <iostream>
#include <queue>
#include <deque>
using namespace std;
bool c[1000000];
int d[1000000];
int MAX = 1000000;
int main() {
    int n, m;
    cin >> n >> m;
    c[n] = true;
    d[n] = 0;
    queue<int> q;
    queue<int> next_queue;
    q.push(n);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now*2 < MAX) {
            if (c[now*2] == false) {
                q.push(now*2);
                c[now*2] = true;
                d[now*2] = d[now];
            }
        }
        if (now-1 >= 0) {
            if (c[now-1] == false) {
                next_queue.push(now-1);
                c[now-1] = true;
                d[now-1] = d[now] + 1;
            }
        }
        if (now+1 < MAX) {
            if (c[now+1] == false) {
                next_queue.push(now+1);
                c[now+1] = true;
                d[now+1] = d[now] + 1;
            }
        }
        if (q.empty()) {
            q = next_queue;
            next_queue = queue<int>();
        }
    }
    cout << d[m] << '\n';
    return 0;
}
*/