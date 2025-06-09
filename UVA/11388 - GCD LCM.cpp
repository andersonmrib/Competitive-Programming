#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int T; cin >> T;
  while(T--){
    int G, L; cin >> G >> L;
    if(L%G) cout << -1 << endl;
    else    cout << G << " " << L << endl;
  }

  return 0;
}
