#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<cmath>

using namespace std;

typedef struct _person{
    int r, c;
    bool on[2];
    int to_stair[2];
    int t_down;
    int state;
}person;

int map[10][10];
int stairs[2][2];
int N;

int main(){
    int test_case;
    scanf("%d",&test_case);

    for(int tc = 1; tc <= test_case ; tc++){
        person people[2][11];
        int p_index = 1;
        int p_count;

        scanf("%d",&N);

        for(int r = 0 ; r < 10 ; r++){
            for(int c = 0 ; c < 10 ;c++){
                map[r][c] = 0;
            }
        }

        int is_first = 0;
        for(int r = 0 ; r < N ; r++){
            for(int c = 0 ; c < N ;c++){
                scanf("%d",&map[r][c]);
                if(map[r][c]==1){
                    people[0][p_index].r = people[1][p_index].r = r;
                    people[0][p_index].c = people[1][p_index].c = c;
                    people[0][p_index].to_stair[0] = people[1][p_index].to_stair[0] = -1;
                    people[0][p_index].to_stair[1] = people[1][p_index].to_stair[1] = -1;
                    people[0][p_index].t_down = people[1][p_index].t_down = -1;
                    people[0][p_index].state = people[1][p_index].state = -1;

                    people[0][p_index].on[0] = people[0][p_index].on[1] = false;
                    people[1][p_index].on[0] = people[1][p_index].on[1] = false;
                    p_index++;
                }
                else if(map[r][c]>1){
                    stairs[is_first][0] = r;
                    stairs[is_first][1] = c;
                    is_first++;
                }
            
            }
        }


        p_count = p_index - 1;

        for(int p = 1 ; p <= p_count ; p++){
            people[0][p].to_stair[0] = abs(people[0][p].r-stairs[0][0]) + abs(people[0][p].c-stairs[0][1]);
            people[0][p].to_stair[1] = abs(people[0][p].r-stairs[1][0]) + abs(people[0][p].c-stairs[1][1]);
            people[1][p].to_stair[0] = abs(people[1][p].r-stairs[0][0]) + abs(people[1][p].c-stairs[0][1]);
            people[1][p].to_stair[1] = abs(people[1][p].r-stairs[1][0]) + abs(people[1][p].c-stairs[1][1]);
        }
        
        int min_ans = 987654321;
        
        for(int c = 0 ; c < pow(2,p_count) ; c++){
            //초기화
            for(int p = 1 ; p <= p_count ; p++){

                people[0][p].t_down = people[1][p].t_down = -1;
                people[0][p].state = people[1][p].state = -1;
                people[0][p].on[0] = people[0][p].on[1] = false;
                people[1][p].on[0] = people[1][p].on[1] = false;

            }

            // 경우의 수 생성하기
            string cases;
            int cases_to_bin = 1 << (p_count-1);
            int c_temp = c;

            // 사람 번호와 시간 for 정렬 by 시간
            vector<int> stair0, stair1;
            for(int p = 0 ; p < p_count ; p++){
                char temp = (c_temp&cases_to_bin) ? '1' : '0';
                cases.push_back(temp);
                c_temp = c_temp << 1;

                people[0][p+1].on[temp-'0'] = true;
                people[1][p+1].on[temp-'0'] = true;

                // 사람의 목적지 설정
                if(temp-'0' == 0){
                    stair0.push_back(p+1);
                }
                else{
                    stair1.push_back(p+1);
                }
            }
            
            int now = 0;
            int time_stair = 0;
            int exited_stair[2];
            exited_stair[0] = exited_stair[1] = p_count;
            int on[2][2];
            on[0][0] = on[0][1] = on[1][1] = on[1][1] = 0;


            while(exited_stair[now] > 0){

                int change_in = 0;
                int change_out = 0;


                for(int p = 0 ; p < stair0.size() ; p++){
                    
                    int p_index = stair0[p];
                    if(people[now][p_index].state == -1){
                        if((people[now][p_index].to_stair[0] == time_stair)){
                            people[1-now][p_index].state = 0;
                        }
                        else{
                            people[1-now][p_index].state = -1;
                        }
                    }
                    else if(people[now][p_index].state == 0){
                            if((on[now][0] + change_in )< 3){
                                change_in++;
                                people[1-now][p_index].state = 1;
                                people[1-now][p_index].t_down = map[stairs[0][0]][stairs[0][1]]-1;
                            }
                            else{
                                people[1-now][p_index].state = 0;
                                people[1-now][p_index].t_down = people[now][p_index].t_down;
                            }

                    }
                    else if(people[now][p_index].state == 1){
                        if(people[now][p_index].t_down > 0){
                            people[1-now][p_index].t_down = --people[now][p_index].t_down;
                            if(people[1-now][p_index].t_down <=0){
                                change_out++;
                                people[1-now][p_index].state = 2;
                                exited_stair[1-now] = --exited_stair[now];
                            }
                            else{
                                people[1-now][p_index].state = 1;
                                exited_stair[1-now] = exited_stair[now];
                            }
                        }
                    }
                    else{
                        people[1-now][p_index].state = 2;
                    }

                }

                on[1-now][0] = on[now][0] + change_in - change_out;
                change_in = change_out = 0;

                for(int p = 0 ; p < stair1.size() ; p++){
                    
                    int p_index = stair1[p];
                    if(people[now][p_index].state == -1){
                        if((people[now][p_index].to_stair[1] == time_stair)){
                            people[1-now][p_index].state = 0;
                        }
                        else{
                            people[1-now][p_index].state = -1;
                        }
                    }
                    else if(people[now][p_index].state == 0){
                            if(on[now][1] + change_in < 3){
                                change_in++;
                                people[1-now][p_index].state = 1;
                                people[1-now][p_index].t_down = map[stairs[1][0]][stairs[1][1]]-1;
                            }
                            else{
                                people[1-now][p_index].state = 0;
                                people[1-now][p_index].t_down = people[now][p_index].t_down;
                            }

                    }
                    else if(people[now][p_index].state == 1){
                        if(people[now][p_index].t_down > 0){
                            people[1-now][p_index].t_down = --people[now][p_index].t_down;
                            if(people[1-now][p_index].t_down <=0){
                                people[1-now][p_index].state = 2;
                                change_out++;
                                exited_stair[1-now] = --exited_stair[now];
                            }
                            else{
                                people[1-now][p_index].state = 1;
                                exited_stair[1-now] = exited_stair[now];
                            }
                        }

                    }
                    else{
                        people[1-now][p_index].state = 2;
                    }

                }

                on[1-now][1] = on[now][1] + change_in - change_out;

                now = 1 - now;
                time_stair++;

            }
            

            if(min_ans > time_stair){
                min_ans = time_stair;
            }

        }

        printf("#%d %d\n",tc,min_ans);

    }

}