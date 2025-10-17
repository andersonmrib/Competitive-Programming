#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

int getValue(string s){
  if(s[0] >= '2' && s[0] <= '9')
    return s[0] - '0';
  return 10;
}

int main(){

  speedBoost;
  int t; cin >> t;
  int NC = 1;
  while(t--){

    vector<string> deck(52);
    for(int i=0; i<52; i++)
      cin >> deck[i];

    vector<string> pile(deck.begin(), deck.begin() + 27);
    vector<string> hand(deck.begin() + 27, deck.end());
    // Take and keep it in your hand

    int Y = 0;
    for(int i=0; i<3; i++){
      int x = getValue(pile.back());
      Y += x;

      for(int j=0; j<(11 - x); j++)
        pile.pop_back();
    }

    pile.insert(pile.end(), hand.begin(), hand.end());

    cout << "Case " << NC++ << ": " << pile[Y-1] << endl;
  }

  return 0;
}
