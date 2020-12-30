#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> numbers(n+1);
    vector<int> memo(n+1);

    numbers[0] = -1;
    for(int i = 1 ; i <= n ; i++){
        cin >> numbers[i];
    }
    
    for(int i = 1 ; i <= n ;i++){
        memo[i] = numbers[i];
        
        int max = 0;
        for(int j = 1 ; j < i  ; j++){
            if(numbers[j] < numbers[i] && max < memo[j]){
                max = memo[j];
            }
        }

        memo[i] += max;
    }

    int ans = *max_element(memo.begin(), memo.end());
    cout << ans << '\n';

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
        for (int j=0; j<i; j++) {
            if (a[j] < a[i] && d[j]+a[i] > d[i]) {
                d[i] = d[j]+a[i];
            }
        }
    }
    int ans = *max_element(d.begin(),d.end());
    cout << ans << '\n';
    return 0;
}
*/