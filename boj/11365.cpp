#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    string input;

    while(getline(cin, input)){
        if(input.compare("END")){
            reverse(input.begin(),input.end());
            cout << input<<endl;
        }
        else{
            break;
        }
    }

    return 0;
}