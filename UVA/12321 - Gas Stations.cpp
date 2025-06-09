#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

struct st{
  int l, r;
  bool operator<(const st &other) const{
    return l < other.l;
  }
};

int main(){

  speedBoost;
  int l, g;
  while((cin >> l >> g), (l || g)){

    vector<st> vec;
    for(int i=0; i<g; i++){
      int x, r; cin >> x >> r;
      vec.push_back({x-r, x+r});
    }

    sort(vec.begin(), vec.end());
    int covered = 0, ans = 0, i=0;
    bool possible = true;

    while(covered < l){

      int max_r = -1;
      int j;

      for(j=i; j<vec.size() && vec[j].l<=covered; j++)
        if(vec[j].r > max_r)
          max_r = vec[j].r;

      if(max_r <= covered){
        possible = false;
        break;
      }

      covered = max_r;
      ans++;
      i=j;
    }

    if(!possible) cout << -1 << "\n";
    else          cout << g - ans << "\n";
  }

  return 0;
}

