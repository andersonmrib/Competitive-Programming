#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

  vector<ll> numbers;
  numbers.push_back(1);
  for(ll i=1; i <= INT_MAX; i*=2)
    for(ll j=i; j <= INT_MAX; j*=3)
      numbers.push_back(j);
  sort(numbers.begin(), numbers.end());

  int m;
  while((cin >> m), m){

    auto ans = lower_bound(numbers.begin(), numbers.end(), m);
    cout << *ans << "\n";
  }

  return 0;
}
