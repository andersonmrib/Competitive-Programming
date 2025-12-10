#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
using namespace std;

int main(){

  speedBoost;
  int n, q;
  int NC = 1;
  while(cin >> n >> q, n, q){


    vector<int> marbles(n);
    for(int i=0; i<n; i++)
      cin >> marbles[i];

    sort(marbles.begin(), marbles.end());

    cout << "CASE# " << NC++ << ":\n";
    while(q--){

      int x; cin >> x;
      int pos = lower_bound(marbles.begin(), marbles.end(), x) - marbles.begin();

      if(pos == n || marbles[pos] != x) cout << x << " not found\n";
      else         cout << x << " found at " << pos+1 << "\n";
    }
  }

  return 0;
}
