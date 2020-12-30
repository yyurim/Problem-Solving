#include<iostream>

using namespace std;

int memo[11];

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
            memo[i] = memo[i-1] + memo[i-2] + memo[i-3];
        }

        cout << memo[n] <<'\n';

    }

    return 0;
}

/*
정답
    DP 풀이임~~
*/


/*
#include <stdio.h>
int d[11];
int main() {
    d[0] = 1;
    for (int i=1; i<=10; i++) {
        if (i-1 >= 0) {
            d[i] += d[i-1];
        }
        if (i-2 >= 0) {
            d[i] += d[i-2];
        }
        if (i-3 >= 0) {
            d[i] += d[i-3];
        }
    }
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        printf("%d\n",d[n]);
    }
}
*/







// #include<iostream>

// using namespace std;

// int recursion(int val, int sum, int depth);

// int main(){
//     int T;
//     int test_case;
//     cin >> T;

//     for(test_case = 1 ; test_case <=T ; test_case++){
//         int n;
//         cin >> n;
//         cout << recursion(n, 0, 0) << '\n';

//     }

//     return 0;
// }

// int recursion(int val, int sum, int depth){
//     int count = 0;
//     if(depth > 10){
//         return count;
//     }

//     for(int i = 1 ; i <=3 ; i++){
//         if( sum+i == val ){
//             count += 1;
//         }
//         else if(sum+i<val){
//             count += recursion(val, sum+i, depth+1);
//         }
//     }

//     return count;
// }

/*
####################
# 정답
#   n중 for문은 재귀함수로 구현 가능하다.
#   하지만 depth가 너무 깊거나 자매노드가 너무 많다면??
#   이 문제의 경우 depth는 10, 자매노드는 3으로 고정됐기때문에
#   시간 복잡도는 O(3^10)으로 백만정도밖에 되지 않는다.
#   그래서 이런 말도 안되는 재귀가 가능한 것이다.
####################
*/

/*
#include <cstdio>
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int ans = 0;
        int n;
        scanf("%d",&n);
        for (int l1=1; l1<=3; l1++) {
            if (l1 == n) {
                ans += 1;
            }
            for (int l2=1; l2<=3; l2++) {
                if (l1+l2 == n) {
                    ans += 1;
                }
                for (int l3=1; l3<=3; l3++) {
                    if (l1+l2+l3 == n) {
                        ans += 1;
                    }
                    for (int l4=1; l4<=3; l4++) {
                        if (l1+l2+l3+l4 == n) {
                            ans += 1;
                        }
                        for (int l5=1; l5<=3; l5++) {
                            if (l1+l2+l3+l4+l5 == n) {
                                ans += 1;
                            }
                            for (int l6=1; l6<=3; l6++) {
                                if (l1+l2+l3+l4+l5+l6 == n) {
                                    ans += 1;
                                }
                                for (int l7=1; l7<=3; l7++) {
                                    if (l1+l2+l3+l4+l5+l6+l7 == n) {
                                        ans += 1;
                                    }
                                    for (int l8=1; l8<=3; l8++) {
                                        if (l1+l2+l3+l4+l5+l6+l7+l8 == n) {
                                            ans += 1;
                                        }
                                        for (int l9=1; l9<=3; l9++) {
                                            if (l1+l2+l3+l4+l5+l6+l7+l8+l9 == n) {
                                                ans += 1;
                                            }
                                            for (int l0=1; l0<=3; l0++) {
                                                if (l1+l2+l3+l4+l5+l6+l7+l8+l9+l0 == n) {
                                                    ans += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
*/

/*
####################
# 정답
#   n중 for문은 재귀함수로 구현 가능하다.
#   정답과 내 코드가 다른 점은 
#       나는 depth 정보를 이용했다는 것이다.
#       사실 이 문제에서 depth는 필요하지 않은 정보이다.
#       합이 특정 수를 만족하면 되기때문이다.
#       몇 번의 덧셈이 일어났는지가 중요한 문제가 아니다.
####################
*/

/*
#include <iostream>
using namespace std;
int go(int sum, int goal) {
    if (sum > goal) {
        return 0;
    }
    if (sum == goal) {
        return 1;
    }
    int now = 0;
    for (int i=1; i<=3; i++) {
        now += go(sum+i, goal);
    }
    return now;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << go(0, n) << '\n';
    }
    return 0;
}
*/