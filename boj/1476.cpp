#include<iostream>

using namespace std;

int main(){
    int E, S, M;

    cin >> E >> S >> M;

    E--;
    S--;
    M--;

    int year = -1;


    for(int i = 0 ; year == -1 ; i++){
        if( (i%15==E) && (i%28==S) && (i%19==M) ){
            year = i;
        }
    }

    cout << year+1 << '\n';

    return 0;

}



/*
####################
# 정답
####################
*/

/*
#include <iostream>
using namespace std;
int main() {
    int e,s,m;
    cin >> e >> s >> m;
    e -= 1;
    s -= 1;
    m -= 1;
    for (int i=0;; i++) {
        if (i % 15 == e && i % 28 == s && i % 19 == m) {
            cout << i+1 << '\n';
            break;
        }
    }
}
*/