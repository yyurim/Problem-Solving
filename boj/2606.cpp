#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dfs(vector<vector<int> > &computers, vector<bool> &check, int now, int count){
    if(count > computers.size()){
        return;
    }

    check[now] = 1;
    for(int i = 0 ; i < computers[now].size() ; i++){
        if(check[computers[now][i]])    continue;
        dfs(computers, check, computers[now][i], count+1);
    }

    return;
    
}

int main(){
    int n, k;
    cin >> n;
    vector<vector<int> > computers(n);
    vector<bool> check(n, false);

    cin >> k;
    for(int i = 0 ; i < k ; i++){
        int in,out;
        cin >> in >> out;
        computers[in-1].push_back(out-1);
        computers[out-1].push_back(in-1);
    }

    dfs(computers, check, 0, 0);

    int count = 0;
    for(int i = 0 ; i < n ; i++){
        if(check[i])    count++;
    }

    cout << count-1 << '\n';

    return 0;

}