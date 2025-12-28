#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define F(i, L, R) for(int i=L; i<R; i++)
#define FR(i, R, L) for(int i=R; i>0; i--)
#define endl "\n"

using namespace std;

typedef vector<int> vi;

void solve(int n){

  if(n == 1){
    cout << 1 << endl;
    return;
  }

  if((n&1)){
    cout << n << " ";
    solve(n*3 + 1);
  }
  else{
    cout << n << " ";
    solve(n/2);
  }
}

int32_t main(){

  speedBoost;
  int n; cin >> n;
  solve(n);

  return 0;
}

