#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int k; cin >> k;
  int numCases = 0;
  while(k--){

    int n; cin >> n;
    vector<unordered_map<int, int>> friends(n);
    unordered_map<int, int> stampCount;

    for(int i=0; i<n; i++){
      int m; cin >> m;
      for(int j=0; j<m; j++){
        int a; cin >> a;
        if(friends[i][a]++ == 0)
          stampCount[a]++;
      }
    }

    vector<int> uniqueStamps(n, 0);
    int numUniques = 0;

    for(int i=0; i<n; i++){
      for(auto [s, count] : friends[i]){
        if(stampCount[s] == 1){
          uniqueStamps[i]++;
          numUniques++;
        }
      }
    }

    printf("Case %d:", ++numCases);
    for(int i=0; i<n; i++){
      double percentage = (numUniques == 0) ? 0.0 : (100.0 * uniqueStamps[i]/numUniques);
      printf(" %6lf%%", percentage);
    }
    printf("\n");
  }

  return 0;
}
