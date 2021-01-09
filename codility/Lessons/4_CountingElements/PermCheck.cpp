// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    int N = A.size();

    sort(A.begin(),A.end());
    A.erase(unique(A.begin(),A.end()),A.end());
    if(A.size()< N )    return false;
    else{
        for(int i = 0 ; i < N ;i++){
            if(A[i]-i > 1)  return false;
        }
    }

    return true;
}