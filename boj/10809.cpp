#include <iostream>
#include <vector>

using namespace std;

int main(){
    string str;
    cin >> str;
    vector<int> alphabet;

    for(int i = 0; i < 26 ; i++){
        alphabet.push_back(-1);
    }

    for(int i = 0; i<str.length(); i++){
        int c_idx = str[i]-'a';
        if(alphabet[c_idx]==-1){
            alphabet[c_idx] = i;
        }
    }
    for(int i = 0; i < 26 ; i++){
        cout << alphabet[i] << ' ';
    }
    cout<< '\n';
}