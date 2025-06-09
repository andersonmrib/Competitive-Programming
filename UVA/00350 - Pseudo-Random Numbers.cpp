#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef pair<int, int> ii;

int Z, I, M, L;

int f(int x) { return (Z*x + I)%M; }


ii floydCycleFinding(int x0){
  int t = f(x0), h = f(f(x0));
  while(t != h) { t = f(t), h = f(f(h)); }

  int mu = 0; h = x0;
  while(t != h) { t = f(t), h = f(f(h)), mu++; }

  int lambda = 1; h = f(t);
  while(t != h) { h = f(h); lambda++; }

  return {mu, lambda};
}

int main(){

  speedBoost;
  int NC = 0;
  while((cin >> Z >> I >> M >> L), (Z || I || M || L)){

    auto [mu, lambda] = floydCycleFinding(L);
    cout << "Case " << ++NC << ": " << lambda << "\n";
  }

  return 0;
}
