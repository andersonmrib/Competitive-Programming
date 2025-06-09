// Naïve solution - running poorly in ~2.5 seconds
/*
#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
  speedBoost;
  int n, k;
  while(cin >> n >> k){

    int ans = n;

    while(n > 0){
      n -= k;
      if(n >= 0) ans++;
      n++;
    }

    cout << ans << "\n";
  }

  return 0;
}
*/


// A smarter one!
#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
  speedBoost;
  int n, k;
  while(cin >> n >> k){

    int ans = n;

    while(n >= k ){
      int newCigarette = n/k;
      int remaining = n%k;
      ans += newCigarette;
      n = newCigarette + remaining;
    }

    cout << ans << "\n";
  }

  return 0;
}
