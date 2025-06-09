#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
using namespace std;

int32_t main(){

  speedBoost;
  int t; cin >> t;
  int NC = 0;
  while(t--){

    int n; cin >> n;
    vector<int> vec(n, 0);

    int denominator = 1;
    for(int i=0; i<n; i++){
      cin >> vec[i];
      denominator *= vec[i];
    }

    int numerator = 0;
    for(int i=0; i<n; i++)
      numerator += denominator / vec[i];

    int temp = numerator;
    numerator = denominator * n;
    denominator = temp;

    int gcd = __gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;

    cout << "Case " << ++NC << ": " << numerator << "/" << denominator << "\n";
  }

  return 0;
}
