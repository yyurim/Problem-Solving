#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int map[101][101];

int bfs(int n, int h, vector<vector<bool> > &check){
    int count = 0;
    int move[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    for(int r = 0 ;r < n ; r++){
        for(int c = 0 ; c < n ; c++){
            if(map[r][c] >= h && !check[r][c]){
                count++;
                pair<int, int> s = make_pair(r,c);
                queue<pair<int, int> > visited;

                visited.push(make_pair(s.first,s.second));
                check[s.first][s.second] = true;

                while(!visited.empty()){
                    pair<int, int> now = visited.front();
                    visited.pop();
                    for(int i = 0 ; i < 4 ; i++){
                        int nr = now.first + move[i][0];
                        int nc = now.second + move[i][1];
                        if(nr < 0 || nr >= n || nc < 0 || nc >= n || check[nr][nc]){
                            continue;
                        }
                        check[nr][nc] = true;

                        if(map[nr][nc] < h) continue;

                        visited.push(make_pair(nr, nc));
                        
                    }
                }

            }
        }
    }

    // cout << endl;
    // for(int r = 0 ; r < n ; r++){
    //     for(int c = 0 ; c < n ; c++){
    //         cout << check[r][c] << ' ';
    //     }
    //     cout << endl;
    // }

    return count;

}

int main(){
    int n;
    cin >> n;

    vector<int> numbers;

    for(int r = 0 ; r <  n ; r++){
        for(int c = 0 ; c < n ; c++){
            cin >> map[r][c];
            numbers.push_back(map[r][c]);

        }
    }

    sort(numbers.begin(),numbers.end());
    numbers.erase(unique(numbers.begin(),numbers.end()),numbers.end());

    int max = 0;

    for(int i = 0; i < numbers.size() ; i++){
        int temp;
        int h = numbers[i];
        vector<bool> check_rows(n, false);
        vector<vector<bool> > check(n, check_rows);
        temp = bfs(n, h, check);
        if(temp > max){
            max = temp;
        }
    }

    cout << max << '\n';

    return 0;



}

/*
언제 등호가 들어가야하는지 !!!!!!
문제를 읽어봐..
*/