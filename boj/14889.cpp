#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int map[20][20];

int main(){
    int n;
    cin >> n;

    for(int r= 0 ; r< n ; r++){
        for(int c= 0 ;c < n ; c++){
            cin >> map[r][c];
        }
    }

    vector<bool> people(n/2,0);
    for(int i = 0 ; i < n/2 ; i++){
        people.push_back(1);
    }

    int min_dist = 987654321;
    do{

        vector<int> team0;
        vector<int> team1;
        for(int i = 0 ; i < n ; i++){
            if(people[i]){
                team1.push_back(i);
            }
            else{
                team0.push_back(i);
            }
        }

        int s1 = 0;
        for(int i = 0 ; i < team1.size() ; i++){
            for(int j = 0 ;  j < team1.size() ; j++){
                if(i==j)    continue;
                s1 += map[team1[i]][team1[j]];
            }
        }

        int s0 = 0;
        for(int i = 0 ; i < team0.size() ; i++){
            for(int j = 0 ;  j < team0.size() ; j++){
                if(i==j)    continue;
                s0 += map[team0[i]][team0[j]];
            }
        }

        min_dist = abs(s1-s0) < min_dist ? abs(s1-s0):min_dist;

    }while(next_permutation(people.begin(), people.end()));

    cout << min_dist << '\n';

    return 0;


}