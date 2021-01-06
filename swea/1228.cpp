#include<iostream>
#include<sstream>
#include<vector>

using namespace std;

/*
*****************************
vector insert
(iterator(위치) , 갯수, value)
*****************************

*****************************
tokenizer
getline(스트림, temp 스트링, delimiter)
*****************************
*/


typedef struct _node{
    int value;
    node* next;

}node;

typedef node* Nptr;

class listClass{
    public:
        listClass();
        ~listClass();
        void Insert(int pos, int item);
        void Delete(int pos);
        //void Retrieve(int pos, int& item);
        bool IsEmpty();
        int Length();
    private:
        int count;
        Nptr head;
};

listClass::listClass(){
    count = 0;
    head = NULL;
}

listClass::~listClass(){
    while(!IsEmpty()){
        Delete(1);
    }
}

bool listClass::IsEmpty(){
    return (count==0); 
}

int listClass::Length(){
    return count;
}

void listClass::Insert(int pos, int item){
    Nptr temp;

    if((pos>count)||(pos<1)){
        cout << "out of range\n";
    }
    else{
        Nptr p = (node*)malloc(sizeof(node));
        p->value = item;
        if(pos==1){
            p->next = head->next;
            head = p;
        }
        else{
            Nptr temp = head;
            for(int i = 1; i < (pos-1) ; i++){
                temp = temp->next;
            }
            p->next = temp->next;
            temp->next = p;
        }

        count++;
    }
}

void listClass::Delete(int pos){
    Nptr temp;

    if(IsEmpty()){
        cout << "empty list\n";
    }
    else if( (pos > count)|| (pos < 1)){
        cout << "out of range\n";
    }
    else{
        if(pos == 1 ){
            Nptr p = head;
            head = head->next;
        }
        else{
            for(int i = 1 ; i < (pos-1) ; i++){
                temp = temp->next;
            }
            Nptr p = temp->next;
            temp->next = p->next;
        }
        count--;
    }


}

int main(){
    for(int tc = 1; tc <= 10 ; tc++){
        int n_cipher;
        scanf("%d",&n_cipher);
        vector<int> cipher;

        for(int i = 0 ; i < n_cipher ; i++){
            int temp;
            scanf("%d",&temp);
            cipher.push_back(temp);
        }

        int n_commands;
        scanf("%d",&n_commands);
        cin.ignore(256,'\n');
        
        string input_cipher;
        getline(cin, input_cipher);
        stringstream ss(input_cipher);
        string s_cipher;
        
        int c_it = 0;
        while(getline(ss, s_cipher, 'I')){
            if(c_it++ == 0) continue;
            stringstream cs(s_cipher);
            string cipher_temp;
            int pos;
            int p = 0;
            
            while(getline(cs, cipher_temp,' ')){
                if( p == 0 || p == 2){
                    p++;
                    continue;
                }
                else if( p == 1){
                    pos = stoi(cipher_temp);
                    p++;
                }
                else{
                    vector<int>::iterator it = cipher.begin();
                    cipher.insert(it+pos+p-3,1, stoi(cipher_temp));
                    p++;
                }
            }        
        }

        printf("#%d ",tc);
        for(int i = 0 ; i < 10 ; i++){
            printf("%d ",cipher[i]);
        }

        printf("\n");
    }
}













