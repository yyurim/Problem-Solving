#include<iostream>
#include<sstream>

using namespace std;

int gcd(int m , int n){
    if( n == 0 ){
        return m;
    }

    return gcd(n,m%n);
}

int nums[100];

int main(){
    int T;
    int test_case;

    cin >> T;
    cin.ignore(256,'\n');
    

    for(test_case = 1; test_case <= T ;test_case++){


        string input, temp;
        getline(cin, input);

        stringstream ss(input);

        int idx = 0;
        while(getline(ss,temp,' ')){
            nums[idx++] = stoi(temp);
        }

        long long ans = 0;

        for(int i = 1 ; i < idx ; i++){
            for(int j = i+1 ; j < idx ; j++){
                int m, n;
                if(nums[i]>nums[j]){
                    m = nums[i];
                    n = nums[j];
                }
                else{
                    m = nums[j];
                    n = nums[i];
                }
                ans += gcd(m,n);
            }

        }

        cout << ans << '\n';


    }

    return 0;
}


/*
####################
# 정답
#   문제의 입력 출력 반드시 확인
#   cin 과 getline을 같이 쓰고 싶다면 !!!!!!!!!!!!!!!
#       cin
#       cin.ignore
#       getline
####################
*/

/*
#include <iostream>
using namespace std;
int gcd(int x, int y) {
    if (y == 0) return x;
    else return gcd(y,x%y);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a[111];
        int n;
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        long long sum=0;
        for (int i=0; i<n-1; i++) {
            for (int j=i+1; j<n; j++) {
                sum += gcd(a[i],a[j]);
            }
        }
        cout << sum << '\n';
    }
    return 0;
}
*/