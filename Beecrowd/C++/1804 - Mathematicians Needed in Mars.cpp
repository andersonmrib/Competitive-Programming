#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

#define LSOne(S) ((S) & -(S))
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
vll ft;

ll rsq(int j){
  ll sum = 0;
  for(; j; j -= LSOne(j))
    sum += ft[j];
  return sum;
}

ll rsq(int i, int j) { return rsq(j) - rsq(i-1); }

void update(int i, ll delta){
  for(; i<(int)ft.size(); i += LSOne(i))
    ft[i] += delta;
}

int main(){

  speedBoost;
  int n; cin >> n;

  vi buggies(n+1);
  ft.assign(n+1, 0);

  ft[0] = 0, buggies[0] = 0;           // index 0 as sentinel
  for(int i=1; i<=n; i++){             // start counting at 1
    cin >> buggies[i];
    update(i, buggies[i]);
  }

  char op1;
  int index;
  while(cin >> op1){
    cin >> index;
    if(op1 == 'a')
      update(index, -buggies[index]);  // eliminate the abducted buggy
    else
      cout << rsq(1, index-1) << "\n"; // checks everyone behind index i
  }

    return 0;
}
