#include<iostream>
#include<vector>

using namespace std;

#define MOD 10007

int memo[1001][10];

int main(){
    int n;
    cin >> n;

    for(int i = 0 ; i < 10 ; i++){
        memo[0][i] = 0;
        memo[1][i] = 1;
    }

    for(int i = 2 ; i <= n ;i++){
        for(int j = 0 ; j < 10 ; j++){
            memo[i][j] = 0;
            for(int k = 0 ; k <= j; k++){
                memo[i][j] += memo[i-1][k];
                memo[i][j] %= MOD; 
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
long long d[1001][10];
long long mod = 10007;
int main() {
    int n;
    cin >> n;
    for (int i=0; i<=9; i++) {
        d[1][i] = 1;
    }
    for (int i=2; i<=n; i++) {
        for (int j=0; j<=9; j++) {
            for (int k=0; k<=j; k++) {
                d[i][j] += d[i-1][k];
                d[i][j] %= mod;
            }
        }
    }
    long long ans = 0;
    for (int i=0; i<10; i++) {
        ans  += d[n][i];
    }
    ans %= mod;
    cout << ans << '\n';
    return 0;
}
*/