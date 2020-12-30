#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void permutation(vector<int> &numbers, vector<bool> &check,int m , vector<int> &result, vector<vector<int> > &output){
    if(result.size() >= m ){
        output.push_back(result);
        return;
    }

    for(int i = 0 ; i <numbers.size() ; i++){
        if(check[i])    continue;
        check[i] = true;
        result.push_back(numbers[i]);
        permutation(numbers, check,m , result, output);
        check[i] = false;
        result.pop_back();
    }
    return ;
}

int main(){
    int n , m;
    cin >> n >> m;
    vector<int> numbers(n);
    vector<bool> check(n, false);
    vector<int> result;
    vector<vector<int> > output;
    for(int i = 0 ; i < n ; i++){
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    permutation(numbers, check, m , result, output);

    sort(output.begin(), output.end());
    output.erase(unique(output.begin(),output.end()),output.end());
    for(int i = 0 ; i < output.size() ; i++){
        for(int j = 0 ; j < output[0].size() ; j++){
            cout << output[i][j] <<  ' ';
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
int c[10];
vector<vector<int>> d;
void go(int index, int n, int m) {
    if (index == m) {
        vector<int> temp;
        for (int i=0; i<m; i++) {
            temp.push_back(num[a[i]]);
        }
        d.push_back(temp);
        return;
    }
    for (int i=0; i<n; i++) {
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
    for (int i=0; i<n; i++) {
        cin >> num[i];
    }
    sort(num,num+n);
    go(0,n,m);
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(),d.end()),d.end());
    for (auto &v : d) {
        for (int i=0; i<m; i++) {
            cout << v[i];
            if (i != m-1) {
                cout << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
*/