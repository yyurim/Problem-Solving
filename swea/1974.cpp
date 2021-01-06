#include<iostream>
using namespace std;

int sudoku[9][9];
bool check[10];

int main(){
    int test_case;
    cin >> test_case;
    for(int tc = 1 ; tc <= test_case ; tc++){
        for(int r = 0 ; r < 9 ; r++){
            for(int c = 0 ; c < 9 ; c++){
                scanf("%d",&sudoku[r][c]);
            }
        }

        for(int i = 0  ; i < 10 ; i++){
            check[i] = 0;
        }

        int ans = 1;

        for(int r = 0  ; r < 9 ; r++){
            for(int c = 0 ; c < 9 ; c++){
                check[sudoku[r][c]] = 1;
            }

            for(int i = 1 ; i <=9 ; i++){
                if(check[i]) continue;
                else{
                    ans = 0;
                }
            }
            for(int i = 0  ; i < 10 ; i++){
                check[i] = 0;
            }
        }

        for(int r = 0  ; r < 9 ; r++){
            for(int c = 0 ; c < 9 ; c++){
                check[sudoku[c][r]] = 1;
            }

            for(int i = 1 ; i <=9 ; i++){
                if(check[i]) continue;
                else{
                    ans = 0;
                }
            }
            for(int i = 0  ; i < 10 ; i++){
                check[i] = 0;
            }
        }

        for(int b = 0 ; b < 9 ;b++){
            for(int r = 3*(int)(b/3) ; r < 3+3*(int)(b/3); r++){
                for(int c= 3*(b%3) ; c < 3+3*(b%3) ; c++){
                    check[sudoku[c][r]] = 1;
                }
            }

            for(int i = 1 ; i <=9 ; i++){
                if(check[i]) continue;
                else{
                    ans = 0;
                }
            }
            for(int i = 0  ; i < 10 ; i++){
                check[i] = 0;
            }
        }

        printf("#%d %d\n",tc,ans);

    }
}