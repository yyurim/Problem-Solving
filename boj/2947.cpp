#include <string>
#include <vector>
#include <iostream>
/*
****************

반례 주의

****************
*/

using namespace std;

int main(){
    string str;
    cin >> str;
    
    vector<char> word;
    
    int word_num=0;
    
    for(int i = 0 ; i < str.size() ; i++){
        if(word.empty()){
            if(str[i]=='c' || str[i]=='d' || str[i]=='l' || str[i]=='n' || str[i]=='s' || str[i]=='z'){
                word.push_back(str[i]);
            }
            word_num++;
            cout <<" is empty and top : " << str[i] << '\n';
        }
        else{
            char top = word.back();
            word.pop_back();
            if(top=='c' || top=='d' || top=='l' || top=='n' || top=='s' || top=='z'){
                if(((top=='c')||(top=='s')||(top=='z'))&&((str[i]=='='))){
                    //word_num++;
                    cout << top << str[i] << '\n';

                }
                else if(((top=='c')||(top=='d'))&&(str[i]=='-')){
                    //word_num++;
                    cout << top << str[i] << '\n';

                }
                else if(((top=='l')||(top=='n'))&&(str[i]=='j')){
                    //word_num++;
                    cout << top << str[i] << '\n';

                }
                else if((top=='d')&&(str[i]=='z')){
                    
                    if((str[i+1]!='=')){
                        cout << "only dz" << '\n';
                        word_num++;
                    }
                    else{
                        word.push_back(str[i]);
                    }
                }
                else{
                    if(str[i]=='c' || str[i]=='d' || str[i]=='l' || str[i]=='n' || str[i]=='s' || str[i]=='z'){
                        word_num++;
                        word.push_back(str[i]);
                        continue;
                    }
                    word_num++;
                
                }
            }
        }
        
        
    }
    
    cout << word_num << '\n';
    
    
    
}