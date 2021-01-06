#include<iostream>
#include<list>

/*
**********************************

연결리스트
노드 따라 이동 -> 삽입/삭제할 위치까지
삽입하고 반복자++ -> 노드가 늘어났으니
삭제하고 반복자 업데이트 -> 삭제하면 삭제된 위치를 가리키므로 삭제된 위치로 업데이트해줘야 연속적인 삭제 가능
**********************************
*/




using namespace std;

int main(){
    for(int tc=1 ; tc <= 10 ; tc++){
        int n;
        scanf("%d",&n);

        list<int> cipher;
        for(int l = 0 ; l < n ; l++){
            int node;
            scanf("%d",&node);
            cipher.push_back(node);
        }

        int n_commands;
        scanf("%d",&n_commands);

        for(int c = 0 ; c < n_commands ; c++){
            char command;
            scanf(" %c",&command);
            int pos;
            scanf("%d",&pos);
            int size;
            scanf("%d",&size);
            list<int>::iterator it = cipher.begin();
            
            for(int i = 0 ; i < pos; i++){
                    it++;
            }
            
            if(command=='I'){
                for(int p = 0 ; p < size ; p++){
                    int new_c;
                    scanf("%d",&new_c);
                    cipher.insert(it,new_c);
                }
            }
            else if(command=='D'){
                for(int p = 0 ; p <size ; p++){
                    it = cipher.erase(it);
                }
                
            }
        }

        printf("#%d ",tc);
        list<int>::iterator it = cipher.begin();
        for(int i = 0 ; i < 10 ; i++){
            printf("%d ",*it++);
        }

        printf("\n");
        
    }
}