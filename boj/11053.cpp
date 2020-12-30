#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> numbers(n);
    vector<int> memo(n);

    for(int i = 0 ; i < n ; i++){
        cin >> numbers[i];
    }

    for(int i = 0 ; i < n ; i++){
        memo[i] = 1;
        int max = -1;
        for(int j = 0 ;  j < i ; j++){
            if(numbers[i] > numbers[j]){
                if(memo[j] > max){
                    max = memo[j];
                }
            }
        }
        if(max == -1){
            continue;
        }
        memo[i] += max;
    }

    int max = *max_element(memo.begin(), memo.end());

    cout << max <<'\n';

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
        d[i] = 1;
        for (int j=0; j<i; j++) {
            if (a[j] < a[i] && d[j]+1 > d[i]) {
                d[i] = d[j]+1;
            }
        }
    }
    
    cout << *max_element(d.begin(),d.end()) << '\n';
    return 0;
}
*/