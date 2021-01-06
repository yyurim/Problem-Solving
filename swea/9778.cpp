#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int TC;
    cin >> TC;
    cin.ignore(256, '\n');

    for(int test_case = 0; test_case < TC ; test_case++){
        vector<int> deck;

        for(int d = 0 ; d < 13 ; d++){
            if(d >=9 ){
                deck.push_back(11);
                deck.push_back(11);
                deck.push_back(11);
                deck.push_back(11);
            }
            else if(d == 8){
                deck.push_back(10);
                deck.push_back(10);
                deck.push_back(10);
                deck.push_back(10);
            }
            else{
                deck.push_back(d+2);
                deck.push_back(d+2);
                deck.push_back(d+2);
                deck.push_back(d+2);
            }
        }
        
        int cards;
        cin >> cards;
        cin.ignore(256, '\n');
        int blackjack = 0;

        for(int c = 0 ; c < cards ; c++){
            string card;
            cin >> card;
            cin.ignore(256, '\n');
            if( card == "Ace"){
                blackjack += 11;
                deck.erase(find(deck.begin(), deck.end(), 11));
            }
            else if( (card == "Ten") || (card == "Jack") || (card == "Queen") || (card == "King")){
                blackjack += 10;
                deck.erase(find(deck.begin(), deck.end(), 10));
            }
            else{
                blackjack += stoi(card);
                deck.erase(find(deck.begin(), deck.end(), stoi(card)));
            }
        }

        int check = 21 - blackjack;
        if(check <= 1){
            cout << "#" << to_string(test_case) << " STOP\n";
        }
        else if(check >= 11){
            cout << "#" << to_string(test_case) << " GAZUA\n";
        }
        else{
            vector<int>::iterator checking = find(deck.begin(),deck.end(), check);
            
            if(deck.end()==checking){
                int flag = deck.size();
                for(int i = 0 ; i < deck.size() ; i++){
                    if(flag!=deck.size()){
                        break;
                    }
                    else{
                        if(deck[i]>check){
                            flag = i;
                        }
                    }
                }

                for(int i = flag ; i < deck.size() ; i++){
                    if(deck[i]!=check){
                        flag = i - 1;
                        break;
                    }
                }

                if((deck.size()- flag) > (flag - 0)){
                    cout << "#" << to_string(test_case) << " STOP\n";
                }
                else{
                    cout << "#" << to_string(test_case) << " GAZUA\n";
                }
                
            }
            else{
                for(; checking < deck.end() ; checking++){
                    if(*checking!=check){
                        //checking--;
                        break;
                    }
                }

                if((deck.end()- checking) > (checking - deck.begin())){
                    cout << "#" << to_string(test_case) << " STOP\n";
                }
                else{
                    cout << "#" << to_string(test_case) << " GAZUA\n";
                }
            };
        }
    }
}