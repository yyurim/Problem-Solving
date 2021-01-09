// you can use includes, for example:
#include <algorithm>
#include <vector>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int memo[33];
int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    vector<bool> bin;
    while(N>0){
        bin.push_back(N%2);
        N /= 2;
    }
    reverse(bin.begin(),bin.end());
    
    if(bin.size() <= 0) return 0;
    else{

        bool flag = bin[0];
        int cnt = 0;
        int ans = 0;
        for(int i = 0 ; i < bin.size() ; i++){
            if(bin[i]){
                flag = true;
                ans = ans > cnt ? ans : cnt;
                cnt = 0;
                
            }
            else{
                cnt++;
            }
        }
        return ans;
    }
}