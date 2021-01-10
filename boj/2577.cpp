#include<iostream>

using namespace std;

int memo[10];

int main(){
    int nums[3];

    int mul = 1;
    for(int i = 0 ; i < 3;  i++){
        scanf("%d", &nums[i]);
        mul *= nums[i];
    }

    string result = to_string(mul);

    for(int i = 0 ; i < result.size() ; i++){
        memo[result[i]-'0']++;
    }

    for(int i = 0 ; i < 10 ; i++){
        printf("%d\n",memo[i]);
    }

    return 0;


    
}