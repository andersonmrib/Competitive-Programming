#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

int main(){

  speedBoost;

  ll a, b, c;
  while((cin >> a >> b >> c), (a || b || c)){

    vector<ll> vec(3);
    vec[0] = a, vec[1] = b, vec[2] = c;
    sort(vec.begin(), vec.end());

    a = vec[0], b = vec[1], c = vec[2];

    if(a*a + b*b == c*c) cout << "right\n";
    else                 cout << "wrong\n";
  }

  return 0;
}
