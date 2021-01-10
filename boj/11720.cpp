#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;

    string input;
    cin >> n;
    cin >> input;

    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += input[i]-'0';
    }
    cout << sum << '\n';

    return 0;
}