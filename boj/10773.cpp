#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(){
    int n;
    cin >> n ;

    vector<int> numbers;

    for(int i = 0 ; i < n ; i++){
        int input;
        cin >> input;
        if(input==0){
            if(numbers.size()==0){
                continue;
            }
            else{
                numbers.pop_back();
            }
        }
        else{
            numbers.push_back(input);
        }
    }

    cout << accumulate(numbers.begin(),numbers.end(),0)<< '\n';



}