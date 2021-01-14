#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){

    for(int i = 0 ; i<1 ; i++){
        int building_num;
        cin >> building_num;
        cin.ignore(256,'\n');

        string input;
        string building;
        vector<int> buildings;

        getline(cin, input);
        stringstream ss(input);
        while(getline(ss, building, ' ')){
            buildings.push_back(stoi(building));
        }

        int answer = 0;


        for(int b = 2 ; b < (buildings.size()-2) ; b++){
            vector<int> side;
            side.push_back(buildings[b-2]);
            side.push_back(buildings[b-1]);
            side.push_back(buildings[b+1]);
            side.push_back(buildings[b+2]);
            int max = *(max_element(side.begin(),side.end()));

            if(max < buildings[b]){
                answer += buildings[b]-max;
            }
        }

        cout<< "#" << to_string(i+1) << " "<<to_string(answer) << '\n';

    }

}