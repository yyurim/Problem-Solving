#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void permutation(vector<int> &numbers, int m, vector<int> result){
    if(result.size()>=m){
        for(int i = 0 ; i < m ; i++){
            cout << numbers[result[i]] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0 ; i < numbers.size() ; i++){
        result.push_back(i);
        permutation(numbers,m,result);
        result.pop_back();
    }

    return;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> numbers(n);
    vector<int> result;
    for(int i = 0 ; i < n ; i++){
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());
    permutation(numbers, m, result);

    return 0;


}

/*
#include <iostream>
#include <algorithm>
using namespace std;
int a[10];
int num[10];
int c[10];
void go(int index, int n, int m) {
    if (index == m) {
        for (int i=0; i<m; i++) {
            cout << num[a[i]];
            if (i != m-1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i=0; i<n; i++) {
        c[i] = true;
        a[index] = i;
        go(index+1, n, m);
        c[i] = false;
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> num[i];
    }
    sort(num,num+n);
    go(0,n,m);
    return 0;
}
*/