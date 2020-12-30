#include<iostream>

using namespace std;

int dp[1001];

int main(){
    int n;
    cin >> n;

    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2 ; i <=n ; i++){
        dp[i] = (dp[i-1]%10007  + dp[i-2]%10007 )%10007;
    }

    cout << dp[n] << '\n';

    return 0;
}

/*
정답
    정답에 나머지처리를 해야하는 경우!!!! 수가 너무 크잖아
    나머지 연산은 분배 후에 다시 한 번 더!!
*/


/*
#include <cstdio>
int d[1001];
int main() {
    d[0]=1;
    d[1]=1;
    int n;
    scanf("%d",&n);
    for (int i=2; i<=n; i++) {
        d[i] = d[i-1]+d[i-2];
        d[i] %= 10007;
    }
    printf("%d\n",d[n]);
    return 0;
}
*/