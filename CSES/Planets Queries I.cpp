#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define F(i, L, R) for(int i=L; i<R; i++)
#define FR(i, R, L) for(int i=R; i>0; i--)
#define endl "\n"

using namespace std;

typedef vector<int> vi;

int main(){

  speedBoost;
  int n, q;
  cin >> n >> q;

  int l = 31;
  vector<vi> up(l+1, vi(n+1));

  for(int i=1; i<=n; i++)
    cin >> up[0][i];

  for(int j=1; j<=l; j++)
    for(int i=1; i<=n; i++)
      up[j][i] = up[j-1][up[j-1][i]];

  while(q--){

    int x, k; cin >> x >> k;
    for(int j=0; j<=l; j++){
      if((k >> j) & 1)
        x = up[j][x];
      if((1 << j) > k && k != 0) break;
    }

    cout << x << endl;
  }

  return 0;
}

