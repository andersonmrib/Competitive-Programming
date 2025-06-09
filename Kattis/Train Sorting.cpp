#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;

int main(){

  speedBoost;
  int n; cin >> n;

  vi A(n);
  for(int i=0; i<n; i++)
    cin >> A[i];

  vi LIS;
  deque<int> LDS;

  int ans = 0, inc = 0, dec = 0;
  for(int i=n-1; i>=0; i--){

    int pos1 = lower_bound(LIS.begin(), LIS.end(), A[i]) - LIS.begin();
    int pos2 = lower_bound(LDS.begin(), LDS.end(), A[i]) - LDS.begin();

    if(pos1 == LIS.size()){
      LIS.push_back(A[i]);
      inc = LIS.size();
    }
    else{
      LIS[pos1] = A[i];
      inc = pos1+1;
    }

    if(pos2 == 0){
      LDS.push_front(A[i]);
      dec = LDS.size();
    }
    else{
      LDS[pos2-1] = A[i];
      dec = LDS.size() - pos2 + 1;
    }
    ans = max(ans, inc+dec-1);
  }
  cout << ans << "\n";

  return 0;
}
