#include<iostream>

using namespace std;

int main(){
    int a, b, c;

    scanf("%d %d %d",&a, &b, &c);

    printf("%d\n%d\n%d\n%d\n",(a+b)%c,((a%c)+(b%c))%c,(a*b)%c,((a%c)*(b%c))%c);

    return 0;
    
}

/*
####################################
#   같은데 왜 굳이 다른 식을 써?
####################################
*/


/*
#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << (a+b)%c << '\n';
    cout << (a+b)%c << '\n';
    cout << (a*b)%c << '\n';
    cout << (a*b)%c << '\n';

    return 0;
}
*/