#include<iostream>
#include<vector>

using namespace std;

void permutation(vector<int> &numbers, int n, int m, int p){
    if(numbers.size() >= m){
        for(int i = 0 ; i < m ; i++){
            cout << numbers[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = p ; i <= n ; i++){
        numbers.push_back(i);
        permutation(numbers, n, m,i);
        numbers.pop_back();
    }

    return;
}

int main(){
    int n , m;
    cin >> n >> m;
    vector<int> numbers;

    permutation(numbers, n,m,1);

    return 0;
}

/*
#include <iostream>
using namespace std;
bool c[10];
int a[10];
void go(int index, int start, int n, int m) {
    if (index == m) {
        for (int i=0; i<m; i++) {
            cout << a[i];
            if (i != m-1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i=start; i<=n; i++) {
        c[i] = true;
        a[index] = i;
        go(index+1, i, n, m);
        c[i] = false;
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    go(0,1,n,m);
    return 0;
}
*/



/*
#include <iostream>
using namespace std;
int cnt[10];
void go(int index, int selected, int n, int m) {
    if (selected == m) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=cnt[i]; j++) {
                cout << i << ' ';
            }
        }
        cout << '\n';
        return;
    }
    if (index > n) return;
    for (int i=m-selected; i>=1; i--) {
        cnt[index] = i;
        go(index+1, selected+i, n, m);
    }
    cnt[index] = 0;
    go(index+1, selected, n, m);
}
int main() {
    int n, m;
    cin >> n >> m;
    go(1, 0, n, m);
    return 0;
}
*/