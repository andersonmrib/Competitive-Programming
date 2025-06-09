#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){


  ll n, m, u; cin >> n >> m >> u;
  ll L, R, v, p;
  ll k;
  ll arr[n+1];

  for(int i=1; i<n+1; i++)
    cin >> arr[i];

  while(m--){

    k = 0;
    cin >> L >> R >> v >> p;

    for(int i=L; i<=R; i++)
      if(arr[i] < v) k++;

    arr[p] = u*k/(R - L + 1);
  }

  for(int i=1; i<n+1; i++)
    cout << arr[i] << endl;

  return 0;
}
