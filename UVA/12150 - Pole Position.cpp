#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;

int main(){

  speedBoost;
  int N;
  while((cin >> N), N){

    vi raceCars, pos;

    for(int i=0; i<N; i++){
      int c, p; cin >> c >> p;
      raceCars.push_back(c);
      pos.push_back(p);
    }

    vi ans(N, -1);
    bool hasSolution = true;

    for(int i=0; i<N; i++){

      int originalPos = pos[i] + i;
      // Produces the position of the car based on his movement
      // then checks if it's a valid one
      if(originalPos < 0 || originalPos >= N || ans[originalPos] != -1){
        hasSolution = false;
        break;
      }
      // Now, simply store it in the answer vector
      ans[originalPos] = raceCars[i];
    }

    if(!hasSolution) cout << -1 << "\n";
    else{
      cout << ans[0];
      for(int i=1; i<N; i++)
        cout << " " << ans[i];
      cout << "\n";
    }
  }

  return 0;
}
