#include<iostream>
#include<vector>

using namespace std;


int numbers[1001];
int memo[1001];

void print_sequence(vector<int> &prev, int idx){
    if(idx==prev[idx]){
        cout << numbers[prev[idx]] << ' ';
        return;
    }
    print_sequence(prev, prev[idx]);
    cout << numbers[idx] << ' ';

    return;
}

int main(){
    int n;
    cin >> n;

    vector<int> prev(n+1);


    for(int i = 1 ; i <=n ; i++){
        cin >> numbers[i];
        memo[i] = 1;
        prev[i] = i;
    }

    for(int i = 1 ; i <=n ; i++){
        
        int max = -1;
        for(int j = 1 ; j < i ; j++){
            if(numbers[j] < numbers[i]){
                if(max < memo[j]){
                    max = memo[j];
                    prev[i] = j;
                }     
            }
        }
        if(max != -1)   memo[i] += max;
    }

    int max_idx = 0;
    for(int i = 0 ; i <= n ; i++){
        if(memo[i] > memo[max_idx]){
            max_idx = i;
        }
    }

    cout << memo[max_idx] << '\n';
    print_sequence(prev, max_idx);
    cout << '\n';

    return 0;

    
}


/*

#include <iostream>
using namespace std;
int a[1000];
int d[1000];
int v[1000];
void go(int p) {
    // ? -> ? -> ... a[v[p]] -> a[p]
    // ---------------------
    //        go(v[p]);
    if (p == -1) {
        return ;
    }
    go(v[p]);
    cout << a[p] << ' ';
}
int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        d[i] = 1;
        v[i] = -1;
        for (int j=0; j<i; j++) {
            if (a[j] < a[i] && d[i] < d[j]+1) {
                d[i] = d[j]+1;
                v[i] = j;
            }
        }
    }
    int ans = d[0];
    int p = 0;
    for (int i=0; i<n; i++) {
        if (ans < d[i]) {
            ans = d[i];
            p = i;
        }
    }
    cout << ans << '\n';
    go(p);
    cout << '\n';
    return 0;
}


*/
