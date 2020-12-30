#include<iostream>
using namespace std;

int memo[1000001];

int dp(int n){
    if(n==0 || n==1){
        memo[n] = 0;
        return memo[n];
    }

    memo[n] = 987654321;

    if(n%2==0){
        if(memo[n/2] <= 0)  memo[n/2] = dp(n/2);
        memo[n] = min(memo[n/2],memo[n]);
    }

    if(n%3==0){
        if(memo[n/3] <= 0) memo[n/3] = dp(n/3);
        memo[n] = min(memo[n/3],memo[n]);
    }

    if(memo[n-1] <= 0) memo[n-1] = dp(n-1);

    memo[n] = min(memo[n-1], memo[n])+1;

    return memo[n];

}


int main(){
    int n;
    cin >> n;

    cout << dp(n) << '\n';

    return 0;

}


/*
정답
    top-down
    이게 bottom-up보다 오래걸림
*/



/*
#include <iostream>
using namespace std;
int d[1000001];
int go(int n) {
    if (n == 1) {
        return 0;
    }
    if (d[n] > 0) {
        return d[n];
    }
    d[n] = go(n-1) + 1;
    if (n%2 == 0) {
        int temp = go(n/2) + 1;
        if (d[n] > temp) {
            d[n] = temp;
        }
    }
    if (n%3 == 0) {
        int temp = go(n/3) + 1;
        if (d[n] > temp) {
            d[n] = temp;
        }
    }
    return d[n];
}
int main() {
    int n;
    cin >> n;
    cout << go(n) << '\n';
    return 0;
}
*/



/*
bottom-up 내 풀이
*/



// #include<iostream>
// #include<vector>

// using namespace std;

// int memo[1000001];

// int main(){
//     int n;
//     cin >> n;

//     memo[0] = 0;
//     memo[1] = 0;

//     for(int i = 2 ; i <= n ; i++){
//         int div2 = 987654321;
//         int div3 = 987654321;
//         int minus1 = memo[i-1];
//         if(i%2==0) div2 = memo[i/2];
//         if(i%3==0) div3 = memo[i/3];
//         memo[i] = min(min(div2,div3), minus1) + 1;
//     }

//     cout << memo[n] << '\n';

//     return 0;

// }




/*
정답
    bottom-up 방식
*/

/*
#include <iostream>
using namespace std;
int d[1000001];
int main() {
    int n;
    cin >> n;
    d[1] = 0;
    for (int i=2; i<=n; i++) {
        d[i] = d[i-1] + 1;
        if (i%2 == 0 && d[i] > d[i/2] + 1) {
            d[i] = d[i/2] + 1;
        }
        if (i%3 == 0 && d[i] > d[i/3] + 1) {
            d[i] = d[i/3] + 1;
        }
    }
    cout << d[n] << '\n';
    return 0;
}
*/