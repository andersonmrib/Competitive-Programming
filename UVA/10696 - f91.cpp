// DP (Bottom Up) approach
#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int F91[1000000];

int main(){

  speedBoost;
  for(int i=1000000; i>=0; i--)
    if(i >= 101) F91[i] = i - 10;
    else         F91[F91[i + 11]];

  int n;
  while((cin >> n), n)
    cout << "f91(" << n << ") = " << F91[n] << "\n";

  return 0;
}

// Recursive approach
/*#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int f91(int n){
  return (n >= 101) ? n - 10 : f91(f91(n + 11));
}

int main(){

  speedBoost;
  int n;
  while((cin >> n), n){
    int ans = f91(n);
    cout << "f91(" << n << ") = " << ans << "\n";
  }

  return 0;
}
*/
