#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void permutation(vector<int> &numbers, int m , int idx, vector<int> &result, vector<vector<int> > &output){
    if(result.size() >= m){
        output.push_back(result);
        return;
    }

    for(int i = idx ; i < numbers.size() ; i++){
        result.push_back(numbers[i]);
        permutation(numbers, m, i, result, output);
        result.pop_back();
    }

    return;
}

int main(){
    int n,m;
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
    output.erase(unique(output.begin(), output.end()), output.end());

    for(int r = 0 ; r < output.size() ; r++){
        for(int c = 0 ; c < m ; c++){
            cout << output[r][c] << ' ';
        }
        cout << '\n';
    }

    return 0;
}



/*
###########################################
정답
    첫번째 코드가 메모리를 더 적게 쓴다.
    각 숫자들이 몇 번 등장했는지 기억하고, 줄여나가기 하면 2차원벡터를 정렬할 필요가 없다.
###########################################
*/


/*
#include <iostream>
#include <algorithm>
using namespace std;
int a[10];
int num[10];
int c[10];
void go(int index, int start, int n, int m) {
    if (index == m) {
        for (int i=0; i<m; i++) {
            cout << num[a[i]];
            if (i != m-1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i=start; i<n; i++) {
        //if (c[i]) continue;
        c[i] = true;
        a[index] = i;
        go(index+1, i, n, m);
        c[i] = false;
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
    for (int i=0; i<n; i++) {
        if (i > 0 && temp[i] == temp[i-1]) continue;
        num[k++] = temp[i];
    }
    n = k;
    go(0,0,n,m);
    return 0;
}
*/

/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[10];
int num[10];
int c[10];
vector<vector<int>> d;
void go(int index, int start, int n, int m) {
    if (index == m) {
        vector<int> temp;
        for (int i=0; i<m; i++) {
            temp.push_back(num[a[i]]);
        }
        d.push_back(temp);
        return;
    }
    for (int i=start; i<n; i++) {
        //if (c[i]) continue;
        c[i] = true;
        a[index] = i;
        go(index+1, i, n, m);
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
    go(0,0,n,m);
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