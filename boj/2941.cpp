#include<iostream>

using namespace std;

int main(){

    string input;
    getline(cin, input);

    int cnt = 0;
    for(int i = 0 ; i < input.size() ; i++){
        cnt++;
        char now = input[i];
        switch(now){
            case 'c':
                if((i+1)<input.size()){
                    if(input[i+1]=='='||input[i+1]=='-'){
                        i++;
                    }
                }
            break;
            case 'd':
                if((i+1)<input.size()){
                    if(input[i+1]=='-'){
                        i++;
                    }
                    else if(input[i+1]=='z' && (i+2)<input.size()){
                        if(input[i+2]=='='){
                            i+=2;
                        }
                    }
                }
            break;

            case 'l':
            case 'n':
                if((i+1)<input.size()){
                    if(input[i+1]=='j'){
                        i++;
                    }
                }
            break;

            case 's':
            case 'z':
                if(input[i+1]=='='){
                        i++;
                }
            break;

        }
    }

    cout << cnt << '\n';

    return 0;
}