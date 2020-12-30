#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

vector<int> people(9);

int main(){

    for(int i = 0 ; i < 9 ; i++){
        cin >> people[i];
    }

    sort(people.begin(),people.end());

    int total_height = accumulate(people.begin(), people.end(),0);
    for(int i = 0 ; i < 9 ; i++){
        for(int j = i+1 ; j < 9 ; j++){
            if(total_height - people[i] - people[j] == 100){
                people.erase(people.begin()+j);
                people.erase(people.begin()+i);

             }
        }
    }

    for(int i = 0 ; i < 7 ; i++){
        cout << people[i] << '\n';
    }

    return 0;

}

/*
####################
# 정답
#   그냥 라이브러리 사용해
#   algorithm
#       sort(arr, arr+idx) *************************** 이거봐 행렬도 정렬가능~~
#       sort(vector.begin(), vector.end())
#   numeric
#       accumulate(vector.begin(), vector.end(), init)
####################
*/

/*
#include <iostream>
#include <algorithm>
using namespace std;
int a[9];
int n = 9;
int main() {
    int sum = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a,a+n);
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (sum - a[i] - a[j] == 100) {
                for (int k=0; k<n; k++) {
                    if (i == k || j == k) continue;
                    cout << a[k] << '\n';
                }
                return 0;
            }
        }
    }
    return 0;
}
*/