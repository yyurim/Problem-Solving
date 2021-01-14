#include<iostream>
 
using namespace std;
 
int main(){
    int tc;
    scanf("%d",&tc);
    for(int test_case = 1; test_case <= tc ; test_case++){
        float p ,q;
        scanf("%f %f",&p, &q);
        if( 2*p - p*q > 1){
            printf("#%d YES\n",test_case);
        }
        else{
            printf("#%d NO\n",test_case);
        }
    }
     
    return 0;
}