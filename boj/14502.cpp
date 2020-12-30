#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int map[8][8];
vector<pair<int, int> > togo;

 int main(){
     int n , m;
     cin >> n >> m;
     for(int r = 0 ; r < n ; r++){
         for(int c= 0 ; c< m ; c++){
             cin >> map[r][c];
             if(map[r][c]==0){
                 togo.push_back(make_pair(r,c));
             }
         }
     }
     vector<bool> permutation(togo.size()-3,0);

     for(int i = 0 ; i < 3;  i++){
         permutation.push_back(1);
     }

     int max = -1;

     do{
         queue<pair<int ,int> > visit;
         int exp[n][m];
         bool check[n][m];
         int first, second,third;
         first = find(permutation.begin(),permutation.end(),1)-permutation.begin();
         second = find(permutation.begin()+first+1, permutation.end(),1) -permutation.begin();
         third = find(permutation.begin()+second+1, permutation.end(),1) -permutation.begin();

         
         for(int r= 0 ; r < n ; r++){
             for(int c= 0 ;c<m ; c++){
                 check[r][c] = false;
                 exp[r][c] = map[r][c];
                 if(exp[r][c]==2){
                     visit.push(make_pair(r,c));
                     check[r][c] = true;
                 }
                 else if(exp[r][c]==1){
                     check[r][c] = true;
                 }
                 
             }
         }

         exp[togo[first].first][togo[first].second] = check[togo[first].first][togo[first].second]  = 1;
         exp[togo[second].first][togo[second].second] = check[togo[second].first][togo[second].second] =1;
         exp[togo[third].first][togo[third].second] = check[togo[third].first][togo[third].second]=1;

        int move[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
         while(!visit.empty()){
             pair<int, int> cur = visit.front();
             visit.pop();

             for(int d = 0 ; d < 4 ;d++){
                 int nr = cur.first + move[d][0];
                 int nc = cur.second + move[d][1];
                 if(nr < 0 || nr >=n || nc < 0 || nc >=m || check[nr][nc])   continue;
                 check[nr][nc] = true;
                 exp[nr][nc] = 2;
                 visit.push(make_pair(nr,nc));                 
             }
         }

         int temp = 0;
         for(int r= 0 ; r < n ;r++){
             for(int c= 0 ; c< m ; c++){
                 if(exp[r][c]==0){
                     temp++;
                 }
             }
         }

         if(temp > max){
             max = temp;
         }


     }while(next_permutation(permutation.begin(),permutation.end()));

     cout << max << '\n';

     return 0;


 }