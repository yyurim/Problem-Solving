#include<iostream>
#include<vector>

using namespace std;

#define PLUS 0
#define MINUS 1
#define MUL 2
#define DIV 3


int cal_max(vector<int> &numbers,int idx, int plus, int minus, int mul, int div, int sum){
    if(idx >= numbers.size()){
        return sum;
    }
    if(plus <= 0 && minus <= 0 && mul <= 0 && div <=0){
        return sum;
    }

    int result = -1000000001;
    for(int op = 0 ; op < 4 ; op++){
        int temp = -1000000001;
        switch(op){
            case PLUS:
                if(plus<=0)   continue;
                temp = cal_max(numbers,idx+1,plus-1,minus,mul,div,sum+numbers[idx]);
            break;
            case MINUS:
                if(minus<=0)   continue;
                temp = cal_max(numbers,idx+1,plus,minus-1,mul,div,sum-numbers[idx]);
            break;
            case MUL:
                if(mul<=0)   continue;
                temp = cal_max(numbers,idx+1,plus,minus,mul-1,div,sum*numbers[idx]);
            break;
            case DIV:
                if(div<=0)   continue;
                temp = cal_max(numbers,idx+1,plus,minus,mul,div-1,int(sum/numbers[idx]));
            break;
        }
        result = result > temp ? result : temp;
    }
    return result;

}

int cal_min(vector<int> &numbers,int idx, int plus, int minus, int mul, int div, int sum){
    if(idx >= numbers.size()){
        return sum;
    }
    if(plus <= 0 && minus <= 0 && mul <= 0 && div <=0){
        return sum;
    }

    int result = 1000000001;
    for(int op = 0 ; op < 4 ; op++){
        int temp = 1000000001;
        switch(op){
            case PLUS:
                if(plus<=0)   continue;
                temp = cal_min(numbers,idx+1,plus-1,minus,mul,div,sum+numbers[idx]);
            break;
            case MINUS:
                if(minus<=0)   continue;
                temp = cal_min(numbers,idx+1,plus,minus-1,mul,div,sum-numbers[idx]);
            break;
            case MUL:
                if(mul<=0)   continue;
                temp = cal_min(numbers,idx+1,plus,minus,mul-1,div,sum*numbers[idx]);
            break;
            case DIV:
                if(div<=0)   continue;
                temp = cal_min(numbers,idx+1,plus,minus,mul,div-1,int(sum/numbers[idx]));
            break;
        }
        result = result < temp ? result : temp;
    }
    return result;

}



int main(){
    int n;
    cin >> n;
    vector<int> numbers(n);
    for(int i = 0 ; i < n ; i++){
        cin >> numbers[i];
    }

    vector<int> op(4);
    cin >> op[PLUS];
    cin >> op[MINUS];
    cin >> op[MUL];
    cin >> op[DIV];

    cout << cal_max(numbers, 1, op[PLUS],op[MINUS],op[MUL],op[DIV],numbers[0]) << '\n';
    cout << cal_min(numbers, 1, op[PLUS],op[MINUS],op[MUL],op[DIV],numbers[0]) << '\n';

    return 0;
    

}





/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
pair<int,int> calc(vector<int> &a, int index, int cur, int plus, int minus, int mul, int div) {
    int n = a.size();
    if (index == n) {
        return make_pair(cur, cur);
    }
    vector<pair<int,int>> res;
    if (plus > 0) {
        res.push_back(calc(a,index+1,cur+a[index],plus-1,minus,mul,div));
    }
    if (minus > 0) {
        res.push_back(calc(a,index+1,cur-a[index],plus,minus-1,mul,div));
    }
    if (mul > 0) {
        res.push_back(calc(a,index+1,cur*a[index],plus,minus,mul-1,div));
    }
    if (div > 0) {
        res.push_back(calc(a,index+1,cur/a[index],plus,minus,mul,div-1));
    }
    auto ans = res[0];
    for (auto p : res) {
        if (ans.first < p.first) {
            ans.first = p.first;
        }
        if (ans.second > p.second) {
            ans.second = p.second;
        }
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int plus, minus, mul, div;
    cin >> plus >> minus >> mul >> div;
    auto p = calc(a, 1, a[0], plus, minus, mul, div);
    cout << p.first << '\n';
    cout << p.second << '\n';
    return 0;
}
*/