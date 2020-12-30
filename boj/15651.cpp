#include<iostream>
#include<vector>

using namespace std;

void permutation(vector<int> &numbers, int n, int m){
    if(numbers.size() >= m){
        for(int i = 0 ; i < m ; i++){
            cout << numbers[i] << " ";
        }
        cout << "\n";
        return ;
    }
    for(int i = 1 ; i <= n; i++){
        numbers.push_back(i);
        permutation(numbers, n, m);
        numbers.pop_back();
    }

    return;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> numbers;

    permutation(numbers, n , m);
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
        //if (c[i]) continue;
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