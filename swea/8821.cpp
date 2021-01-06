#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int TC;
    cin >> TC;

    for(int test_case = 1; test_case <= TC ;test_case){
        string input;
        cin >> input;

        vector<char> is_in;

        for(int i = 0 ; i < input.length() ; i++){
            vector<char>::iterator check = find(is_in.begin(), is_in.end(), input[i]);
            if(is_in.end()==check){
                is_in.push_back(input[i]);
            }
            else{
                is_in.erase(check);
            }
        }

        cout << "#" <<to_string(test_case)+" "+to_string((is_in.size()))<<'\n';
    }
}