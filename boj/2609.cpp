#include<iostream>

using namespace std;

int gcd(int m , int n);
int lcm(int m , int n);

int main(){
    int m, n;

    scanf("%d %d",&m, &n);

    int temp;
    if(m<n){
        temp=m;
        m=n;
        n=temp;
    }

    printf("%d\n%d\n",gcd(m,n),lcm(m,n));

    return 0;

}

int gcd(int m , int n){
    if(n==0){
        return m;
    }

    return gcd(n,m%n);
}

int lcm(int m, int n){
    return m*n/gcd(m,n);
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
    int a, b;
    cin >> a >> b;
    int g = gcd(a,b);
    cout << g << '\n' << a*b/g << '\n';
    return 0;
}
*/