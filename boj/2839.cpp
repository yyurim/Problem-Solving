#include<iostream>

using namespace std;

int memo[5001];

int main(){

    int n;
    cin >> n;

    memo[0] = 0;
    memo[1] = 0;
    memo[2] = 0;
    memo[3] = 1;
    memo[4] = 0;
    memo[5] = 1;

    for(int i = 6 ; i <= n;i++){
        if(memo[i-5]!=0 && memo[i-3]!= 0){
            memo[i] = min(memo[i-3] , memo[i-5]) + 1;
        }
        else if(memo[i-5]==0 && memo[i-3]!=0){
            memo[i] = memo[i-3] + 1;
        }
        else if(memo[i-3]==0 && memo[i-5]!=0){
            memo[i] = memo[i-5] + 1;
        }
        else{
            memo[i] = 0;
        }
    }

    if(memo[n]==0){
        cout << -1 << '\n';
    }
    else{
        cout << memo[n] << '\n';
    }
    
    return 0;

}