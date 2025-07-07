#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int A[55], memo[55][55];
int l, r, n;

int cut(int left, int right){
  if(left+1 == right) return 0;
  int &ans = memo[left][right];
  if(ans != -1) return ans;
  ans = 2e9;
  for(int i=left+1; i<right; i++)
    ans = min(ans, cut(left, i) + cut(i, right) + (A[right] - A[left]));
  return ans;
}

int main(){

  speedBoost;
  while(cin >> l, l){
    A[0] = 0;
    cin >> n;
    for(int i=1; i<=n; i++)
      cin >> A[i];
    A[n+1] = l;
    memset(memo, -1, sizeof memo);
    cout << "The minimum cutting is " << cut(0, n+1) << ".\n";
  }

  return 0;
}
