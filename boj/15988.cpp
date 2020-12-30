#include<iostream>

using namespace std;

int memo[1000001];

int main(){
    int TC;
    cin >> TC;
    
    for(int test_case = 1 ; test_case <= TC ; test_case++){
        int n ;
        cin >> n;

        memo[0] = 1;
        memo[1] = 1;
        memo[2] = 2;
    
        for(int i = 3 ; i <= n ;i++){
            memo[i] = (memo[i-1]%1000000009 + memo[i-2]%1000000009 + memo[i-3]%1000000009)%1000000009;
        }

        cout << memo[n] <<'\n';

    }

    return 0;
}

/*
정답
    아주 큰 정수 !! 자료형.. int는 1e+6여기까지만~
*/


/*
#include <iostream>
using namespace std;
long long d[1000001];
const long long mod = 1000000009LL;
int main() {
    d[0] = 1;
    for (int i=1; i<=1000000; i++) {
        if (i-1 >= 0) {
            d[i] += d[i-1];
        }
        if (i-2 >= 0) {
            d[i] += d[i-2];
        }
        if (i-3 >= 0) {
            d[i] += d[i-3];
        }
        d[i] %= mod;
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }
}
*/