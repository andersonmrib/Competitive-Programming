#include <bits/stdc++.h>
using namespace std;
#define LSOne(S) ((S) & -(S))

typedef long long ll;
vector<ll> vll;

ll rsq(int j){
  ll sum = 0;
  for(; j; j -= LSOne(j))
    sum += vll[j];
  return sum;
}

void update(int i, ll v){
  for(; i<vll.size(); i += LSOne(i))
    vll[i] += v;
}

int main(){

  int n; cin >> n;
  vll.assign(n+1, 0);

  vll.push_back(0);  // index 0 always starts with 0
  int ans = 0;
  for(int i=1; i<=n; i++){
    int x; cin >> x;
    vll.push_back(x);

    ans += (i - 1) - rsq(x - 1);
    update(x, 1);
  }

  cout << ans << endl;

  return 0;
}
