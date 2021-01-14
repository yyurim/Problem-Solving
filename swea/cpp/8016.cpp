#include<iostream>
#include<vector>

using namespace std;

int main(){
    int TC;
    cin >> TC;

    for(int test_case = 1; test_case <= TC ; test_case++){
        long long lev;
        cin >> lev;

        long long first = 1+2*(lev-1)*(lev-1);
        long long last = 2*lev*lev - 1;

        cout << "#" <<to_string(test_case)+" "+to_string(first)+" "+to_string(last)+'\n';
    }
}