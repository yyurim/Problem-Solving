#include<iostream>
#include<vector>

using namespace std;

int main(){
    for(int tc = 1 ; tc <= 10 ; tc++){
        int t;
        scanf("%d",&t);
        int arr[4][4];
        for(int r= 0 ; r < 4 ; r++){
            for(int c = 0 ; c < 4 ; c++){
                int temp;
                scanf("%d",&temp);
                arr[r][c] = temp;
            }
        }

        bool visited[10000000];

        for(int s = 0 ; s < 16 ; s++){
            int now_r = s/4;
            int now_c = s%4;
            string number = "";
            
            
            

        }

    }
}