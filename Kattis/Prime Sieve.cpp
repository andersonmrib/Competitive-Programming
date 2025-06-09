#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n, q; cin >> n >> q;

  vector<bool> p(n+1, true);
  p[0] = p[1] = false;
  int count = 0;

  for(int i=2; i<=sqrt(n); i++)
    if(p[i]){
    for(int j=i*i; j<=n; j+=i)
      p[j] = 0;
  }

  for(int i=2; i<=n; i++)
    if(p[i]) count++;

  cout << count << "\n";

  for(int i=0; i<q; i++){
    int x; cin >> x;
    cout << p[x] << "\n";
  }

  return 0;
}
