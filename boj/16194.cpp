#include<iostream>
#include<vector>

using namespace std;


int min_cost[1001];


int main(){
    int n;
    cin >> n;
    vector<int> p(n+1);

    p[0] = 0;
    for(int i = 1 ; i <= n ; i++){
        cin >> p[i];
    }

    min_cost[0] = p[0];
    min_cost[1] = p[1];

    

    for(int i = 1 ; i <= n ; i++){
        int min_temp = 987654321;
        for(int j = 1 ; j <= i ; j++){
            min_temp = min(min_temp, min_cost[i-j]+p[j]);
        }
        min_cost[i] = min_temp;
    }

    cout << min_cost[n] << '\n';

    return 0;

}

/*
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    vector<int> d(n+1,-1);
    d[0] = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            if (d[i] == -1 || d[i] > d[i-j]+a[j]) {
                d[i] = d[i-j]+a[j];
            }
        }
    }
    cout << d[n] << '\n';
    return 0;
}
*/