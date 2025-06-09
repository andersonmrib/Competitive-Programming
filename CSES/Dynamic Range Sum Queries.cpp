#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

// Square root decomposition method.
// Segment tree is faster for this problem,
// but it will take some extra time due to the longer code

typedef long long ll;
vector<int> leaf;
vector<ll> terminal;

int sqrt_n;

void update_interval(int x){
  int idx = x / sqrt_n * sqrt_n;
  terminal[idx] = 0;
  for(int i=idx; i<idx+sqrt_n; i++)
    terminal[idx] += leaf[i];
}

void update(int k, int x){
  leaf[x] = k;
  update_interval(x);
}

ll query(int L, int R){
  ll ans = 0;
  for(int i=L; i<=R;){
    if((i%sqrt_n == 0) && (i+sqrt_n-1 <= R))
      ans += terminal[i], i+=sqrt_n;
    else
      ans += leaf[i], i++;
  }
  return ans;
}

int main(){

  speedBoost;

  int n, q; cin >> n >> q;
  sqrt_n = sqrt(n) + 1;

  leaf.assign(n, 0), terminal.assign(n, 0);
  for(int i=0; i<n; i++)
    cin >> leaf[i];

  for(int i=0; i<n; i+=sqrt_n)
    update_interval(i);

  int op, a, b, newVal, pos;
  for(int i=0; i<q; i++){

    cin >> op;

    if((op&1)){
      cin >> pos >> newVal; pos--;
      update(newVal, pos);
    }
    else{
      cin >> a >> b; a--, b--;
      cout << query(a, b) << "\n";
    }
  }

  return 0;
}
