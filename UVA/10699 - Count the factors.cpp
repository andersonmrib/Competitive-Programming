#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

#define MAX_N 1000000

int main(){

  speedBoost;
  vector<int> numDiffPFarr(MAX_N+10, 0);
  for(int i=2; i<=MAX_N; i++)
    if(numDiffPFarr[i] == 0)
      for(int j=i; j<=MAX_N; j+=i)
        numDiffPFarr[j]++;

  int n;
  while(cin >> n){
    if(n == 0) return 0;
    cout << n << " : " << numDiffPFarr[n] << "\n";
  }

  return 0;
}
