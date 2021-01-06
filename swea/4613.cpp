#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int test_case = 1; test_case <= t ; test_case++){
        vector<int> colors;
        char flag[50][50];
        int N ,M;
        vector<int> parted;
        scanf("%d %d",&N, &M);

        for(int r = 0 ; r < N ;r++){
            string line;
            cin >> line;
            for(int c = 0 ; c < M ;c++){
                flag[r][c] = line[c];
            }
        }

        for(int w = 1; w <=N-2 ; w++){
            for(int b = 1 ; b <= N-1-w ; b++){
                int count = 0;
            
                for(int i = 0 ; i < w ; i++){
                    for(int c = 0 ; c < M ;c++){
                        if(flag[i][c] != 'W')   count++;
                    }
                }

                for(int i = w ; i < w+b ; i++){
                    for(int c = 0 ; c < M ;c++){
                        if(flag[i][c] != 'B')   count++;
                    }
                }

                for(int i = w+b ; i < N ; i++){
                    for(int c = 0 ; c < M ;c++){
                        if(flag[i][c] != 'R')   count++;
                    }
                }

                colors.push_back(count);

            }
        }

        printf("#%d %d\n",test_case, *min_element(colors.begin(),colors.end()));
     
    }
}