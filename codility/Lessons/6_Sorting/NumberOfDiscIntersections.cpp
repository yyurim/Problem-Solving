// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;


int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int cnt = 0;
    for(int i = 0 ; i < A.size() ; i++){
        for(int j = i+1 ; j < A.size() ; j++){
            if(j-i <= (A[i]+(long long)A[j])){
                cnt++;
                if(cnt>10000000)    return -1;
            }
        }
    }
    return cnt;
}