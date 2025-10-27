#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

int main(){

  speedBoost;
  int N, R;
  int NC = 0;
  while(cin >> N >> R, N || R){

    vector<double> p(N);
    for(int i=0; i<N; i++)
      cin >> p[i];

    vector<double> res(N, 0.0);

    double denom = 0.0;
    int total_masks = 1<<N;
    for(int mask=0; mask<total_masks; mask++){

      if(__builtin_popcount(mask) != R) continue;

      double prob = 1.0;
      for(int i=0; i<N; i++){
        if(mask & (1<<i)) prob *= p[i];
        else              prob *= (1 - p[i]);
      }

      denom += prob;
      for(int i=0; i<N; i++){
        if(mask & (1<<i)) res[i] += prob;
      }
    }

    cout << "Case " << ++NC << ":\n";
    cout << fixed << setprecision(6);
    for(int i=0; i<N; i++){
      double condProb = (denom == 0.0) ? 0.0 : res[i] / denom;
      cout << condProb << endl;
    }
  }

  return 0;
}
