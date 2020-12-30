#include<iostream>
#include<vector>

using namespace std;

void permutation(vector<int> numbers, int n, int m, vector<bool> check){
    if(numbers.size() > m ){
        for(int i = 1 ; i <= m ; i++){
            cout << numbers[i] << ' ';
        }
        cout << '\n';

        return;
    }

    for(int i = numbers.back()+1 ; i <= n ; i++){
        if(check[i])    continue;
        numbers.push_back(i);
        check[i] = true;
        permutation(numbers, n, m, check);
        numbers.pop_back();
        check[i] = false;
        
    }

    return ;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> numbers;
    vector<bool> check(n+1, false);
    numbers.push_back(0);
    permutation(numbers, n ,m ,check);

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
        if (c[i]) continue;
        c[i] = true;
        a[index] = i;
        go(index+1, i+1, n, m);
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