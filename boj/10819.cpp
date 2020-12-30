#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> numbers(n);

    for(int i = 0 ; i < n ; i++){
        cin >> numbers[i];
    }

    sort(numbers.begin(),numbers.end());

    int max = -1;

    do{
        int sum = 0;
        for(int i = 0 ; i < n-1 ; i++){
            sum += abs(numbers[i]-numbers[i+1]);
        }
        if(sum > max){
            max = sum;
        }

    }while(next_permutation(numbers.begin(),numbers.end()));

    cout << max << '\n';

    return 0;
}


/*
####################
# 정답
#   모든 순열을 구하려면, 첫 순열이 오름차순이 되게끔 정렬을 해야한다!!!!!!
#   초기화 하세요
####################
*/



/*
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int calculate(vector<int> &a) {
    int sum = 0;
    for (int i=1; i<a.size(); i++) {
        sum += abs(a[i] - a[i-1]);
    }
    return sum;
}
int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = 0;

    do {
        int temp = calculate(a);
        ans = max(ans,temp);
    } while(next_permutation(a.begin(), a.end()));

    cout << ans << '\n';
    return 0;
}
*/
