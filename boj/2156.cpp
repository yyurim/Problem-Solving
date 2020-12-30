#include<iostream>
#include<vector>

using namespace std;

int memo[10001][3];
int wine[10001];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n ; i++){
        cin >> wine[i];
    }

    memo[0][0] = memo[0][1] = memo[0][2] = 0;
    memo[1][0] = memo[1][2] = 0;
    memo[1][1] = wine[1];

    for(int i = 2;  i<=n ; i++){
        memo[i][0] = max(max(memo[i-1][0],memo[i-1][1]),memo[i-1][2]);
        memo[i][1] = memo[i-1][0] + wine[i];
        memo[i][2] = memo[i-1][1] + wine[i];
    }

    int ans = max(max(memo[n][0],memo[n][1]),memo[n][2]);
    cout << ans <<'\n';

    return 0;


}

/*
#include <iostream>
using namespace std;
int a[10001];
int d[10001];
int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    d[1] = a[1];
    d[2] = a[1]+a[2];
    for (int i=3; i<=n; i++) {
        d[i] = d[i-1];
        if (d[i] < d[i-2] + a[i]) {
            d[i] = d[i-2] + a[i];
        }
        if (d[i] < d[i-3] + a[i] + a[i-1]) {
            d[i] = d[i-3] + a[i] + a[i-1];
        }
    }
    printf("%d\n",d[n]);
    return 0;
}
*/