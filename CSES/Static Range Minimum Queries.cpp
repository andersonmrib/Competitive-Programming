#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

// Square root decomposition method.
// Segment tree is faster for this problem,
// but it will take some extra time due to the longer code

const int INF = 1e9+1;
const int MAX_N = 200000;

int leaf[MAX_N] = {0};
int terminal[MAX_N] = {0};
int sqrt_n;

void update_internal(int x){
  int idx = x / sqrt_n * sqrt_n;
  terminal[idx] = leaf[idx];
  for(int i=idx; i<idx+sqrt_n; i++)
    terminal[idx] = min(terminal[idx], leaf[i]);
}

int min_query(int l, int r){
  int ans = INF;
  for(int i=l; i<=r;){
    if((i%sqrt_n == 0) && (i+sqrt_n-1 <= r))
      ans = min(ans, terminal[i]), i += sqrt_n;
    else
      ans = min(ans, leaf[i]), i++;
  }

  return ans;
}

int main(){

  speedBoost;

  int n, q; cin >> n >> q;
  sqrt_n = sqrt(n) + 1;

  for(int i=0; i<n; i++)
    cin >> leaf[i];

  for(int i=0; i<n; i+=sqrt_n)
    update_internal(i);

  for(int i=0; i<q; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    cout << min_query(a, b) << "\n";
  }

  return 0;
}
