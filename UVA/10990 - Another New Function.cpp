#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

#define MAX_N 2000000

int main(){

  speedBoost;
  vector<int> EulerPhi(MAX_N+1, 0);
  vector<int> depthPhi(MAX_N+1, 0);
  vector<int> sumDepthPhi(MAX_N+1, 0);

  for(int i=1; i<=MAX_N; i++) EulerPhi[i] = i;
  for(int i=2; i<=MAX_N; i++)
    if(EulerPhi[i] == i)
      for(int j=i; j<=MAX_N; j+=i)
        EulerPhi[j] = (EulerPhi[j]/i) * (i-1);

  for(int i=1; i<=MAX_N; i++){
    if(i == 1) depthPhi[i] = 0;
    else depthPhi[i] = 1 + depthPhi[EulerPhi[i]];
  }

  for(int i=2; i<=MAX_N; i++)
    sumDepthPhi[i] = depthPhi[i] + sumDepthPhi[i-1];

  int t; cin >> t;
  while(t--){

    int m, n; cin >> m >> n;
    cout << sumDepthPhi[n] - sumDepthPhi[m-1] << "\n";
  }

  return 0;
}
