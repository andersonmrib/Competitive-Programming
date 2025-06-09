#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> ii;

int main(){

  speedBoost;
  int P, S;
  int numCases = 0;
  while((cin >> P >> S), (P || S)){

    vector<ii> vec, ans;
    for(int i=0; i<S; i++){
      int l, r; cin >> l >> r;
      vec.push_back({l, r});
    }

    sort(vec.begin(), vec.end());

    // Simple interval problem!
    // Just check if the left corner is
    // inside another interval and, if not, push it to the
    // answer vector
    int furthestRight = vec[0].second, currentLeft = vec[0].first;
    for(int i=1; i<vec.size(); i++){
      if(vec[i].first <= furthestRight) furthestRight = max(furthestRight, vec[i].second);
      else{
        ans.push_back({currentLeft, furthestRight});
        currentLeft = vec[i].first;
        furthestRight = vec[i].second;
      }
    }

    ans.push_back({currentLeft, furthestRight});

    cout << "Teste " << ++numCases << endl;
    for(auto x : ans)
      cout << x.first << " " << x.second << endl;
    cout << endl;

  }
  return 0;
}
