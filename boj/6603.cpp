#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    

    do{
        cin >> n;
        vector<int> numbers(n);
        vector<int> digits(n);
        
        for(int i = 0 ; i < n ; i++){
            cin >> numbers[i];
        }

        sort(numbers.begin(),numbers.end());

        for(int i = 0 ; i < n ; i++){
            digits[i] = i > 5 ? 0 : 1;
        }

        do{
            for(int i =0 ; i < n ; i++){
                if(numbers[i]*digits[i]){
                    cout << numbers[i];
                }
                else{
                    continue;
                }
                cout << ' ';
            }

            cout << '\n';

        }while(prev_permutation(digits.begin(),digits.end()));
        cout << '\n';

    }while(n!=0);

    return 0;
}

/*
정답
    1. 순열을 사용하는 경우
        정렬 후 해당 인덱스를 선택할 것인가?
        bit mask 순열 만들기 : 선택은 1 아니면 0

    2. 재귀를 사용하는 경우
        정렬 후 해당 인덱스를 선택할 것인가?
        failure이 아니거나 goal이 아니라면
        어쨌든!! 기회를 소비하고 재귀호출하기
*/



/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        vector<int> d;
        for (int i=0; i<n-6; i++) {
            d.push_back(0);
        }
        for (int i=0; i<6; i++) {
            d.push_back(1);
        }
        vector<vector<int>> ans;
        do {
            vector<int> current;
            for (int i=0; i<n; i++) {
                if (d[i] == 1) {
                    current.push_back(a[i]);
                }
            }
            ans.push_back(current);
        } while (next_permutation(d.begin(), d.end()));
        sort(ans.begin(), ans.end());
        for (auto &v : ans) {
            for (int i=0; i<v.size(); i++) {
                cout << v[i] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}
*/



/*
#include <iostream>
#include <vector>
using namespace std;
vector<int> lotto;
void solve(vector<int> &a, int index, int cnt) {
    if (cnt == 6) {
        for (int num : lotto) {
            printf("%d ",num);
        }
        printf("\n");
        return;
    }
    int n = a.size();
    if (n == index) return;
    lotto.push_back(a[index]);
    solve(a,index+1,cnt+1);
    lotto.pop_back();
    solve(a,index+1,cnt);
}
int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        solve(a, 0, 0);
        cout << '\n';
    }
    return 0;
}
*/