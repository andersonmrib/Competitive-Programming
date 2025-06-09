#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

int main(){

  speedBoost;
  ll n, k;
  while(cin >> n >> k){

    // C(n, k) == C(n, n-k)
    if(k > n - k) k = n - k;
    double sum = 0;

    // Number and Log properties
    for(int i=0; i<k; i++)
      sum += log10(n - i) - log10(i + 1);

    int ans = floor(sum) + 1;
    cout << ans << "\n";
  }

  return 0;
}
