#include<iostream>
#include<list>

using namespace std;

int main(){   
    for(int tc = 1 ; tc <= 10 ; tc++){
        list<int> cipher;
        
        
        
        int n_cipher;
        scanf("%d",&n_cipher);
        for(int i = 0 ; i < n_cipher ; i++){
            int c;
            scanf("%d",&c);
            cipher.push_back(c);
        }

        int n_commands;
        scanf("%d",&n_commands);
        for(int i  = 0 ; i < n_commands ; i++){
            char command;
            scanf(" %c",&command);
            int pos, num;
            list<int>::iterator it = cipher.begin();
            switch(command){
                case 'I':
                    scanf("%d %d", &pos, &num);
                    for(int j = 0 ; j < pos ; j++) it++;
                    for(int j = 0 ; j < num ; j++){
                        int new_c;
                        scanf("%d",&new_c);
                        cipher.insert(it,new_c);
                    }
                    break;
                case 'D':
                    scanf("%d %d", &pos, &num);
                    for(int j = 0 ; j < pos ; j++) it++;
                    for(int j = 0 ; j < num ; j++) it = cipher.erase(it);
                    break;
                case 'A':
                    scanf("%d",  &num);
                    for(int j = 0 ; j < num ; j++){
                        int new_c;
                        scanf("%d",&new_c);
                        cipher.push_back(new_c);
                    }
                    break;
                default:
                    cout << "hey.. you got wrong...."<<endl;
                    break;
            }
        }

        printf("#%d ",tc);
        for(int i = 0 ; i < 10 ; i++){
            printf("%d ",cipher.front());
            cipher.pop_front();
        }
        printf("\n");

    }
}