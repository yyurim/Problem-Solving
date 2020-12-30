#include<iostream>

using namespace std;

int memo[1000001];

int main(){
    int n;
    cin >> n;

    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 2;

    for(int i = 3 ; i <= n ; i++){
        memo[i] = (memo[i-1] + memo[i-2])%15746;
    }

    cout << memo[n] << '\n';

    return 0;

}