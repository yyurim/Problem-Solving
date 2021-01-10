#include<iostream>
#include<algorithm>
#include<sstream>

using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 0;  i < n ; i++){
        string input;
        getline(cin, input);
        string word;

        stringstream ss(input);
        while(getline(ss, word, ' ')){
            reverse(word.begin(), word.end());
            cout << word << ' ';
        }
        cout << '\n';
    }

    return 0;
}