#include<iostream>
#include<vector>
#include<utility>

/*
***********************************
seg fault를 피하고 싶다면 행렬을 충분히 크게 만들기
***********************************

*/
 
using namespace std;
 
int main(){
    int t;
    scanf("%d",&t);
 
    for(int tc = 1 ; tc <=t ; tc++){
        int p,q;
        scanf("%d %d",&p,&q);
        pair<int,int> p_loc, q_loc;
 
        int arr[301][301];
        int val = 1;
        for(int i = 1 ; i <= 300 ; i++){
            int r = i;
            int c = 1;
 
            while(c <= i){
                if(p==val){
                    p_loc.first = r;
                    p_loc.second = c;
                }
 
                if(q==val){
                    q_loc.first = r;
                    q_loc.second = c;
                }
 
                arr[r][c] = val++;
                r--;
                c++;
            }
        }
 
        printf("#%d %d\n",tc, arr[p_loc.first+q_loc.first][p_loc.second+q_loc.second]);
    }
}