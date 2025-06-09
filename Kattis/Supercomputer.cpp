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
    vector<bool> bits;              // will help us checking the current bit
  public:
    fenwickTree(int m) : bits(m+1, 0), ft(m+1, 0) {}

    ll rsq(int j){
      ll sum = 0;
      for(; j; j -= LSOne(j))
        sum += ft[j];
      return sum;
    }

    ll rsq(int i, int j) { return rsq(j) - rsq(i-1); }

    void update(int i){
      bool currentState = bits[i];
      bits[i] = !currentState;      // flips the bit

      int delta = bits[i] ? 1 : -1; // updates all the tree
      for(; i<(int)ft.size(); i += LSOne(i))
        ft[i] += delta;
    }
};

int main(){

  speedBoost;
  int n, k; cin >> n >> k;

  fenwickTree ft(n);

  while(k--){
    char op; cin >> op;

    if(op == 'F'){
      int index; cin >> index;
      ft.update(index);
    }
    else{
      int v1, v2; cin >> v1 >> v2;
      cout << ft.rsq(v1, v2) << "\n";
    }
  }

    return 0;
}
