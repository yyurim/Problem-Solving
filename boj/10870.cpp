#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long memo[n+1];
    memo[0] = 0;
    memo[1] = 1;

    for(int i = 2; i<=n ;i++){
        memo[i] = memo[i-1] + memo[i-2];
    }
    cout << memo[n] << '\n';

    return 0;
}