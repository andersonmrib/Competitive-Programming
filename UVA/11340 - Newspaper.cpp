#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n; cin >> n;

  while(n--){

    int k; cin >> k;
    unordered_map<char, int> prices;

    for(int i=0; i<k; i++){
      char character; int cent;
      cin >> character >> cent;
      prices[character] = cent;
    }

    int M; cin >> M; cin.ignore();
    string line;

    int totalCents = 0;
    for(int i=0; i<M; i++){
      getline(cin, line);
      for(auto c : line)
        totalCents += prices[c];
    }

    printf("%d.%02d$\n", totalCents/100, totalCents%100);
  }

  return 0;
}
