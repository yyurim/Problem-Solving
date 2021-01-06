#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    for(int test_case = 1 ; test_case <= 10 ; test_case++){
        int t;
        cin >> t;
        cin.ignore(256,'\n');

        

        int arr[100][100];

        vector<int> sum_total;

        int sum_right_dig = 0;
        int sum_left_dig = 0;

        for(int row = 0 ; row < 100 ; row++){
            string input;
            getline(cin, input);
            stringstream ss(input);
            string temp;

            int col = 0;
            while(getline(ss, temp, ' ')){
                arr[row][col++] = stoi(temp);
            }
        }

        for(int r = 0 ; r < 100 ; r++){
            int sum = 0;
            for(int c = 0 ; c < 100 ; c++){
                sum +=arr[r][c];
            }
            sum_total.push_back(sum);
        }

        for(int c = 0 ; c < 100 ; c++){
            int sum = 0;
            for(int r = 0 ; r < 100 ; r++){
                sum +=arr[r][c];
            }
            sum_total.push_back(sum);
        }

        for(int step = 0 ; step < 100 ; step++){
            sum_right_dig += arr[step][step];
        }

        for(int step = 0 ; step < 100 ; step++){
            sum_left_dig += arr[step][99-step];
        }

        sum_total.push_back(sum_right_dig);
        sum_total.push_back(sum_left_dig);

        cout << "#"<<test_case << " "<<*max_element(sum_total.begin(), sum_total.end())<<"\n";


    }
}