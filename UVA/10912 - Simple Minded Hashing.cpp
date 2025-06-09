#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int memo[27][27][361];
int dp(int L, int last, int S){

  if(L == 0) return S == 0;
  if(L < 0 || last > 26 || S < 0) return 0;
  if(L > 26 || S > 351) return 0;

  int &ans = memo[L][last][S];
  if(ans != -1) return ans;

  ans = 0;
  for(int i=last+1; i<=26; i++)
    ans += dp(L - 1, i, S - i);
  return ans;
}

int main(){

  speedBoost;
  memset(memo, -1, sizeof memo);
  int L, S;
  int NC = 0;
  while((cin >> L >> S), (L || S)){

    cout << "Case " << ++NC << ": ";
    cout << dp(L, 0, S) << "\n";
  }

  return 0;
}
