#include<iostream>

using namespace std;
typedef struct _magnet{
    int info[8];
    int front;
}magnet;

magnet mag[2][4];

int main(){
    
    for(int i = 0 ; i < 4 ; i++){
        string temp;
        cin >> temp;
        for(int j = 0 ; j < 8 ; j++){
            mag[0][i].info[j] = temp[j]-'0';
            //scanf("%d",&mag[0][i].info[j]);
            mag[1][i].info[j] = mag[0][i].info[j];
        }
        mag[1][i].front = mag[0][i].front = 0;
    }
    cin.ignore(256,'\n');

    
    int K;
    scanf("%d",&K);
    
    int now = 0;

    for(int move = 0 ; move < K ; move++){
        int n, dir;
        scanf("%d %d",&n,&dir);

        if(n == 1){
            if(dir==1){
                mag[1-now][0].front = (mag[now][0].front-1) < 0 ? (mag[now][0].front-1)+8 : (mag[now][0].front-1);
                int f1 = (mag[now][0].front+2)%8;
                int b2 = (mag[now][1].front+6)%8;
                if(mag[now][0].info[f1]!=mag[now][1].info[b2]){
                    mag[1-now][1].front = (mag[now][1].front+1)%8;
                    int f2 = (mag[now][1].front+2)%8;
                    int b3 = (mag[now][2].front+6)%8;
                    if(mag[now][1].info[f2]!=mag[now][2].info[b3]){
                        mag[1-now][2].front = (mag[now][2].front-1) < 0 ? (mag[now][2].front-1)+8 :(mag[now][2].front-1);
                        int f3 = (mag[now][2].front+2)%8;
                        int b4 = (mag[now][3].front+6)%8;
                        if(mag[now][2].info[f3]!=mag[now][3].info[b4]){
                            mag[1-now][3].front = (mag[now][3].front+1)%8;
                        }
                        else{
                            mag[1-now][3].front = mag[now][3].front;
                        }
                    }
                    else{
                        mag[1-now][2].front = mag[now][2].front;
                        mag[1-now][3].front = mag[now][3].front;
                    }
                }
                else{
                    mag[1-now][1].front = mag[now][1].front;
                    mag[1-now][2].front = mag[now][2].front;
                    mag[1-now][3].front = mag[now][3].front;
                }
            }
            else if(dir==-1){
                mag[1-now][0].front = (mag[now][0].front+1)%8;
                int f1 = (mag[now][0].front+2)%8;
                int b2 = (mag[now][1].front+6)%8;
                if(mag[now][0].info[f1]!=mag[now][1].info[b2]){
                    mag[1-now][1].front = (mag[now][1].front-1) < 0 ? (mag[now][1].front-1)+8 : (mag[now][1].front-1);
                    int f2 = (mag[now][1].front+2)%8;
                    int b3 = (mag[now][2].front+6)%8;
                    if(mag[now][1].info[f2]!=mag[now][2].info[b3]){
                        mag[1-now][2].front = (mag[now][2].front+1)%8;
                        int f3 = (mag[now][2].front+2)%8;
                        int b4 = (mag[now][3].front+6)%8;
                        if(mag[now][2].info[f3]!=mag[now][3].info[b4]){
                            mag[1-now][3].front = (mag[now][3].front-1) < 0 ? (mag[now][3].front-1)+8 : (mag[now][3].front-1);
                        }
                        else{
                            mag[1-now][3].front = mag[now][3].front;
                        }
                    }
                    else{
                        mag[1-now][2].front = mag[now][2].front;
                        mag[1-now][3].front = mag[now][3].front;
                    }
                }
                else{
                    mag[1-now][1].front = mag[now][1].front;
                    mag[1-now][2].front = mag[now][2].front;
                    mag[1-now][3].front = mag[now][3].front;
                }

            }

        }
        else if(n==2){
            if(dir==1){
                mag[1-now][1].front = (mag[now][1].front-1) < 0 ? (mag[now][1].front-1)+8 : (mag[now][1].front-1);
                int f1 = (mag[now][0].front+2)%8;
                int b2 = (mag[now][1].front+6)%8;
                if(mag[now][0].info[f1]!=mag[now][1].info[b2]){
                    mag[1-now][0].front = (mag[now][0].front+1)%8;
                }
                else{
                    mag[1-now][0].front = mag[now][0].front;
                }

                int f2 = (mag[now][1].front+2)%8;
                int b3 = (mag[now][2].front+6)%8;
                if(mag[now][1].info[f2]!=mag[now][2].info[b3]){
                    mag[1-now][2].front = (mag[now][2].front+1)%8;
                    int f3 = (mag[now][2].front+2)%8;
                    int b4 = (mag[now][3].front+6)%8;
                    if(mag[now][2].info[f3]!=mag[now][3].info[b4]){
                        mag[1-now][3].front = (mag[now][3].front-1) < 0 ? (mag[now][3].front-1)+8 : (mag[now][3].front-1);
                    }
                    else{
                        mag[1-now][3].front = mag[now][3].front;
                    }
                }
                else{
                    mag[1-now][2].front = mag[now][2].front;
                    mag[1-now][3].front = mag[now][3].front;
                }
            }
            else if(dir==-1){
                mag[1-now][1].front = (mag[now][1].front+1)%8;
                int f1 = (mag[now][0].front+2)%8;
                int b2 = (mag[now][1].front+6)%8;
                if(mag[now][0].info[f1]!=mag[now][1].info[b2]){
                    mag[1-now][0].front = (mag[now][0].front-1) < 0 ? (mag[now][0].front-1)+8 : (mag[now][0].front-1);
                }
                else{
                    mag[1-now][0].front = mag[now][0].front;
                }
                int f2 = (mag[now][1].front+2)%8;
                int b3 = (mag[now][2].front+6)%8;

                if(mag[now][1].info[f2]!=mag[now][2].info[b3]){
                    mag[1-now][2].front = (mag[now][2].front-1) < 0 ? (mag[now][2].front-1)+8 :(mag[now][2].front-1);
                    int f3 = (mag[now][2].front+2)%8;
                    int b4 = (mag[now][3].front+6)%8;
                    if(mag[now][2].info[f3]!=mag[now][3].info[b4]){
                        mag[1-now][3].front = (mag[now][3].front+1)%8;
                    }
                    else{
                        mag[1-now][3].front = mag[now][3].front;
                    }
                }
                else{
                    mag[1-now][2].front = mag[now][2].front;
                    mag[1-now][3].front = mag[now][3].front;
                }

            }

        }
        else if(n==3){
            if(dir==1){
                mag[1-now][2].front = (mag[now][2].front-1) < 0 ? (mag[now][2].front-1)+8 :(mag[now][2].front-1);
                int f3 = (mag[now][2].front+2)%8;
                int b4 = (mag[now][3].front+6)%8;

                if(mag[now][2].info[f3]!=mag[now][3].info[b4]){
                    mag[1-now][3].front = (mag[now][3].front+1)%8;
                }
                else{
                    mag[1-now][3].front = mag[now][3].front;
                }
                int f2 = (mag[now][1].front+2)%8;
                int b3 = (mag[now][2].front+6)%8;

                if(mag[now][1].info[f2]!=mag[now][2].info[b3]){
                    mag[1-now][1].front = (mag[now][1].front+1)%8;
                    int f1 = (mag[now][0].front+2)%8;
                    int b2 = (mag[now][1].front+6)%8;
                    if(mag[now][0].info[f1]!=mag[now][1].info[b2]){
                        mag[1-now][0].front = (mag[now][0].front-1) < 0 ? (mag[now][0].front-1)+8 : (mag[now][0].front-1);
                    }
                    else{
                        mag[1-now][0].front = mag[now][0].front;
                    }
                }
                else{
                    mag[1-now][1].front = mag[now][1].front;
                    mag[1-now][0].front = mag[now][0].front;
                }
            }
            else if(dir==-1){
                mag[1-now][2].front = (mag[now][2].front+1)%8;
                int f3 = (mag[now][2].front+2)%8;
                int b4 = (mag[now][3].front+6)%8;
                if(mag[now][2].info[f3]!=mag[now][3].info[b4]){
                    mag[1-now][3].front = (mag[now][3].front-1) < 0 ? (mag[now][3].front-1)+8 : (mag[now][3].front-1);
                }
                else{
                    mag[1-now][3].front = mag[now][3].front;
                }

                int f2 = (mag[now][1].front+2)%8;
                int b3 = (mag[now][2].front+6)%8;

                if(mag[now][1].info[f2]!=mag[now][2].info[b3]){
                    mag[1-now][1].front = (mag[now][1].front-1) < 0 ? (mag[now][1].front-1)+8 : (mag[now][1].front-1);
                    int f1 = (mag[now][0].front+2)%8;
                    int b2 = (mag[now][1].front+6)%8;
                    if(mag[now][0].info[f1]!=mag[now][1].info[b2]){
                        mag[1-now][0].front = (mag[now][0].front+1)%8;
                    }
                    else{
                        mag[1-now][0].front = mag[now][0].front;
                    }
                }
                else{
                    mag[1-now][1].front = mag[now][1].front;
                    mag[1-now][0].front = mag[now][0].front;
                }

            }

        }
        else if(n==4){
            if(dir==1){
                mag[1-now][3].front = (mag[now][3].front-1) < 0 ? (mag[now][3].front-1)+8 : (mag[now][3].front-1);
                int f3 = (mag[now][2].front+2)%8;
                int b4 = (mag[now][3].front+6)%8;
                if(mag[now][2].info[f3]!=mag[now][3].info[b4]){
                    mag[1-now][2].front = (mag[now][2].front+1)%8;
                    int f2 = (mag[now][1].front+2)%8;
                    int b3 = (mag[now][2].front+6)%8;
                    if(mag[now][1].info[f2]!=mag[now][2].info[b3]){
                        mag[1-now][1].front = (mag[now][1].front-1) < 0 ? (mag[now][1].front-1)+8 : (mag[now][1].front-1);
                        int f1 = (mag[now][0].front+2)%8;
                        int b2 = (mag[now][1].front+6)%8;
                        if(mag[now][0].info[f1]!=mag[now][1].info[b2]){
                            mag[1-now][0].front = (mag[now][0].front+1)%8;
                        }
                        else{
                            mag[1-now][0].front = mag[now][0].front;
                        }
                    }
                    else{
                        mag[1-now][1].front = mag[now][1].front;
                        mag[1-now][0].front = mag[now][0].front;
                    }
                }
                else{
                    mag[1-now][2].front = mag[now][2].front;
                    mag[1-now][1].front = mag[now][1].front;
                    mag[1-now][0].front = mag[now][0].front;
                }
            }
            else if(dir==-1){
                mag[1-now][3].front = (mag[now][3].front+1)%8;
                int f3 = (mag[now][2].front+2)%8;
                int b4 = (mag[now][3].front+6)%8;
                if(mag[now][2].info[f3]!=mag[now][3].info[b4]){
                    mag[1-now][2].front = (mag[now][2].front-1) < 0 ? (mag[now][2].front-1)+8 :(mag[now][2].front-1);
                    int f2 = (mag[now][1].front+2)%8;
                    int b3 = (mag[now][2].front+6)%8;
                    if(mag[now][1].info[f2]!=mag[now][2].info[b3]){
                        mag[1-now][1].front = (mag[now][1].front+1)%8;
                        int f1 = (mag[now][0].front+2)%8;
                        int b2 = (mag[now][1].front+6)%8;
                        if(mag[now][0].info[f1]!=mag[now][1].info[b2]){
                            mag[1-now][0].front = (mag[now][0].front-1) < 0 ? (mag[now][0].front-1)+8 : (mag[now][0].front-1);
                        }
                        else{
                            mag[1-now][0].front = mag[now][0].front;
                        }
                    }
                    else{
                        mag[1-now][1].front = mag[now][1].front;
                        mag[1-now][0].front = mag[now][0].front;
                    }
                }
                else{
                    mag[1-now][2].front = mag[now][2].front;
                    mag[1-now][1].front = mag[now][1].front;
                    mag[1-now][0].front = mag[now][0].front;
                }

            }

        }

        now = 1-now;

    }

    int sum = mag[now][0].info[mag[now][0].front]*1 + mag[now][1].info[mag[now][1].front]*2 +mag[now][2].info[mag[now][2].front]*4 +mag[now][3].info[mag[now][3].front]*8;
    printf("%d\n",sum);
    

}