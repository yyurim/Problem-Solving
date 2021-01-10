#include<iostream>
#include<sstream>

using namespace std;

int main(){
    string input;
    getline(cin,input);
    
    stringstream ss(input);
    string temp;
    int cnt = 0;
    while(getline(ss,temp, ' ')){
        if(temp=="")    continue;
        cnt++;
    }

    cout << cnt << '\n';

    return 0;
}