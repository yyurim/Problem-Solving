// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
bool isNeg(int n){
    return n <= 0;
}

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(),A.end());
    A.erase(unique(A.begin(),A.end()),A.end());

    int max = A.back();
    if(max <= 0)    return 1;
    else{
        remove_if(A.begin(),A.end(),isNeg);
        for(int i = 0 ; i < A.size() ; i++){
            if(A[i]-i > 1 ) return i+1;
        }
    }

    return max+1;

}