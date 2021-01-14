#include<iostream>
#include<vector>

using namespace std;

int arr[7][7];

int main(){
    int tc;
    scanf("%d",&tc);
    for(int test_case = 1 ; test_case <= tc ; test_case++){
        int n;
        scanf("%d",&n);

        vector<int> angle90;
        vector<int> angle180;
        vector<int> angle270;

        for(int r = 0 ; r < n ; r++){
            for(int c = 0 ; c < n ; c++){
                scanf("%d",&arr[r][c]);
            }
        }
        
        for(int c = 0 ; c < n ; c++){
            for(int r = n-1 ; r >= 0 ; r--){
                angle90.push_back(arr[r][c]);
            }
        }

        for(int r = n-1 ; r >= 0 ; r--){
            for(int c = n-1 ; c >= 0 ; c--){
                angle180.push_back(arr[r][c]);
            }
        }

        for(int c = n-1 ; c >= 0 ; c--){
            for(int r = 0 ; r < n ; r++){
                angle270.push_back(arr[r][c]);
            }
        }

        printf("#%d\n",test_case);

        for(int r = 0 ; r < n ; r++){
            for(int c = 0 ; c < n ; c++){
                printf("%d",angle90.front());
                angle90.erase(angle90.begin());
            }
            
            cout << " ";

            for(int c = 0 ; c < n ; c++){
                printf("%d",angle180.front());
                angle180.erase(angle180.begin());
            }
            cout << " ";

            for(int c = 0 ; c < n ; c++){
                printf("%d",angle270.front());
                angle270.erase(angle270.begin());
            }
            cout << " ";

            printf("\n");
        }

        for(int r = 0 ; r < n ; r++){
            for(int c = 0 ; c < n ; c++){
                arr[r][c] = 0;
            }
        }

    }
}