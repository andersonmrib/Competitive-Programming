#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

#define LSOne(S) ((S) & -(S))
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

class fenwickTree{
  private:
    vll ft;
  public:
    fenwickTree(int m) { ft.assign(m+1, 0); }

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
};

int main(){

  speedBoost;
  int n, q; cin >> n >> q;
  fenwickTree ft(n);

  while(q--){
    char op; cin >> op;

    if(op == '+'){
      ll v1, v2; cin >> v1 >> v2;
      ft.update(v1+1, v2);
    }
    else{
      int value; cin >> value;
      cout << ft.rsq(value) << "\n";
    }
  }

    return 0;
}
