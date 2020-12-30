#include<iostream>

using namespace std;

long long memo[101];

int main(){
    int tc;
    cin >> tc;

    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 1;
 
    int prev = 3;
    for(int test_case = 1 ; test_case <= tc ; test_case++){
        int n;
        cin >> n;
        for(; prev<= n ; prev++){
            memo[prev] = memo[prev-2]+memo[prev-3];
        }

        cout << memo[n] << '\n';

    }

    return 0;
}