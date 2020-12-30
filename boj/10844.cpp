#include<iostream>
#include<vector>

using namespace std;

#define MOD 1000000000

int memo[101][10];

int main(){
    int n;
    cin >> n;

    for(int i = 0 ; i < 10 ; i++){
        memo[0][i] = 0;
    }
    memo[1][0] = 0;
    for(int i = 1 ; i < 10 ; i++){
        memo[1][i] = 1;
    }

    for(int i = 2 ; i <= n ; i++){
        for(int j = 0 ; j < 10 ; j++){
            if(j==0){
                memo[i][j] = memo[i-1][j+1];
            }
            else if(j == 9){
                memo[i][j] = memo[i-1][j-1];
            }
            else{
                memo[i][j] = (memo[i-1][j-1] + memo[i-1][j+1])%MOD;
            }
        }
    }

    int ans = 0;
    for(int i = 0 ; i < 10 ; i++){
        ans += memo[n][i];
        ans %= MOD;
    }

    cout << ans <<'\n';

    return 0;
}


/*
#include <iostream>
using namespace std;
long long d[101][10];
long long mod = 1000000000;
int main() {
    int n;
    cin >> n;
    for (int i=1; i<=9; i++) {
        d[1][i] = 1;
    }
    for (int i=2; i<=n; i++) {
        for (int j=0; j<=9; j++) {
            d[i][j] = 0;
            if (j-1 >= 0) {
                d[i][j] += d[i-1][j-1];
            }
            if (j+1 <= 9) {
                d[i][j] += d[i-1][j+1];
            }
            d[i][j] %= mod;
        }
    }
    long long ans = 0;
    for (int i=0; i<=9; i++) {
        ans += d[n][i];
    }
    ans %= mod;
    cout << ans << '\n';
    return 0;
}
*/