#include<iostream>
#include<vector>

using namespace std;

int main(){
    for(int test_case = 1; test_case <= 10 ; test_case++){
        int t;
        scanf("%d",&t);

        vector<int> q;

        for(int i = 0 ; i < 8 ; i++){
            int tmp;
            scanf("%d",&tmp);
            q.push_back(tmp);
        }

        int decrease = 1;
        while(q.back()!=0){
            int f = q.front() - decrease;
            q.erase(q.begin());
            if (f <0)
            	q.push_back(0);
            else
                q.push_back(f);
            decrease = 1+decrease%5;
        }

        printf("#%d ",test_case);
        for(int i = 0 ; i < 7 ; i++){
            printf("%d ", q[i]);
        }

        printf("%d\n",q.back());

    }
}