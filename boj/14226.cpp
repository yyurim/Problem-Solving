#include<iostream>
#include<queue>

using namespace std;

typedef struct _state{
    int emoji;
    int clip;
}state;



int main(){
    int s;
    cin >> s;

    
    bool check[2001][2001];
    for(int r = 0; r < 2001 ; r++){
        for(int c = 0 ; c < 2001 ; c++){
            check[r][c] = false;
        }
    }

    queue<pair<state, int> > states;
    state init;
    init.emoji = 1;
    init.clip = 0;
    states.push(make_pair(init, 0));
    check[1][0] = true;

    while(!states.empty()){
        pair<state, int> now = states.front();
        int emoji = now.first.emoji;
        int clip = now.first.clip;
        int time = now.second;
        // cout << emoji << " " << clip << " " << time << endl;
        states.pop();

        if(emoji == s){
            cout << time << '\n';
            return 0;
        }

        
        if(emoji <= 2000){
            if(!check[emoji][emoji]){
                check[emoji][emoji] = true;
                state next;
                next.emoji = emoji;
                next.clip = emoji;
                states.push(make_pair(next, time+1));
            }
        }
        

        if(clip+emoji <= 2000){
            if(!check[clip+emoji][clip]){
                check[clip+emoji][clip] = true;
                state next;
                next.emoji = clip+emoji;
                next.clip = clip;
                states.push(make_pair(next, time+1));
            }
        }

        if(emoji-1 >=0){
            if(!check[emoji-1][clip]){
                check[emoji-1][clip] = true;
                state next;
                next.emoji = emoji -1;
                next.clip = clip;
                states.push(make_pair(next, time+1));
            }
        }
    }

    return 0;

}

/*
#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;
int d[1001][1001];
int main() {
    int n;
    cin >> n;
    memset(d,-1,sizeof(d));
    queue<pair<int,int>> q;
    q.push(make_pair(1,0));
    d[1][0] = 0;
    while (!q.empty()) {
        int s, c;
        tie(s, c) = q.front();
        q.pop();
        if (d[s][s] == -1) {
            d[s][s] = d[s][c] + 1;
            q.push(make_pair(s,s));
        }
        if (s+c <= n && d[s+c][c] == -1) {
            d[s+c][c] = d[s][c] + 1;
            q.push(make_pair(s+c, c));
        }
        if (s-1 >= 0 && d[s-1][c] == -1) {
            d[s-1][c] = d[s][c] + 1;
            q.push(make_pair(s-1, c));
        }
    }
    int ans = -1;
    for (int i=0; i<=n; i++) {
        if (d[n][i] != -1) {
            if (ans == -1 || ans > d[n][i]) {
                ans = d[n][i];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
*/