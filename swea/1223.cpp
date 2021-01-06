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
                else{
                    while(op.empty()==0){
                        postfix.push_back(op.back());
                        op.pop_back();
                    }
                    op.push_back(input[i]);
                }
            }
            else if(input[i]=='*'){
                if(op.empty()){
                    op.push_back(input[i]);
                }
                else{
                    if(op.back()=='+'){
                        op.push_back(input[i]);
                    }
                    else{
                        
                        while(op.empty()==0 && op.back()!='+'){
                            postfix.push_back(op.back());
                            op.pop_back();
                        }

                        op.push_back(input[i]);

                    }
                }
            }
            else{
                postfix.push_back(input[i]);         
            }
        }
        
        while(op.empty()==0){
            postfix.push_back(op.back());
            op.pop_back();
        }

        for(int i = 0 ; i < n ; i++){
            if(postfix[i]!='+' && postfix[i]!='*'){
                cal.push_back(postfix[i] - '0');
            }
            else{
                int second = cal.back();
                cal.pop_back();
                int first = cal.back();
                cal.pop_back();

                
                if(postfix[i]=='*'){
                    cal.push_back(first*second);
                }
                else{
                    cal.push_back(first+second);
                }
                

            }
        }


        printf("#%d %d\n",test_case, cal[0]);



    }
}