#include<iostream>
#include<vector>

using namespace std;

int map[1001][3];
int memo[1001][3];

int main(){
    int n;
    cin>> n;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j < 3 ; j++){
            cin>> map[i][j];
        }   
    }

    memo[0][0] = memo[0][1] = memo[0][2] = 0;
    memo[1][0] = map[1][0];
    memo[1][1] = map[1][1];
    memo[1][2] = map[1][2];
    for(int i = 2 ; i <= n ; i++){
        memo[i][0] = min(memo[i-1][1],memo[i-1][2])+map[i][0];
        memo[i][1] = min(memo[i-1][0] , memo[i-1][2])+map[i][1];
        memo[i][2] = min(memo[i-1][0] , memo[i-1][1])+map[i][2];
    }

    int ans = min(min(memo[n][0],memo[n][1]),memo[n][2]);

    cout << ans <<'\n';

    return 0;
    

}