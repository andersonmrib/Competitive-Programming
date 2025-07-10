#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n; cin >> n; cin.ignore();
    int pos = 0;
    vector<int> previousMoves;
    // -1 for left, 1 for right, 0 for repeating
    for(int i=0; i<n; i++){
      string movement; getline(cin, movement);
      if(movement == "LEFT") pos--, previousMoves.push_back(-1);
      else if(movement == "RIGHT") pos++, previousMoves.push_back(1);
      else{
        int idx = stoi(movement.substr(movement.find_last_of(' ') + 1));
        pos += previousMoves[idx-1];
        previousMoves.push_back(previousMoves[idx-1]);
      }
    }

    cout << pos << "\n";
  }

  return 0;
}
