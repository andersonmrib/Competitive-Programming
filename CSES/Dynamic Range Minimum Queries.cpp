#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

vector<int> leaf, terminal;
int sqrt_n;

const int INF = 1e9+1;

void update_internal(int x){
  int idx = x / sqrt_n * sqrt_n;
  terminal[idx] = leaf[idx];
  for(int i=idx; i<idx+sqrt_n; i++)
    terminal[idx] = min(terminal[idx], leaf[i]);
}

void update(int k, int x){
  leaf[x] = k;
  update_internal(x);
}

int min_query(int L, int R){
  int ans = INF;
  for(int i=L; i<=R;){
    if((i%sqrt_n == 0) && (i+sqrt_n-1 <= R))
      ans = min(ans, terminal[i]), i += sqrt_n;
    else
      ans = min(ans, leaf[i]), i++;
  }
  return ans;
}

int main(){

  speedBoost;

  int n, q; cin >> n >> q;
  leaf.assign(n, 0), terminal.assign(n, 0);
  sqrt_n = sqrt(n)+1;

  for(int i=0; i<n; i++)
    cin >> leaf[i];

  for(int i=0; i<n; i+=sqrt_n)
    update_internal(i);

  int op;
  for(int i=0; i<q; i++){

    cin >> op;

    if((op&1) == 1){
      int pos, newVal; cin >> pos >> newVal;
      pos--;
      update(newVal, pos);
    }
    else{
      int a, b; cin >> a >> b;
      a--, b--;
      cout << min_query(a, b) << "\n";
    }
  }

  return 0;
}
