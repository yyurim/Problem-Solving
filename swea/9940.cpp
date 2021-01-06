#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int TC;
    scanf("%d",&TC);
    for(int test_case = 1 ; test_case <= TC ; test_case++){
        int n;
        scanf("%d",&n);

        int check[n];
        string answer = "Yes";

        for(int i = 0 ; i < n ; i++){
            check[i] = 0;
        }

        for(int i = 0 ;  i < n  ; i++){
            int tmp;
            scanf("%d",&tmp);
            if (tmp<=n && tmp>0)
            {
                check[tmp-1] = 1;
            }
        }

        for(int i = 0 ; i < n ; i++){
            if(check[i]==0){
                answer = "No";
                break;
            }
        }

        // cout으로 프린트
        printf("#%d %s\n",test_case,answer);


    
    }
}