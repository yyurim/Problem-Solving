#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> numbers(n);
    vector<int> memo(n,1);
    for(int i = 0 ; i < n ; i++){
        cin >> numbers[i];
    }

    for(int i = 0 ; i < n ; i++){
        int max = -1;
        for(int j = 0 ;  j < i ; j++){
            if(numbers[i]<numbers[j]){
                if(memo[j] > max){
                    max = memo[j];
                }
            }
        }
        if(max != -1){
            memo[i] += max;
        }
    }

    int max = *max_element(memo.begin(), memo.end());
    cout << max <<'\n';

    return 0;

    
}