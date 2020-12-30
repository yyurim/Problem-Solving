#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string str;
    cin>> str;
    
    vector<int> alphabet;
    int is_multiple = 0;

    for(int a = 0 ; a <26 ; a++){
        alphabet.push_back(0);
    }
    
    for(int i = 0 ; i < str.length(); i++){
        str[i] = toupper(str[i]);
        alphabet[str[i]-'A']++;
    }

    vector<int>::iterator max = max_element(alphabet.begin(), alphabet.end());
    
    for(int a = 0 ; a <26 ; a++){
        if(alphabet[a]==*max){
            is_multiple++;
        }
    }
    
    if(is_multiple<=1){
        char max_alpha = distance(alphabet.begin(), max) + 'A';
        cout << max_alpha << '\n';
    }
    else{
        cout << "?" << '\n';
    }

    

    

}