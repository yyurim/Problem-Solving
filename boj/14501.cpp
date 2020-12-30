#include<iostream>
#include<vector>

using namespace std;

#define T 0
#define P 1


int cal(vector<vector<int> > &table, int idx, int earning){
    if(idx >= table.size()){
        return earning;
    }

    int worked;
    if(idx+table[idx][T] > table.size()){
        worked = cal(table, idx+table[idx][T], earning);
    }
    else{
        worked = cal(table, idx+table[idx][T], earning+table[idx][P]);
    }

    int passed = cal(table, idx+1, earning);

    return worked > passed ? worked : passed;
}

int main(){
    int days;
    cin >> days;

    vector<int> vals(2);
    vector<vector<int> > table(days, vals);
    

    for(int i = 0 ; i < days ; i++){
        int t,p;
        cin >> table[i][T] >> table[i][P];

    }

    cout << cal(table, 0,0) << '\n';

    return 0;

}


/*
정답
    그!!! 인덱스에서 일을 할거냐 말거냐
    시작 인덱스가 0일이기때문에
    하루를 더 쓸 수 있고, table의 크기가 근무일에 포함될 수 있다.

    재귀
*/


/*
#include <iostream>
using namespace std;
const int inf = -100000000;
int t[21];
int p[21];
int n;
int ans = 0;
void go(int day, int sum) {
    if (day == n+1) {
        if (ans < sum) ans = sum;
        return;
    }
    if (day > n+1) {
        return;
    }
    go(day+1, sum);
    go(day+t[day], sum+p[day]);
}
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i] >> p[i];
    }
    go(1, 0);
    cout << ans << '\n';
    return 0;
}
*/