#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int memo[n+1];

    memo[0] = 0;

    for(int i = 1; i <= n ;i++){
        int min = memo[i-1]+1;
        for(int j = 1 ; j*j <= i ; j++){
            min = min < memo[i-j*j]+1 ? min : memo[i-j*j]+1 ;
        }
        memo[i] = min;
    }

    cout << memo[n] << '\n';

    return 0;
}

/*
#include <iostream>
using namespace std;
int d[100001];
int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        d[i] = i;
        for (int j=1; j*j <= i; j++) {
            if (d[i] > d[i-j*j]+1) {
                d[i] = d[i-j*j]+1;
            }
        }
    }
    cout << d[n] << '\n';
    return 0;
}
*/