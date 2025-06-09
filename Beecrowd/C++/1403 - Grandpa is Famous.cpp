#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  int n, m;
  while((cin >> n >> m) && (n|m)){

    map<int, int> mapper;

    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++){
        int player;
        cin >> player;
        mapper[player]++;
     }

    int firstMax = 0, secondMax = 0;
    for(auto x : mapper){             // simple algorithm for checking
        if(x.second > firstMax){      // the best and all of the "second
            secondMax = firstMax;     // best players
            firstMax = x.second;
        }
        else if(x.second > secondMax)
            secondMax = x.second;
    }

    set<int> secondBest; // getting the player's number again
    for(auto x : mapper){
        if(x.second == secondMax)
            secondBest.insert(x.first);
    }

    for(auto player : secondBest)
        cout << player << " ";
        cout << endl;
  }

  return 0;
}
