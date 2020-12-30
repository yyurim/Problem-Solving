#include <vector>
#include <iostream>
#include <numeric>

using namespace std;


int main(){
    int min, max;
    cin >> min;
    cin >> max;

    vector<int> primes;
    primes.push_back(2);
    for(int num = 3; num< min  ; num++){
        int is_prime = true;

        for(vector<int>::iterator iter = primes.begin(); iter != primes.end() ; iter++){
            if(num%*iter==0){
                is_prime = false;
                break;
            }
        }
        if(is_prime){
            
            primes.push_back(num);
        }
    }

    vector<int> answers;

    for(int num = min; num<= max  ; num++){
        int is_prime = true;
        if(num==1){
            continue;
        }
        else if(num==2){
            answers.push_back(num);
        }

        for(vector<int>::iterator iter = primes.begin(); iter != primes.end() ; iter++){
            if(num%*iter==0){
                is_prime = false;
                break;
            }
        }
        if(is_prime){
            if(num>primes.back())
                primes.push_back(num);
            answers.push_back(num);
        }
    }

    if(answers.size()){
        cout<< accumulate(answers.begin(), answers.end(),0) << '\n';
        cout<< answers.front() << '\n';
    }
    else{
        cout << -1 << '\n';
    }



    
}

    

    