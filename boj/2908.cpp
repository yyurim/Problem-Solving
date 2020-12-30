#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int num1, num2;
    string num1_s, num2_s;
    cin >> num1 >> num2;

    num1_s = to_string(num1);
    num2_s = to_string(num2);

    reverse(num1_s.begin(),num1_s.end());
    reverse(num2_s.begin(),num2_s.end());

    int result = stoi(num1_s>num2_s ? num1_s: num2_s);
    cout << result <<'\n';    
}