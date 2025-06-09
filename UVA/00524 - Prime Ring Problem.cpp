#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
unordered_set<int> p;
vi used, ring;
vector<vi> results;

void backtrack(int cur, int n){
  if(cur == n){
    if(p.count(ring[0] + ring[n-1]))
      results.push_back(ring);
    return;
  }

  for(int i=2; i<=n; i++){
    if(!used[i] && p.count(ring[cur-1] + i)){
      used[i] = true;
      ring[cur] = i;
      backtrack(cur+1, n);
      used[i] = false;
    }
  }
}

int main(){

  speedBoost;
  p.insert({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31});

  int n;
  int NC = 0;
  bool first = true;
  while(cin >> n){

    if(!first) cout << "\n";
    first = false;

    used.assign(n+1, false), ring.assign(n, 0), results.clear();
    ring[0] = 1;
    used[1] = true;

    backtrack(1, n);

    cout << "Case " << ++NC << ":\n";
    for(auto sol : results){
      for(int i=0; i<n; i++){
        if(i) cout << " ";
        cout << sol[i];
      }
      cout << "\n";
    }
  }

  return 0;
}
