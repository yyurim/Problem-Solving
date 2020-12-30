#include<iostream>
#include<vector>

using namespace std;


int main(){
    int tc;
    cin >> tc;

    int map[100001][3];
    int memo[100001][3];
    for(int test_case = 1 ; test_case <= tc ; test_case++){
        
        int cols;
        cin >> cols;
        

        for(int r = 1 ; r < 3 ; r++){
            for(int c = 1 ; c <= cols ; c++){
                cin >> map[c][r];
            }
        }

        memo[0][0] = memo[0][1] = memo[0][2] = 0;


        for(int c = 1 ; c <= cols ;c++){
            memo[c][0] = max(memo[c-1][0],max(memo[c-1][1],memo[c-1][2]));
            memo[c][1] = max(memo[c-1][0]+map[c][1],memo[c-1][2]+map[c][1]);
            memo[c][2] = max(memo[c-1][0]+map[c][2],memo[c-1][1]+map[c][2]);
        }

        int ans = max(memo[cols][0],max(memo[cols][1],memo[cols][2]));

        cout << ans <<'\n';
        
    }

    return 0;
}

/*
#include <iostream>
#include <algorithm>
using namespace std;
long long a[100001][2];
long long d[100001][3];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> a[i][0];
        }
        for (int i=1; i<=n; i++) {
            cin >> a[i][1];
        }
        d[0][0] = d[0][1] = d[0][2] = 0;
        for (int i=1; i<=n; i++) {
            d[i][0] = max({d[i-1][0],d[i-1][1],d[i-1][2]});
            d[i][1] = max(d[i-1][0],d[i-1][2])+a[i][0];
            d[i][2] = max(d[i-1][0],d[i-1][1])+a[i][1];
        }
        long long ans = max({d[n][0], d[n][1], d[n][2]});
        cout << ans << '\n';
    }
    return 0;
}
*/