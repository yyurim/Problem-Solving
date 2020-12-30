#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int map[1000001];
bool check[1000001];

int main(){
    int F, S, G, U ,D;
    cin >> F >> S >> G >> U >> D;

    queue<pair<int, int> > visit;
    visit.push(make_pair(S,0));
    check[S] = true;

    while(!visit.empty()){
        int now = visit.front().first;
        int count = visit.front().second;
        visit.pop();
        if(now == G){
            cout << count << '\n';
            return 0;
        }

        if(now + U <= F && now + U > 0){
            if(!check[now + U]){
                visit.push(make_pair(now + U, count+1));
                check[now + U]= true;
            }
        }

        if(now - D <= F && now - D > 0){
            if(!check[now - D]){
                visit.push(make_pair(now - D, count+1));
                check[now - D]= true;
            }
        }

    }

    cout << "use the stairs\n";

    return 0;

}