#include<iostream>

using namespace std;

int gcd(int m , int n){
    if(n==0){
        return m;
    }

    return gcd(n,m%n);
}

int m,n;

int main(){
    int T;
    int test_case;

    scanf("%d",&T);

    for(test_case = 1 ; test_case <= T ;test_case++){
        
        scanf("%d %d",&m,&n);

        int temp;
        if(m<n){
            temp = m;
            m = n;
            n = temp;
        }

        printf("%d\n",m*n/gcd(m,n));

    }

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
int gcd(int x, int y) {
    if (y == 0) return x;
    else return gcd(y, x%y);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int g = gcd(a,b);
        cout << a*b/g << '\n';
    }
    return 0;
}
*/