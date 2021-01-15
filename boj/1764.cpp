#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

map<string, bool> memo;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    cin.ignore();

    for(int i = 0 ; i < n ;i+s+){
        string temp;
        getline(cin, temp);
        memo.insert(make_pair(temp,true));
    }

    vector<string> ans;
    for(int i = 0 ; i < m ; i++){
        string temp;
        getline(cin, temp);
        if(memo.find(temp) != memo.end()){
            ans.push_back(temp);
        }
    }

    sort(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << '\n';
    }

    return 0;
}