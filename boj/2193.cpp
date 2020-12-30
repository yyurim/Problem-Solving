#include<iostream>
#include<vector>

using namespace std;

long long memo[91][2];

int main(){
    int n;
    cin >> n;

    memo[0][0] = memo[0][1] = 0;
    memo[1][0] = 0;
    memo[1][1] = 1;

    for(int i = 2 ; i <= n ;i++){
        memo[i][0] = memo[i-1][0]+memo[i-1][1];
        memo[i][1] = memo[i-1][0];
    }

    long long ans = memo[n][0] + memo[n][1];
    cout << ans <<'\n';

    return 0;

}



/*
정답
    피보나치수 long long !!!!!!!!!!!!!!!!!!
*/
/*
#include <iostream>
using namespace std;
long long d[91];
int main() {
    int n;
    cin >> n;
    d[1] = 1;
    d[2] = 1;
    for (int i=3; i<=n; i++) {
        d[i] = d[i-1] + d[i-2];
    }
    cout << d[n] << '\n';
    return 0;
}
*/