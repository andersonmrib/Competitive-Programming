#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define F(i, L, R) for(int i=L; i<R; i++)
#define FR(i, R, L) for(int i=R; i>0; i--)
#define endl "\n"

using namespace std;

int fastPow(int b, int p, int m){
  if(p == 0) return 1;
  int ans = fastPow(b, p/2, m);
  ans = ans * ans % m;
  if((p&1)) ans = ans * b % m;
  return ans;
}

int32_t main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n, k; cin >> n >> k;

    double x = k * (log10((double)n));
    double frac = x - floor(x);
    int first3 = (int)pow(10, frac + 2);
    int last3 = fastPow(n, k, 1000);

    cout << first3 << "...";
    cout << setw(3) << setfill('0') << last3 << endl;
  }

  return 0;
}
