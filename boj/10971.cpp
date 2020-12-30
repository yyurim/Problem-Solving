#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int map[10][10];

int main(){
    int n;
    cin >> n;
    vector<int> cities(n);
    for(int i = 0 ; i < n ; i++){
        cities[i] = i;
    }

    for(int r = 0 ; r < n ; r++){
        for(int c = 0 ; c < n ; c++){
            cin >> map[r][c];
        }
    }

    int min = 987654321;

    do{
        int cost = 0;
        bool flag = false;
        for(int i = 0 ; i < n-1 ; i++){
            int from = cities[i];
            int to = cities[i+1];
            if(map[from][to] > 0){
                cost += map[from][to];
            }
            else{
                flag = true;
                break;
            }
        }

        if(map[cities[n-1]][cities[0]] <= 0)    continue;
        else{
            cost += map[cities[n-1]][cities[0]];
        }
        if(flag)    continue;

        if(cost < min) min = cost;

    }while(next_permutation(cities.begin(),cities.end()));

    cout << min << '\n';
    return 0;

}