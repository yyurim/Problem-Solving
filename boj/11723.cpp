#include<iostream>
#include<cstring>
using namespace std;


int main(){
    int n;

    scanf("%d",&n);


    int result = 0;
    for(int i = 0 ; i < n ; i++){
        char input[10];
        int value;
        
        scanf("%s %d",input,&value);

        value = 1 << (value-1);



        if(!strcmp(input,"add")){
            result = result | value;
        }else if(!strcmp(input,"remove")){
            result = result & ~value;
        }else if(!strcmp(input,"check")){
            if(result & value){
                printf("1\n");
            }
            else{
                printf("0\n");
            }

        }else if(!strcmp(input,"toggle")){
            if(result & value){
                result = result & ~value;
            }
            else{
                result = result | value;
            }
            
        }else if(!strcmp(input,"all")){
            result = (1<<21)-1;
        }else if(!strcmp(input,"empty")){
            result = 0;
        }
    }

    return 0;

}