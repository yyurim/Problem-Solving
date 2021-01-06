#include <iostream>
#include <vector>

using namespace std;

int main(){
    int TC;
    cin >> TC;

    for(int test_case = 1 ; test_case <= TC ;test_case++){
        int num;
        cin >> num;

        string input;
        cin >> input;

        vector<char> chars;
        int flag = 1;

        for(int c = 0 ; c < num ; c++){
            if( (input[c]=='(') || (input[c]=='[') || (input[c]=='{') || (input[c]=='<')){
                chars.push_back(input[c]);
            }
            else{
                if(input[c]==')'){
                    if(chars.back()!='('){
                        flag = 0;
                        break;
                    }
                    else{
                        chars.pop_back();
                    }
                }
                else if(input[c]==']'){
                    if(chars.back()!='['){
                        flag = 0;
                        break;
                    }
                    else{
                        chars.pop_back();
                    }
                }
                else if(input[c]=='>'){
                    if(chars.back()!='<'){
                        flag = 0;
                        break;
                    }
                    else{
                        chars.pop_back();
                    }
                }
                else if(input[c]=='}'){
                    if(chars.back()!='{'){
                        flag = 0;
                        break;
                    }
                    else{
                        chars.pop_back();
                    }
                }
            }
        }

        cout << "#"+to_string(test_case)+" " << flag << '\n';
    }
}