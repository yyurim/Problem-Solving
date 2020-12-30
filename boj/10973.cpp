#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> numbers(n);

    for(int i = 0 ; i < n ; i++){
        cin >> numbers[i];
    }

    if(prev_permutation(numbers.begin(), numbers.end())){
        for(int i = 0 ; i < n ; i++){
            cout << numbers[i] << ' ';
        }
    }else{
        cout << -1;
    }

    cout << '\n';

    return 0;
}

/*
####################
# 정답
#   algorithm 라이브러리의 prev_permutation은 입력벡터의 이전 순열을 입력벡터에 저장한다
#   prev_permutation(vector.begin(), vector.end())
#   위의 함수는 리턴값이 boolean이다 
#        현재 순열의 이전 순열이     존재한다면 true
#                              존재하지 않는다면 false
#        vector에는 현재순열의 이전 순열이 저장된다. 따라서 위험한 방법이다. 원본이 변형되기 때문이다.
####################
*/


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
    if (prev_permutation(a.begin(),a.end())) {
        for (int i=0; i<n; i++) {
            cout << a[i] << ' ';
        }
    } else {
        cout << "-1";
    }
    cout << '\n';
    return 0;
}

*/