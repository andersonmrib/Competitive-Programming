#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n;
  int NC = 0;
  while(cin >> n){

    vector<int> vec(n);
    for(int i=0; i<n; i++)
      cin >> vec[i];

    cout << "Case " << ++NC << ":\n";

    int m; cin >> m;
    for(int i=0; i<m; i++){
      int q; cin >> q;

      cout << "Closest sum to " << q << " is ";

      int ans = vec[0] + vec[1];
      for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
          int sum = vec[i] + vec[j];
          if(abs(ans - q) > abs(sum - q))
            ans = sum;
        }
      }

      cout << ans << ".\n";
    }
  }

  return 0;
}
