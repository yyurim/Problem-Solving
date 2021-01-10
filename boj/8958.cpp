#include<iostream>
#include<vector>

using namespace std;



int main(){
    int tc;
    cin >> tc;
    for(int test_case = 0 ; test_case < tc ;test_case++){
        string input;
        cin >> input;

        int memo[81] = {0,};
        memo[0] = input[0]=='O'? 1 : 0;
        
        int score = memo[0];

        for(int i = 1 ; i < input.size() ; i++){
            if(input[i]=='O'){
                memo[i] = memo[i-1] + 1;
            }
            score+=memo[i];
        }

        cout << score << '\n';
    }

    return 0;
    
}