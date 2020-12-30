#include<iostream>
#include<vector>

using namespace std;

#define MOD 1000000009

int memo[100001][3];

int main(){
    int tc;
    cin >> tc;
    vector<int> test_case(tc);
    for(int i = 0 ; i < tc ; i++){
        cin >> test_case[i]; 
    }

    for(int t = 0; t < tc ; t++){
        int n = test_case[t];

        
        memo[0][0] = memo[0][1] = memo[0][2] = 0;

        memo[1][0] = 1;
        memo[1][1] = memo[1][2] = 0;

        memo[2][0] = memo[2][2] = 0;
        memo[2][1] = 1;

        memo[3][0] = memo[3][1] = memo[3][2] = 1;

        for(int i = 4 ; i <= n ; i++){
            memo[i][0] = (memo[i-1][1] + memo[i-1][2])%MOD;
            memo[i][1] = (memo[i-2][0] + memo[i-2][2])%MOD;
            memo[i][2] = (memo[i-3][0] + memo[i-3][1])%MOD;
        }

        int ans = ((memo[n][0] + memo[n][1])%MOD + memo[n][2])%MOD;

        cout << ans << '\n';


    }

    return 0;

}

/*
#include <stdio.h>
long long d[1000001][4];
const long long mod = 1000000009LL;
const int limit = 100000;
int main() {
    for (int i=1; i<=limit; i++) {
        if (i-1 >= 0) {
            d[i][1] = d[i-1][2] + d[i-1][3];
            if (i == 1) {
                d[i][1] = 1;
            }
        }
        if (i-2 >= 0) {
            d[i][2] = d[i-2][1] + d[i-2][3];
            if (i == 2) {
                d[i][2] = 1;
            }
        }
        if (i-3 >= 0) {
            d[i][3] = d[i-3][1] + d[i-3][2];
            if (i == 3) {
                d[i][3] = 1;
            }
        }
        d[i][1] %= mod;
        d[i][2] %= mod;
        d[i][3] %= mod;
    }
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        printf("%lld\n",(d[n][1] + d[n][2] + d[n][3])%mod);
    }
}
*/