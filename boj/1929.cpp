#include<iostream>

using namespace std;

bool isPrime[1000001];

int main(){
    int M, N;
    cin >> M >> N;

    for(int i = 1 ; i <=N ; i++){
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    
    for(int i = 1 ; i <= N ; i++){
        if(isPrime[i] == false)  continue;
        if(i<2)   isPrime[i] = false;
        else{
            // int*int의 범위!!!!
            // 어디까지 보면 되는거니?? i*j <= (여기 범위말이야 이 이후는 볼 필요도 없다)
            for(long long j = i ; i*j <= N ; j++){
                isPrime[i*j] = false;
            }
        }
    }

    for(int i = M ; i <=N ; i++){
        if(isPrime[i]){
            cout << i << '\n';
        }
    }

    return 0;

}


/*
####################
# 정답
#   에라토스테네스의 체
#       범위 내의 가장 작은 수의 배수들을 지워보자.
#       남은 수는 모두 소수이다.
#


            // int*int의 범위!!!!
            // 어디까지 보면 되는거니?? i*j <= (여기 범위말이야 이 이후는 볼 필요도 없다)
            for(long long j = i ; i*j <= N ; j++){
                isPrime[i*j] = false;
            }

            이 부분을 루트 N 까지만보는게 best이다.
            하지만 약간의 제약이 있다.
            시작 점을 현재 가장 작은 수의 <<제곱수>>라고두자.
                곱연산을 사용하므로 현재 자료형의 두배만큼의 공간이 필요하여 오버플로가 발생한다.
                이렇게 두고 싶다면 자료형 조심해라.
            그렇지 않다면 시작점을 현재 가장 작은 수의 <<2배>> 정도로두자.
                곱연산을 사용하지 않으므로 현재 자료형만큼의 공간만이 필요하다. 


####################
*/


/*
#include <iostream>
using namespace std;
const int MAX = 1000000;
bool check[MAX+1];
int main() {
    check[0] = check[1] = true;
    for (int i=2; i*i<=MAX; i++) {
        if (check[i] == false) {
            for (int j=i+i; j<=MAX; j+=i) {
                check[j] = true;
            }
        }
    }
    int m, n;
    cin >> m >> n;
    for (int i=m; i<=n; i++) {
        if (check[i] == false) {
            cout << i << '\n';
        }
    }
    return 0;
}
*/