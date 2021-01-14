#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){
    int T;
    cin >> T;
    cin.ignore(256, '\n');
    for(int test_case = 0 ; test_case < T ; test_case++){
        int scores[101] = {0,};
        string score;
        
        string number;
        cin >> number;
        cin.ignore(256, '\n');

        string input;
        getline(cin, input);
        stringstream ss(input);
        while(getline(ss, score,' ')){
            scores[stoi(score)]++;
        }
        int max_score = 0;

        for(int i = 0 ; i < 101 ; i++){
            if(scores[max_score] <= scores[i]){
                max_score = i;
            }
        }

        cout << "#"<< number << " "<<to_string(max_score)<<'\n';

    }
    
    
}