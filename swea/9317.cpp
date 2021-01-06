#include<iostream>
#include<vector>

using namespace std;

int main(){
    int tc;
    scanf("%d",&tc);
    for(int test_case = 1;  test_case <= tc ; test_case++){
        int n;
        scanf("%d",&n);
        cin.ignore(256,'\n');
        string input, answer;
        getline(cin, input);
        getline(cin, answer);
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(input[i]==answer[i]){
                count++;
            }
        }

        printf("#%d %d\n",test_case, count);
    }
}