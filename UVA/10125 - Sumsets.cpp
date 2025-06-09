#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define fixed(n) fixed << setprecision(n)
#define ceil(n, m) (((n) + (m) - 1) / (m))
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define pb push_back
#define debug(x) cout << #x << ": " << (x) << "\n";
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef tuple<int, int, int> edge;

const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 62;
const double EPS = 1e-9;

int main(){

  speedBoost;
  int n;
  while((cin >> n), n){
    vll S(n);
    unordered_set<ll> values;

    for(int i=0; i<n; i++){
      cin >> S[i];
      values.insert(S[i]);
    }

    sort(rall(S));
    bool found = false;
    for(int i=0; i<n && !found; i++){
      ll d = S[i];
      for(int j=0; j<n && !found; j++){
        if(i == j) continue;
        for(int k=0; k<n && !found; k++){
          if(k == i || k == j) continue;
          ll a = d - S[j] - S[k];
          if(a == S[i] || a == S[j] || a == S[k]) continue;
          if(values.count(a)){
            found = true;
            cout << d << "\n";
          }
        }
      }
    }
    if(!found) cout << "no solution\n";
  }

  return 0;
}


