#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    int n;
    cin >> n;

    
    int len = int(log(n))+1;
    int ans = 0;
    for(int i = 1 ; i <= len  ; i++){
        ans += (n%10)*i;
        n /=10;
    }

    cout << ans <<'\n';

    return 0;


}