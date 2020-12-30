#include <vector>
#include <string>
#include <iostream>
#include <utility>

using namespace std;

vector<int> push(vector<int> arr, int n){
    arr.push_back(n);
    cout << "pushed !!! " << endl;

    return arr;
}

pair<vector<int>,int> pop(vector<int> arr){
    if(arr.empty()){
        return make_pair(arr, -1);
    }
    else{
        int temp = arr.back();
        arr.pop_back();
        return make_pair(arr, temp);
    }
}
int size(vector<int> arr){
    return arr.size();
}
int empty(vector<int> arr){
    return arr.empty();
}
int top(vector<int> arr){
    if(arr.empty()){
        return -1;
    }
    else{
        return arr.back();
    }
}


int main(){
    int tries;
    cin >> tries;
    vector<int> arr;
    for(int i = 0 ; i<tries; i++){
        string inst;
        cin >> inst;
        
        if(inst=="push"){
            cin.ignore();
            int value;
            cin >> value;
            arr = push(arr, value);
        }
        else if(inst=="pop"){
            pair<vector<int>,int> poped = pop(arr);
            arr = poped.first;
            cout << poped.second<<endl;
            
        }
        else if(inst=="size"){
            cout << size(arr)<<endl;
        }
        else if(inst=="empty"){
            cout << empty(arr)<<endl;
        }
        else if(inst=="top"){
            cout << top(arr)<<endl;
        }       
    }
}