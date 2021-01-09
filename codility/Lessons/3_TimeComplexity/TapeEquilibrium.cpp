// you can use includes, for example:
// #include <algorithm>
#include <numeric>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int memo[100001];

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int sum = accumulate(A.begin(),A.end(),0);

    memo[0] = A[0];
    int min = 987654321;
    for(int i = 1 ; i < A.size() ; i++){
        memo[i] = memo[i-1]+A[i];
        min = min < abs(sum-2*memo[i-1]) ? min : abs(sum-2*memo[i-1]);
    }
    
    return min;
}