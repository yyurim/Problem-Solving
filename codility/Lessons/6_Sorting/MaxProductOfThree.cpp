// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool isPos(int n ){
    return n>0;
}

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();

    sort(A.begin(),A.end());
    if(A.back()<0){
        return A[n-1]*A[n-2]*A[n-3];
    }
    else{
        // int zero_pos = find(A.begin(),A.end(),0)-A.begin();
        int pos_pos = find_if(A.begin(),A.end(),isPos)-A.begin();
        if(pos_pos <= 1){
            return A[n-1]*A[n-2]*A[n-3];
        }
        else{
            return A[n-1]*A[n-2]*A[n-3] > A[n-1]*A[1]*A[0] ? A[n-1]*A[n-2]*A[n-3] : A[n-1]*A[1]*A[0];
        }

    }
}


// // you can use includes, for example:
// #include <algorithm>

// // you can write to stdout for debugging purposes, e.g.
// // cout << "this is a debug message" << endl;

// int solution(vector<int> &A) {
//     // write your code in C++14 (g++ 6.2.0)
//     vector<bool> mask(A.size()-3,0);
//     mask.push_back(1);
//     mask.push_back(1);
//     mask.push_back(1);
    
//     int max = -987654321;
//     do{
//         long long temp = 1;

//         for(int i = 0 ; i < mask.size() ; i++){
//             if(mask[i]) temp *= A[i];
//         }

//         max = max > temp ? max : temp;

//     }while(next_permutation(mask.begin(),mask.end()));

//     return max;
// }