// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int cnt[100001];

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int max = 0;
    for(int i = 0 ; i < A.size() ; i++){
        int X = A[i];
        
        if(X>=1 && X<= N){
            cnt[X]++;
            max = max > cnt[X] ? max : cnt[X];
        }
        
        else if(X == (N+1)){
            fill_n(cnt, N+1, max);
            // for(int j = 1 ; j <=N ;j++){
            //     cnt[j] = max;
            // }
        }
    }

    vector<int> ans;

    for(int i = 1 ; i <= N;i++){
        ans.push_back(cnt[i]);
    }

    return ans;
}
