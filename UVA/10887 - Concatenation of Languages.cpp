#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  int numCases = 0;
  while(t--){

    int m, n; cin >> m >> n; cin.ignore();
    vector<string> vecM(m), vecN(n);

    for(int i=0; i<m; i++)
      getline(cin, vecM[i]);
    for(int i=0; i<n; i++)
      getline(cin, vecN[i]);

    unordered_set<string> uset;
    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
        uset.insert(vecM[i]+vecN[j]);
      }
    }
    cout << "Case " << ++numCases << ": ";
    cout << uset.size() << "\n";
  }

  return 0;
}
