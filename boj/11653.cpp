#include<iostream>
#include<vector>

using namespace std;

bool numbers[10000001];

int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < 10000001; i++){
        numbers[i] = true;
    }
    numbers[0] = numbers[1] = false;
    for(int i = 2 ; i*i <= 10000000 ; i++){
        if(numbers[i]==false){
            continue;
        }
        for(long long j = i+1 ; j*i <= 10000000 ; j++){
            numbers[j*i] = false;
        }
    }
    vector<int> primes;

    for(int i = 0 ; i <= 10000001; i++){
        if(numbers[i]){
            primes.push_back(i);
        }
    }

    int idx = 0;
    do{
        if( n%primes[idx] == 0){
            n /= primes[idx];
            cout << primes[idx] << '\n';
        }
        else{
            idx++;
        }
    }while(n!=1);

    return 0;
    

}

/*
소인수 분해문제
소수 전부 구함 에라토스네스의 체 이용
*/