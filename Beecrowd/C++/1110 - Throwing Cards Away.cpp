#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  queue<int> deck;
  int n;
  while(scanf("%d", &n), n){

    while(!deck.empty()) deck.pop();

    for(int i=1; i<=n; i++) deck.push(i);

    cout << "Discarded cards: ";
    bool first = true;
    while(deck.size() > 1){

        if(!first) cout << ", ";
        cout << deck.front();
        deck.pop();
        deck.push(deck.front());
        deck.pop();
        first = false;
    }
    cout << "\nRemaining card: " << deck.front() << endl;



  }

  return 0;
}
