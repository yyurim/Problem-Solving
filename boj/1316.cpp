#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        string input;
        cin >> input;

        int memo[26] = {0,};
        bool flag = true;

        char prev = input[0];
        memo[prev-'a']++;
        
        if(input.size() <=1){
            ans++;
        }
        else{
            for(int j = 1 ; j < input.size() ; j++){
                int now = input[j]-'a';
                if(memo[now] > 0 && prev!=input[j]){
                    flag = false;
                    break;
                }
                prev = input[j];
                memo[now]++;
            }
            if(flag)    ans++;
        }

        
    }

    cout << ans << '\n';

    return 0;
}