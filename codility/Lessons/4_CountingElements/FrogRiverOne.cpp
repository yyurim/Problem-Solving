// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool memo[100001];

int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int cnt = 0;
    int ans = -1;
    for(int i = 0 ; i < A.size() ; i++){
        if(!memo[A[i]]){
            memo[A[i]] = true;
            cnt++;
            if(cnt>=X){
                ans = i;
                break;
            }
        }
    }
    for(int i = 1; i <= X ; i++){
        if(!memo[i])    return -1;
    }

    return ans;

}
