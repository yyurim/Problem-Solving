#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> numbers(n);
    for(int i = 0 ; i < n ; i++){
        numbers[i] = i+1;
    }

    do{
        for(int i = 0 ; i < n ; i++){
            cout << numbers[i]<<" ";
        }
        cout << '\n';
    }while(next_permutation(numbers.begin(),numbers.end()));

    return 0;

}


/*
####################
# 정답
#   algorithm 라이브러리의 next_permutation은 입력벡터의 다음 순열을 입력벡터에 저장한다
#   next_permutation(vector.begin(), vector.end())
#   위의 함수는 리턴값이 boolean이다 
#        현재 순열의 다음 순열이     존재한다면 true
#                              존재하지 않는다면 false
#        vector에는 현재순열의 다음 순열이 저장된다. 따라서 위험한 방법이다. 원본이 변형되기 때문이다.
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
        a[i] = i+1;
    }
    do {
        for (int i=0; i<n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    } while (next_permutation(a.begin(), a.end()));
    return 0;
}
*/