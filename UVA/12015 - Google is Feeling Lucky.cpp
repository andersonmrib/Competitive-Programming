#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef pair<string, int> p;

int main(){

  speedBoost;
  int t; cin >> t; cin.ignore();

  int numCases = 0;
  while(t--){

    vector<p> vec(10);
    string url; int v;

    int best = 0;
    for(int i=0; i<10; i++){
      cin >> url >> v; cin.ignore();
      vec[i].first = url;
      vec[i].second = v;
      best = max(best, v);
    }

    cout << "Case #" << ++numCases << ":\n";
    for(int i=0; i<10; i++){
      if(vec[i].second == best)
        cout << vec[i].first << "\n";
    }
  }

  return 0;
}
