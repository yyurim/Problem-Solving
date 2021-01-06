#include<iostream>
#include<vector>

using namespace std;

int main(){
    int tc;
    scanf("%d",&tc);
    for(int test_case = 1; test_case <= tc ; test_case++){
        int N , M;
        scanf("%d %d",&N,&M);
        cin.ignore(256,'\n');
        char cipher[N+1][M+1];

        for(int r = 1 ; r <= N ;r++){
            string s;
            getline(cin,s);
            for(int c = 1; c<=M ; c++){
                cipher[r][c] = s[c-1];
            }
        }
        
        int find_r = 0;
        int find_c = 0;

        for(int r = N ; r >= 1 ;r--){
            for(int c = M; c>=1 ; c--){
                if(cipher[r][c]=='1'){
                    find_r = r;
                    find_c = c;
                    break;
                }
            }
        }

        string cipher_string;

        for(int i = 0 ; i < 56 ; i++){
            cipher_string.push_back(cipher[find_r][find_c-i]);
        }
        
        string word = "";
        vector<int> check;
        int sum = 0;

        for(int i = 1 ; i <=56 ; i++){
            word += cipher_string[i-1];
            if(i%7==0){
                //cout << word << endl;
                if(word=="1011000"){
                    check.push_back(0);
                    sum +=0;
                }
                else if(word=="1001100"){
                    check.push_back(1);
                    sum +=1;
                }
                else if(word=="1100100"){
                    check.push_back(2);
                    sum +=2;
                }
                else if(word=="1011110"){
                    check.push_back(3);
                    sum +=3;
                }
                else if(word=="1100010"){
                    check.push_back(4);
                    sum +=4;
                }
                else if(word=="1000110"){
                    check.push_back(5);
                    sum +=5;
                }
                else if(word=="1111010"){
                    check.push_back(6);
                    sum +=6;
                }
                else if(word=="1101110"){
                    check.push_back(7);
                    sum +=7;
                }
                else if(word=="1110110"){
                    check.push_back(8);
                    sum +=8;
                }
                else if(word=="1101000"){
                    check.push_back(9);
                    sum +=9;
                }
                else{

                    break;
                }

                word = "";

            }
        }
        
        int is_valid = check[0] + check[2] + check[4] + check[6] + 3*(check[1] + check[3] + check[5] + check[7]);

        int is_cipher;
        if(is_valid%10){
            is_cipher = 0;
        }
        else{
            is_cipher = sum;
        }

        printf("#%d %d\n",test_case, is_cipher);


    }
}