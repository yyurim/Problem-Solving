#include<iostream>
#include<vector>

using namespace std;


int max_cost[1001];


int main(){
    int n;
    cin >> n;
    vector<int> p(n+1);

    p[0] = 0;
    for(int i = 1 ; i <= n ; i++){
        cin >> p[i];
    }

    max_cost[0] = p[0];
    max_cost[1] = p[1];

    

    for(int i = 1 ; i <= n ; i++){
        int max = -1;
        for(int j = 1 ; j <= i ; j++){
            if(max_cost[i-j]+p[j] > max){
                max = max_cost[i-j]+p[j];
            }
        }
        max_cost[i] = max;
    }

    cout << max_cost[n] << '\n';

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
    vector<int> d(n+1);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            d[i] = max(d[i],d[i-j]+a[j]);
        }
    }
    cout << d[n] << '\n';
    return 0;
}
*/