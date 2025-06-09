#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef unsigned long long ull;

ull solve(int n, int k){
  if(k > n - k) k = n - k;
  ull ans = 1;
  for(int i=0; i<k; i++)
    ans = ans * (n - i) / (i + 1);
  return ans;
}

int main(){

  speedBoost;
  int n, k;

  while((cin >> n >> k), (n || k)){
    cout << solve(n, k) << "\n";
  }

  return 0;
}
