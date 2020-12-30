#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

int map[20][20];
bool check[20][20];

typedef struct _passenger{
    int start[2];
    int dest[2];
    int dist_taxi;
    int dist_start2dest;
}passenger;


typedef struct _state{
    int loc[2];
    int fuel;
    int passenger_num;
    int passenger_dist;
}state;

bool compare(passenger &a, passenger &b){
    if(a.dist_taxi < b.dist_taxi){
        return true;
    }
    else if(a.dist_taxi > b.dist_taxi){
        return false;
    }
    else{
        if(a.start[0] < b.start[0]){
            return true;
        }
        else if(a.start[0] > b.start[0]){
            return false;
        }
        else{
            if(a.start[1] < b.start[1]){
                return true;
            }
            else{
                return false;
            }

        }
    }
}

void bfs_taxi_pass(int n, state &taxi, passenger &pass){
    queue<pair<pair<int,int >, int> > visit;
    visit.push(make_pair(make_pair(taxi.loc[0],taxi.loc[1]),0));

    bool check_loc[20][20];
    memcpy(check_loc, check, sizeof(check));
    check_loc[taxi.loc[0]][taxi.loc[1]] = true;

    
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    while(!visit.empty()){
        pair<int,int> cur = visit.front().first;
        int dist = visit.front().second;
        visit.pop();
        if(cur.first==pass.start[0] && cur.second==pass.start[1]){
            pass.dist_taxi = dist;
            return;
        }

        for(int d = 0 ; d < 4 ; d++){
            int nr = cur.first + dir[d][0];
            int nc = cur.second + dir[d][1];
            if(nr < 0 || nr >= n || nc < 0 || nc >= n || check_loc[nr][nc]) continue;
            if(map[nr][nc]==1)  continue;
            check_loc[nr][nc] = true;
            visit.push(make_pair(make_pair(nr,nc),dist+1));
        }
    }

    pass.dist_taxi = -1;
    return;

}

void bfs_start2dest(int n, passenger &pass){
    queue<pair<pair<int, int>, int> > visit;
    visit.push(make_pair(make_pair(pass.start[0],pass.start[1]), 0));

    bool check_loc[20][20];
    memcpy(check_loc, check, sizeof(check));
    check_loc[pass.start[0]][pass.start[1]] = true;

    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int dist;
    while(!visit.empty()){
        pair<int,int> cur = visit.front().first;
        dist = visit.front().second;

        visit.pop();

        if(cur.first==pass.dest[0] && cur.second==pass.dest[1]){
            pass.dist_start2dest = dist;
            return;
        }
        
        for(int d = 0 ; d <4 ;d++){
            int nr = cur.first + dir[d][0];
            int nc = cur.second + dir[d][1];
            if(nr < 0 || nr >= n || nc < 0 || nc >= n || check_loc[nr][nc]) continue;
            if(map[nr][nc]==1)  continue;
            check_loc[nr][nc] = true;
            
            visit.push(make_pair(make_pair(nr,nc),dist+1));
        }

    }

    return;


}



int main(){
    int n, m , k;
    cin >> n >> m >> k;

    for(int r = 0 ; r < n ; r++){
        for(int c= 0 ; c < n ; c++){
            cin >> map[r][c];
            check[r][c] = map[r][c] > 0 ? 1 : 0;
        }
    }

    queue<state> taxi;
    state init;
    cin >> init.loc[0] >> init.loc[1];
    init.loc[0]--;
    init.loc[1]--;
    init.fuel = k;
    init.passenger_num = -1;

    vector<passenger> passengers(m);
    int start_pass = 987654321;
    for(int i =  0 ; i < m ;i++){
        cin >> passengers[i].start[0] >> passengers[i].start[1] >> passengers[i].dest[0] >> passengers[i].dest[1];
        passengers[i].start[0]--;
        passengers[i].start[1]--;
        passengers[i].dest[0]--;
        passengers[i].dest[1]--;
        passengers[i].dist_taxi = 0;

        ///// taxiiiii
        bfs_taxi_pass(n, init, passengers[i]);

        ///start to dest
        bfs_start2dest(n, passengers[i]);
    }

    sort(passengers.begin(), passengers.end(), compare);
    init.passenger_num = 0;
    init.passenger_dist = passengers[0].dist_taxi;

    taxi.push(init);

    // cout << "init fuel >> " << init.fuel<<endl;
    while(!taxi.empty()){
        state cur = taxi.front();
        taxi.pop();
        if(cur.passenger_dist < 0){
            cout << -1 << '\n';
            return 0;
        }
        cur.fuel -= cur.passenger_dist;
        if(cur.fuel<0){
            cout << -1 << '\n';
            return 0;
        }

        // cout << "passenger ride >> " << cur.fuel << endl;
        // cout << "pass dist >> " << cur.passenger_dist << endl;
        // cout << "to dest >> " << passengers[cur.passenger_num].dist_start2dest << endl;

        cur.fuel -= passengers[cur.passenger_num].dist_start2dest ;
        if(cur.fuel<0){
            cout << -1 << '\n';
            return 0;
        }
        
        cur.fuel += 2*(passengers[cur.passenger_num].dist_start2dest);
        cur.loc[0] = passengers[cur.passenger_num].dest[0];
        cur.loc[1] = passengers[cur.passenger_num].dest[1];
        passengers.erase(passengers.begin()+cur.passenger_num);

        if(passengers.empty()){
            cout<< cur.fuel << '\n';
            return 0;
        }
        else{
            for(int i = 0; i < passengers.size(); i++){
                bfs_taxi_pass(n,cur,passengers[i]);
            }
            sort(passengers.begin(), passengers.end(), compare);
            cur.passenger_num = 0;
            cur.passenger_dist = passengers[0].dist_taxi;
        }

        taxi.push(cur);

    }

    return 0;


}