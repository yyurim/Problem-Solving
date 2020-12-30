#include<iostream>
#include<vector>

using namespace std;

void permutation(vector<int> &numbers, int idx, int n, int m, vector<bool> &check){
    if(idx >= m){
        for(int i = 0 ; i < m ; i++){
            cout << numbers[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i = 0 ; i < n ; i++){
        if(check[i])    continue;
        check[i] = true;
        numbers.push_back(i+1);
        permutation(numbers, idx+1, n, m, check);
        numbers.pop_back();
        check[i] = false;
    }

    return;

}

int main(){
    int n,m;
    cin >> n >> m;

    vector<int> numbers;
    vector<bool> check(n);
    for(int i = 0 ; i < n ; i++){
        check[i] = false;
    }

    permutation(numbers, 0, n,m,check);

    return 0;

}


/*
#include <iostream>
using namespace std;
bool c[10];
int a[10];
void go(int index, int n, int m) {
    if (index == m) {
        for (int i=0; i<m; i++) {
            cout << a[i];
            if (i != m-1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i=1; i<=n; i++) {
        if (c[i]) continue;
        c[i] = true;
        a[index] = i;
        go(index+1, n, m);
        c[i] = false;
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    go(0,n,m);
    return 0;
}
*/