#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define PLUS 0
#define MINUS 1
#define MUL 2
#define DIV 3

int main(){
    int n;
    cin >> n;

    vector<int> numbers(n);
    vector<int> operators(4);
    for(int i = 0 ;i < n ; i++){
        cin >> numbers[i];
    }

    for(int i = 0 ; i < 4 ; i++){
        cin >> operators[i];
    }

    vector<int> types(operators[PLUS]+operators[MINUS]+operators[MUL]+operators[DIV]);

    int min = 100000001;
    int max = -100000001;
    
    for(int i = 0 ;i < operators[PLUS]; i++){
        types[i] = PLUS;
    }
    for(int i = operators[PLUS] ;i < operators[PLUS]+operators[MINUS]; i++){
        types[i] = MINUS;
    }
    for(int i = operators[PLUS]+operators[MINUS] ;i < operators[PLUS]+operators[MINUS]+operators[MUL]; i++){
        types[i] = MUL;
    }
    for(int i = operators[PLUS]+operators[MINUS]+operators[MUL] ;i < operators[PLUS]+operators[MINUS]+operators[MUL]+operators[DIV]; i++){
        types[i] = DIV;
    }

    do{
        int sum = numbers[0];

        for(int i = 0 ; i < types.size(); i++){
            switch(types[i]){
                case PLUS:
                    sum += numbers[i+1];
                break;
                case MINUS:
                    sum -= numbers[i+1];
                break;
                case MUL:
                    sum *= numbers[i+1];
                break;
                case DIV:
                    sum = int(sum/numbers[i+1]);
                break;
            }
        }

        if(sum > max){
            max = sum;
        }

        if(sum < min){
            min = sum;
        }
        

    }while(next_permutation(types.begin(),types.end()));

    cout << max << '\n';
    cout << min << '\n';

    return 0;

}




/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int calc(vector<int> &a, vector<int> &b) {
    int n = a.size();
    int ans = a[0];
    for (int i=1; i<n; i++) {
        if (b[i-1] == 0) {
            ans = ans + a[i];
        } else if (b[i-1] == 1) {
            ans = ans - a[i];
        } else if (b[i-1] == 2) {
            ans = ans * a[i];
        } else {
            ans = ans / a[i];
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
    vector<int> b;
    for (int i=0; i<4; i++) {
        int cnt;
        cin >> cnt;
        for (int k=0; k<cnt; k++) {
            b.push_back(i);
        }
    }
    sort(b.begin(),b.end());
    vector<int> result;
    do {
        int temp = calc(a, b);
        result.push_back(temp);
    } while (next_permutation(b.begin(), b.end()));
    auto ans = minmax_element(result.begin(), result.end());
    cout << *ans.second << '\n';
    cout << *ans.first << '\n';
    return 0;
}
*/