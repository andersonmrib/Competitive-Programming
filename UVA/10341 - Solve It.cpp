#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

const double EPS = 1e-9;

int p, q, r, s, t, u;
double f(double x){
  return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

void apply_bisection(){
  double low = 0.0, high = 1.0;
  while(low + EPS< high){
    double mid = (low + high)/2.0;
    if(f(mid) > 0) low = mid;
    else high = mid;
  }
  cout << fixed << setprecision(4);
  cout << low << endl;
}

int main(){

  speedBoost;
  while(cin >> p >> q >> r >> s >> t >> u){

    double f0 = f(0), f1 = f(1);
    if(f0 * f1 > 0) cout << "No solution\n";
    else
      apply_bisection();
  }

  return 0;
}
