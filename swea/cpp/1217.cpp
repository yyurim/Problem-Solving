#include <iostream>
#include <vector>

using namespace std;

int exp(int base, int exponent);

int main(){
    int TC;
    cin >> TC;

    for(int test_case = 1; test_case <= TC ;test_case++){
        int t;
        cin >> t;

        int base = cin.get();
        int exponent = cin.get();

        cout << to_string(t)<<'\n';
        cout << to_string(exp(base,exponent)) << '\n';
        
    }
    
    return 0;
}

int exp(int base, int exponent){
    if(exponent <= 0){
        return 1;
    }
    else{
        return base * exp(base, (exponent-1));
    }
}