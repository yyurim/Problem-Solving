// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> ans;
    int n = P.size();

    vector<int>  scores;

    for(int i = 0 ; i < S.size() ; i++){
        switch(S[i]){
            case 'A':
                scores.push_back(1);
                break;
            case 'C':
                scores.push_back(2);
                break;
            case 'G':
                scores.push_back(3);
                break;
            case 'T':
                scores.push_back(4);
                break;
        }
    }

    for(int i = 0 ; i < n ; i++){
        int s = P[i];
        int e = Q[i];

        int min = *min_element(scores.begin()+s, scores.begin()+e+1);
        ans.push_back(min);
    }

    return ans;
}