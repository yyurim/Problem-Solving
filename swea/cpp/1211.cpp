#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

int main(){
    for(int test_case = 1 ; test_case <= 1 ; test_case++){
        int t;
        scanf("%d",&t);

        int ladders[100][100];
        int now_r,now_c;

        vector<int> starting;
        vector<int> paths;

        for(int r = 0 ; r < 100 ; r++){
            for(int c = 0 ; c < 100 ; c++){
                scanf("%d",&ladders[r][c]);
                if( (r== 0) && ladders[r][c]==1 ){
                    starting.push_back(c);
                }
            }
        }

        for(int person = 0 ; person < starting.size() ; person++){
            now_r = 0;
            now_c = starting[person];
            int path = 0;
            while(now_r < 99){
                ladders[now_r][now_c] = 2;
                if(now_c > 0 && ladders[now_r][now_c-1]==1){
                    now_c--;
                }
                else if(now_c < 99 && ladders[now_r][now_c+1]==1){
                    now_c++;
                }
                else{
                    now_r++;
                }
                path++;
            }
            paths.push_back(path);
        }

        int min = starting[min_element(paths.begin(), paths.end())-paths.begin()];



        cout << "#"<<test_case <<" " << min<<'\n';
        
    }
}