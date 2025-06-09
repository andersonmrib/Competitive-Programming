#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

int main(){

  speedBoost;
  ll N; cin >> N;
  set<ll> friends;

  for(ll i=1; i<=sqrt(N); i++){
    if(N%i == 0){ // everyone can eat a candy
      if(i-1 >= 0) friends.insert(i-1); // excludes Benny itself
      friends.insert((N/i) - 1);
    }
  }

  for(auto x : friends) cout << x << " ";
  cout << "\n";

  return 0;
}
