#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int tries;
    cin >> tries;

    for(int i = 0 ; i< tries ; i++){
        short valid = 1;
        vector<char> paren;
        string parenthesis;
        cin >> parenthesis;
    
        for(int c = 0 ; c < parenthesis.size();c++){
            if(parenthesis[c]=='('){
                paren.push_back('(');
            }
            else{
                if(paren.empty()){
                    valid = 0;
                    break;
                }
                else{
                    paren.pop_back();
                }
            }
        }
        

        if(valid&&paren.empty()){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}