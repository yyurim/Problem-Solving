#include<iostream>
#include<sstream>
#include<vector>
#include<utility>

using namespace std;

/*
***********************************************
bruteforce
갔던 경로에 들어서지 않도록 재정의 해줘야해
***********************************************
*/

int main(){
    for(int test_case = 1 ; test_case <= 1 ; test_case++){
        int t;
        scanf("%d",&t);

        int ladders[100][100];
        int now_r,now_c;

        for(int r = 0 ; r < 100 ; r++){
            for(int c = 0 ; c < 100 ; c++){
                scanf("%d",&ladders[r][c]);
                if(ladders[r][c]==2){
                    now_r = r;
                    now_c = c;
                }
            }
        }

        cout <<" now c " << now_c <<"   now r"<<now_r<<endl;

        while(now_r > 0){
            ladders[now_r][now_c] = 2;
            if(now_c > 0 && ladders[now_r][now_c-1]==1){
                now_c--;
            }
            else if(now_c < 99 && ladders[now_r][now_c+1]==1){
                now_c++;
            }
            else{
                now_r--;
            }
        }

        cout << "#"<<test_case <<" " << now_c<<'\n';
        
    }
}