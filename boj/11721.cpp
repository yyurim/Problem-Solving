#include<iostream>

using namespace std;

int main(){
    string input;
    cin >> input;

    int cnt = 0;
    for(int i = 0 ; i < input.size() ; i++){
        cout <<input[i];
        cnt++;
        if(cnt%10==0)   cout << '\n';
    }
    cout << '\n';
    return 0;
}