#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;


int main(){
    int TC;
    cin >> TC;

    for(int test_case = 1; test_case <= TC ; test_case++){
        int lev;
        cin >> lev;
        cin.ignore(256, '\n');
         
        string tmp;
        string input;
        getline(cin,input);
 
        stringstream ss(input);
 
        vector<int> bintree;
        while(getline(ss, tmp, ' ')){
            bintree.push_back(stoi(tmp));
        }
 
        cout << "#"<< to_string(test_case)+" ";
 
        for(int l = 1 ; l <= lev ; l++){
            int n = (int)pow(2,l-1);
            int init = (int)pow(2,lev-l);
            int step = (int)pow(2,lev-l+1);
            for(int c = 0 ; c < n ; c++){
                cout<< bintree[init-1  + c*(step)] << " ";
            }
            cout << '\n' ;
        }

    }
}

