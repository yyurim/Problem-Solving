#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> numbers(n);
    vector<int> memo(n,0);

    for(int i = 0 ; i < n ; i++){
        cin >> numbers[i];
    }
    memo[0] = numbers[0];
    for(int i = 1 ; i < n ; i++){
        memo[i] = memo[i-1]+numbers[i] > numbers[i] ? memo[i-1]+numbers[i] : numbers[i];
    }

    int max = -987654321;
    for(int i = 0 ; i < n ; i++){
        max = max > memo[i] ? max : memo[i];
    }

    cout << max << '\n';

    return 0;

}

/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    vector<int> d(n);
    for (int i=0; i<n; i++) {
        d[i] = a[i];
        if (i == 0) continue;
        if (d[i] < d[i-1] + a[i]) {
            d[i] = d[i-1] + a[i];
        }
    }
    int ans = d[0];
    for (int i=1; i<n; i++) {
        if (ans < d[i]) {
            ans = d[i];
        }
    }
    cout << ans << '\n';
    return 0;
}
*/