#include<iostream>
#include<vector>

using namespace std;

int main(){
    for(int test_case = 0 ; test_case <= 10 ; test_case++){
        int t;
        scanf("%d",&t);

        string str;
        getline(cin, str);

        string question;
        getline(cin, question);

        int count = 0;
        for(int s = 0 ; s < question.length() ; s++){
            if(question[s]==str[0]){
                int found = 1;
                for(int i = 0 ; i < str.length() ; i++){
                    if(s+i <= question.length()){
                        if(question[s+i]!=str[i]){
                            found = 0;
                            break;
                        }
                    }
                }
                if(found){
                    count++;
                }
            }
        }

        printf("#%d %d\n",t, count);

    }
}