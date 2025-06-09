#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
vll dist;

int main(){

  speedBoost;
  set<ll> tree;
  int n; cin >> n;

  dist.assign(300001, 0);
  ll ans = 0;
  for(int i=0; i<n; i++){

    int x; cin >> x;
    ll cost = 0;

    tree.insert(x);
    if(i == 0){
      cout << 0 << "\n";
      continue;
    }

    auto cur = tree.find(x);
    if(cur != tree.begin()){                   // checks if we can have a previous element
      auto previous = cur;
      previous--;                              // gets the previous
      cost = max(dist[*(previous)] + 1, cost); // add plus 1 for thee layers
    }
    if(cur != tree.end()){                     // checks if we can have a 'next' element
      auto next = cur;
      next++;
      if(next != tree.end())                   // another check
        cost = max(dist[*(next)] + 1, cost);
    }

    ans += cost;
    dist[x] = cost;
    cout << ans << "\n";
  }

  return 0;
}
