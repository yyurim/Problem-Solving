#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int tc;
    scanf("%d",&tc);
    for(int test_case = 1 ; test_case <= tc ; test_case++){
        int num, n;
        scanf("%d %d",&num, &n);


        string input = to_string(num);

        

        cout << "#"<<test_case << " " <<input <<endl;

    }
}