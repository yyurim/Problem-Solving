#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>

/*
초기화 병ㅇ신아진짜 왜살아??
*/

using namespace std;

int N, K;
int s;
string input;
vector<long long> cipher;

int main(){
    int test_case;
    scanf("%d",&test_case);
    for(int tc = 1; tc <= test_case ; tc++){
        cipher.clear();
        scanf("%d %d", &N, &K);
        cin.ignore(256, '\n');
        getline(cin, input);
        s = 0;
        int count = N/4;
        for(int r = 0 ; r < N ; r++){
            s = (-r < 0) ? -r+N : r;
            for(int i = 0 ; i < 4 ;i++){
                string c_temp;
                for(int j = 0 ; j < count ; j++){
                    c_temp.push_back(input[(s+i*count+j)%N]);
                }
                long long stohex;
                istringstream(c_temp) >>  hex >> stohex;
                cipher.push_back(stohex);
            }
        }
        
		sort(cipher.rbegin(), cipher.rend());
        cipher.erase(unique(cipher.begin(), cipher.end()),cipher.end());

        long long max = cipher[K-1];

        printf("#%d %lld\n",tc, max);
  
    }
}