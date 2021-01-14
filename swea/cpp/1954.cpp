#include <iostream>
#include <vector>

using namespace std;

int main(){
    int TC;
    cin >> TC;

    for(int test_case = 0 ; test_case < TC ; test_case++){
        int n;
        cin >> n;
        int arr[n][n];

        int move = n-1;
        int width = 0;
        int height = 0;
        int value = 1;
        while(1){

            
            if((move <= 1)){
                if(n%2){
                    arr[height][width]  = value;
                }
                else if(n%2==0){
                    arr[height][width] = value++;
                    width++;
                    arr[height][width] = value++;
                    height++;
                    arr[height][width] = value++;
                    width--;
                    arr[height][width] = value++;
                }
                    
                break;
            }

            for(int w = 0 ; w < move ; w++){
                arr[height][width] = value++;
                width++;
            }
            
            for(int h = 0 ; h < move ; h++){
                arr[height][width]  = value++;
                height++;
            }

            for(int w = 0 ; w < move ; w++){
                arr[height][width] = value++;
                width--;
            }

            for(int h = 0 ; h < move ; h++){
                arr[height][width]  = value++;
                height--;
            }
            
            height++;
            width++;
            move -=2;

        }

        cout << "#" << to_string(test_case) <<'\n';
        for(int i = 0 ; i < n ; i++){
            for(int j =0 ; j < n ; j++){
                cout << arr[i][j] << " ";
            }
            cout << '\n';
        }
    }
}