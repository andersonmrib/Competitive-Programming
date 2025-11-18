#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
using namespace std;

int main(){

  speedBoost;
  int n; cin >> n;

  vector<int> A(n), L(n, 0);
  for(int i=0; i<n; i++)
    cin >> A[i];

  int k = 0;
  for(int i=0; i<n; i++){

    int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
    L[pos] = A[i];
    if(pos == k)
      k = pos + 1;
  }

  cout << k << endl;

  return 0;
}
