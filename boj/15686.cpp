#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int map[50][50];

typedef struct _house{
    int loc[2];
}house;

int main(){
    int n , m;
    cin >> n >> m;

    vector<pair<int,int> > chicken;
    vector<house> houeses;
    for(int r = 0 ;r < n ; r++){
        for(int c= 0 ; c< n ; c++){
            cin >> map[r][c];
            if(map[r][c]==2){
                chicken.push_back(make_pair(r,c));
            }
            else if(map[r][c]==1){
                house new_h;
                new_h.loc[0] = r;
                new_h.loc[1] = c;
                houeses.push_back(new_h);
            }
        }
    }

    vector<bool> permuation(chicken.size()-m,0);
    for(int i = 0 ; i < m ; i++){
        permuation.push_back(1);
    }

    int ans = 987654321;
    do{

        int sum = 0;
        for(int i = 0 ; i < houeses.size() ; i++){
            int min_dist = 987654321;
            for(int c = 0 ; c < chicken.size() ; c++){
                if(permuation[c]){
                    int dist = abs(houeses[i].loc[0]-chicken[c].first)+abs(houeses[i].loc[1]-chicken[c].second);
                    min_dist = min(min_dist, dist);
                }
            }
            sum += min_dist;
        }
        ans = ans < sum ? ans : sum;

    }while(next_permutation(permuation.begin(), permuation.end()));

    cout << ans << '\n';
    return 0;

}