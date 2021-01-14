#include<iostream>
#include<sstream>
#include<list>

using namespace std;

typedef struct _node{
    int index;
    char value;
    int left;
    int right;
}node;

int main(){
    for(int tc = 1; tc <= 10 ; tc++){
        int n;
        scanf("%d",&n);
        list<node> tree;
        for(int i = 1 ; i <=n ; i++){
            string command;
            getline(cin, command);
            stringstream ss(command);
            string temp;
            int j = 0;
            node child;
            while(getline(ss, temp, ' ')){
                if ( j = 0 ){
                    child.index = stoi(temp);
                }
                else if( j == 1){
                    child.index = temp[0];
                }
                else if( j == 2){
                    child.left = stoi(temp);
                }
                else{
                    child.right = stoi(temp);
                }
                j++;
            }
            tree.push_back(child);

        }
    }
}