#include<iostream>

using namespace std;

int nums[101];

int main(){
    int n;
    int ans = 0;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> nums[i];
    }

    for(int i = 0 ; i < n ; i++){
        bool flag = true;
        if(nums[i] < 2){
            flag = false;
        }
        else{
            for(int j = 2 ; j*j <= nums[i] ; j++){
                if( (nums[i]%j)==0 ){
                    flag = false;
                    break;
                }}
        }

        if(flag)    ans++;
    }

    cout << ans << '\n';

    return 0;

}


/*
####################
# 정답
#   <배열의 값>을 넣는지
#   <배열의 인덱스>를 넣는지
#   이런거 헷갈리지 말기
####################
*/


/*
#include <iostream>
using namespace std;
bool is_prime(int x) {
    if (x < 2) {
        return false;
    }
    for (int i=2; i*i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    
    int cnt = 0;
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        if (is_prime(num)) {
            cnt += 1;
        }
    }

    cout << cnt << '\n';
    return 0;
}
*/