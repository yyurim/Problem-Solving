#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void decrypt(vector<char> &alphabet,int length, int idx, string cipher){
    // 불가능
    if(alphabet.size() < idx){
        return;
    }


    // Goal state 여부 확인 
    if(cipher.size() == length){
        int count = 0;
        for(int i = 0 ; i < cipher.size() ; i++){
            if(cipher[i]=='a' || cipher[i] == 'e' || cipher[i] =='i' || cipher[i] == 'o' || cipher[i] == 'u'){
                count++;
            }
        }
        if( cipher.size() - count >= 2 && count >= 1){
            cout << cipher <<'\n';
        }

        return;
    }
    
    // 둘 다 아니라면 진행하기!
    if(cipher.size() < length ){
        decrypt(alphabet,length, idx+1, cipher+alphabet[idx]);
        decrypt(alphabet,length,idx+1,cipher);
    }

    return;
}

int main(){
    int l ,c;
    cin >> l >> c ;

    vector<char> alphabet(c);

    for(int i = 0 ; i < c ; i++){
        cin >> alphabet[i];
    }

    sort(alphabet.begin(),alphabet.end());

    decrypt(alphabet,l,0,"");

    return 0;

}

/*
#####################################
// 정답
//     재귀함수 사용하기
//         1. 불가능한 경우 : 더 재귀를 진행해봐도 답을 얻을 수 없는 경우
//         2. 조건을 만족하는 경우 : 답이 되는 조건 생각
//         3. 재귀호출
//             1) 선택을 한 경우
//             2) 선택을 하지 않은 경우 -> 어쨌든 선택은 한 것이므로 선택의 기회가 줄어들어야한다.
//                 -> 이 부분을 처리하지않는 다면 런타임 에러 발생 가능성 높아진다.
//                 -> 카운팅 되지 않는 경우의 수가 있기 때문
#####################################
*/




/*
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool check(string &password) {
    int ja = 0;
    int mo = 0;
    for (char x : password) {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
            mo += 1;
        } else {
            ja += 1;
        }
    }
    return ja >= 2 && mo >= 1;
}
void go(int n, vector<char> &alpha, string password, int i) {
    if (password.length() == n) {
        if (check(password)) {
            cout << password << '\n';
        }
        return;
    }
    if (i == alpha.size()) return;
    go(n, alpha, password+alpha[i], i+1);
    go(n, alpha, password, i+1);
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<char> a(m);
    for (int i=0; i<m; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    
    go(n, a, "", 0);

    return 0;
}
*/