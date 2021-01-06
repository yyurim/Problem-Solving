#include<iostream>
#include<vector>

using namespace std;

int main(){
    for(int test_case = 1 ; test_case <= 10 ; test_case++){
        int len;
        scanf("%d",&len);
        cin.ignore(256, '\n');

        char question[8][8];

        for(int r = 0 ; r<8 ; r++){
            string line;
            getline(cin, line);
            for(int c = 0 ; c < 8 ; c++){
                question[r][c] = line[c];
            }
        }
        int count = 0;
        

        for(int w = 0 ; w < 64 ; w++){
            vector<char> is_answer;
            if(w%8+len <= 8){
                int i;
                for(i = 0 ; i < (len/2) ; i++){
                    is_answer.push_back(question[w/8][w%8+i]);
                }
                if(len%2)   i++;
                for(; i < len; i++){
                    if(is_answer.back() == question[w/8][w%8+i]){
                        is_answer.pop_back();
                    }
                }
                if(is_answer.empty()){
                    count++;
                }
            }
            else{
                continue;
            } 
        }

        for(int c = 0 ; c < 64 ; c++){
            vector<char> is_answer;
            if(c/8+len <= 8){
                int i;
                for(i = 0 ; i < (len/2) ; i++){
                    is_answer.push_back(question[i+c/8][c%8]);
                }
                if(len%2)   i++;
                for(; i < len; i++){
                    if(is_answer.back() == question[i+c/8][c%8]){
                        is_answer.pop_back();
                    }
                }
                if(is_answer.empty()){
                    count++;
                }
            }
            else{
                continue;
            } 
        }

            
            
        

        printf("#%d %d\n",test_case, count);


    }
}