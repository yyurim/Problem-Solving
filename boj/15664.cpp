#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void permutation(vector<int> &numbers, int m, int idx, vector<int> &result, vector<vector<int> > &output){
    if(result.size() >= m){
        output.push_back(result);
        return;
    }
    
    for(int i = idx ; i < numbers.size() ; i++){
        result.push_back(numbers[i]);
        permutation(numbers, m, i+1, result, output);
        result.pop_back();
    }

    return;
}

int main(){
    int n ,m;
    cin >> n >> m;
    vector<int> numbers(n);
    vector<int> result;
    vector<vector<int> > output;
    for(int i = 0 ; i < n ; i++){
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    permutation(numbers, m, 0, result, output);

    sort(output.begin(), output.end());
    output.erase(unique(output.begin(), output.end()),output.end());
    for(int r= 0 ; r < output.size() ; r++){
        for(int c = 0 ; c < m ; c++){
            cout << output[r][c] << ' ';
        }
        cout << '\n';
    }
    return 0;

}


/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[10];
int num[10];
int cnt[10];
void go(int index, int start, int n, int m) {
    if (index == m) {
        for (int i=0; i<m; i++) {
            cout << num[a[i]] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i=start; i<n; i++) {
        if (cnt[i] > 0) {
            cnt[i] -= 1;
            a[index] = i;
            go(index+1, i, n, m);
            cnt[i] += 1;
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    int temp[10];
    for (int i=0; i<n; i++) {
        cin >> temp[i];
    }
    sort(temp,temp+n);
    int k = 0;
    int x = temp[0];
    int c = 1;
    for (int i=1; i<n; i++) {
        if (x == temp[i]) {
            c += 1;
        } else {
            num[k] = x;
            cnt[k] = c;
            k += 1;
            x = temp[i];
            c = 1;
        }
    }
    num[k] = x;
    cnt[k] = c;
    n = k+1;
    go(0,0,n,m);
    return 0;
}
*/