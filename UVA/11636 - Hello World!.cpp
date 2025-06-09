#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int N;
  int numCases = 0;
  while(cin >> N){

    if(N < 0) break;
    cout << "Case " << ++numCases << ": ";

    int have = 1;
    int ans = 0;

    while(have < N){
      if(N - have < have){
        ans++;
        break;
      }
      have *= 2;
      ans++;
    }
    cout << ans << "\n";
  }

  return 0;
}
