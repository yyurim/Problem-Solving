#include<iostream>
#include<vector>

using namespace std;

int main(){
    for(int test_case = 1 ; test_case <= 10 ; test_case++){
        int n;
        scanf("%d",&n);
        cin.ignore(256,'\n');

        string input;
        getline(cin, input);
        
        vector<char> op;
        vector<char> postfix;
        vector<int> cal;

        for(int i = 0 ; i < n ; i++){
            if(input[i]=='+'){
                if(op.empty())
                    op.push_back(input[i]);
                else
                    postfix.push_back(input[i]);
            }
            else{
                postfix.push_back(input[i]);         
            }
        }
        
        while(op.empty()!=1){
            postfix.push_back(op.back());
            op.pop_back();
        }

        for(int i = 0 ; i < n ; i++){
            if(postfix[i]!='+'){
                cal.push_back(postfix[i] - '0');
            }
            else{
                int second = cal.back();
                cal.pop_back();
                int first = cal.back();
                cal.pop_back();

                int sum = first + second;
                cal.push_back(sum);

            }
        }


        printf("#%d %d\n",test_case, cal[0]);



    }
}