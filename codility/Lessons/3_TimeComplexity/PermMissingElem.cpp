// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(),A.end());

    for(int i = 0 ; i < A.size() ; i++){
        if((A[i]-i)>1)    return i+1;
    }

    return A.size()+1;
}