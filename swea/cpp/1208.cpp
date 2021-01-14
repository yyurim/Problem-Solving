#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    for(int test_case = 1 ; test_case <= 10 ; test_case++){
        int tries;
        cin >> tries;
        cin.ignore(256, '\n');

        string input;
        getline(cin, input);
        stringstream ss(input);
        string tmp;

        vector<int> buildings;
        while(getline(ss, tmp, ' ')){
            buildings.push_back(stoi(tmp));
        }
        
        int diff;
        vector<int>::iterator max = max_element(buildings.begin(), buildings.end());
        vector<int>::iterator min = min_element(buildings.begin(), buildings.end());
        for(int i = 0 ; i<tries ; i++){
            if((min==max) || ((*max-*min) <= 1)){
                break;
            }
            else{
                buildings[max-buildings.begin()] = *max - 1;
                buildings[min-buildings.begin()] = *min + 1;
                max = max_element(buildings.begin(), buildings.end());
            	min = min_element(buildings.begin(), buildings.end());
                diff = *max - *min;
            }
        }

        cout << "#" << test_case << " "<< diff << '\n';


    }
}