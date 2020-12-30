#include<iostream>
#include<vector>


using namespace std;


int main(){
    int tc;
    cin >> tc;
    
    for(int test_case =  1 ; test_case <= tc ; test_case++){
        int x,y,n,m;
        cin>> m >> n >> x >> y;
        vector<bool> check_row(n+1,0);
        vector<vector<bool> > check(m+1,check_row);

        int year = 1;
        int x_t = 1;
        int y_t = 1;
        int count = 0;
        while(1){
            if(check[x_t][y_t]){
                cout << -1 << '\n';
                break;
            }
            check[x_t][y_t] = true;
            if(x==x_t && y==y_t){
                cout << year << '\n';
                break;
            }
            x_t = x_t%m + 1;
            y_t = y_t%n + 1;
            year++;
        }
    }
    return 0;
}