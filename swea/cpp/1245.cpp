#include<iostream>
#include<vector>
#include<sstream>

using namespace std;


#define COORX 0
#define WEIGHT 1 
#define F 2 


float mag[10][3];
float b_points[10];

int main(){
    int test_case;
    int T;

    scanf("%d",&T);

    for(test_case = 1 ; test_case <= T ; test_case++){

        for(int i = 0 ; i < 10 ; i++){
            mag[i][COORX] = 0;
            mag[i][WEIGHT] = 0;
            mag[i][F] = 0;
            b_points[i] = 0.0;
        }


        int mag_num;
        scanf("%d",&mag_num);

        for(int i = 0 ; i < mag_num ; i++){
            scanf("%f",&mag[i][COORX]);
        }

        for(int i = 0 ; i < mag_num ; i++){
            scanf("%f",&mag[i][WEIGHT]);
        }


        // string input;
        // string temp;
        // getline(cin, input);

        // stringstream ss(input);

        // int count = 0;
        // cout << input << endl;
        // while(getline(ss,temp,' ')){
        //     if(count < mag_num){
        //         mag[count][COORX] = stoi(temp);
        //     }
        //     else{
        //         mag[count-mag_num][WEIGHT] = stoi(temp);
        //     }

        //     count++;

        // }



        float sum_f = 0.0;

        for(int i = 0 ; i < mag_num ; i++){
    
            for(int j = 0 ; j < mag_num ; j++){
                if(i==j)    continue;
                mag[i][F] += mag[i][WEIGHT]*mag[j][WEIGHT]/((mag[i][COORX]-mag[j][COORX])*((mag[i][COORX]-mag[j][COORX])));
            }
            sum_f += mag[i][F];
        }

        sum_f = sum_f/mag_num;



        printf("#%d ",test_case);
        for(int i = 0 ; i < mag_num - 1 ; i++){
            
            printf("%.10f ",b_points[i]);
        }
        printf("\n");
        
    }
}