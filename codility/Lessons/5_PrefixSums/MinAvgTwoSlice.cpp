// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

float memo[100001][3];

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    memo[0][0] = A[0];  // accumulated sum
    memo[0][1] = A[0];
    memo[0][2] = 0;

    for(int i = 1 ; i < A.size() ; i++){
        memo[i][0] = memo[i-1][0]+A[i];
        float min = memo[i][0]/(i+1);
        int start_idx = 0;
        for(int j = 0; j< i;  j++){
            float part_sum = memo[i][0]-memo[j][0]+A[j];
            float part_avg = part_sum/(i+1-j);
            if(min >= part_avg){
                min = part_avg;
                start_idx = j;
            }
        }

        memo[i][1] = min;
        memo[i][2] = start_idx;
    }

    float ans = 987654321;
    int ans_idx = 0;
    for(int i = 1 ; i < A.size() ; i++){
        if(ans > memo[i][1]){
            ans = memo[i][1];
            ans_idx = memo[i][2];
        }
    }

    return ans_idx;
}