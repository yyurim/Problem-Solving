#include<iostream>

using namespace std;

long long memo[31][31];

int main(){
    int tc;
    cin >> tc;
    for(int lev = 0 ; lev <= 30 ; lev++){
        memo[lev][0] = 1;
        memo[lev][lev] = 1;
    }
    memo[0][0] = 0;
    for(int lev = 2 ; lev <= 30 ; lev++){
        for(int r = 1 ; r <= lev-1 ; r++){
            memo[lev][r] = memo[lev-1][r-1] + memo[lev-1][r];
        }
    }
    
    for(int test_case = 0 ; test_case < tc ; test_case++){
        int n, m;
        cin >> n >> m;

        cout << memo[m][n] << '\n';
        
    }
    return 0;
}