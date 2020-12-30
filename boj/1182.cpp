#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int partition(vector<int> &numbers, int idx, int ans, int sum){
    if(numbers.size() < idx){
        return 0;
    }

    if(numbers.size() == idx){
        if(ans == sum) {
            return 1;
        }
    }

    int count = 0;

    count += partition(numbers,idx+1,ans, sum+numbers[idx]);
    count += partition(numbers,idx+1, ans, sum);

    return count;
}

int main(){
    int n, s;
    cin >> n >> s;

    vector<int> numbers(n);
    for(int i = 0 ; i < n ; i++){
        cin >> numbers[i];
    }

    if(s == 0){
        cout << partition(numbers,0,s,0) -1 << '\n';
    }
    else{
        cout << partition(numbers,0,s,0) << '\n';

    }

    return 0;
}

/*
########################################
// 정답
//     모든 부분집합을 구해야하는 문제
//     최대 부분집합의 수가 2^20 == 1e+6 정도.. 따라서 브루트포스 써도 좋다.
//     재귀를 이용해도 depth가 그다지 깊어지지 않는다.

//     재귀!!
//         failure
//         goal
//         재귀
########################################
*/



/*
#include <iostream>
using namespace std;
int a[20];
int n, m;
int ans = 0;
void go(int i, int sum) {
    if (i == n) {
        if (sum == m) {
            ans += 1;
        }
        return;
    }
    go(i+1, sum+a[i]);
    go(i+1, sum);
}
int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    go(0, 0);
    if (m == 0) ans -= 1;
    cout << ans << '\n';
    return 0;
}
*/