// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<bool> memo(1000000001,false);

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    long long max = -1;
    long long min = 1000000001;
    for(int i = 0 ; i < A.size() ; i++){
        max = max > A[i] ? max : A[i];
        min = min < A[i] ? min : A[i];
        if(memo[A[i]]){
            memo[A[i]] = false;
        }
        else{
            memo[A[i]] = true;
        }
    }

    int ans =  find(memo.begin()+min,memo.begin()+max,true)-memo.begin();

    return ans;
}