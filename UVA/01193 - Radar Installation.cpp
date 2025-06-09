#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

struct st{
  double l, r;
  bool operator<(const st &other) const{
    return l < other.l;
  }
};

int main(){

  speedBoost;
  int n, d;
  int NC = 0;
  while((cin >> n >> d), (n || d)){

    bool hasSolution = true;

    vector<st> vec;
    for(int i=0; i<n; i++){
      double x, y; cin >> x >> y;

      if(y > d)
        hasSolution = false;

      double dx = sqrt(d*d - y*y);
      vec.push_back({x-dx, x+dx});
    }

    cout << "Case " << ++NC << ": ";
    if(!hasSolution) cout << "-1" << "\n";
    else{

      sort(vec.begin(), vec.end());

      int ans = 0;
      double max_r = -1e9;     // Last covered island position
      for(int i=0; i<n; i++){  // Island not covered
        if(vec[i].l > max_r){
          ans++; max_r = vec[i].r;
        }                      // Maintain the leftmost radar possible
        else                   // since it covers the current i and previous i-1 island
          max_r = min(max_r, vec[i].r);
      }

      cout << ans << "\n";
    }
  }

  return 0;
}
