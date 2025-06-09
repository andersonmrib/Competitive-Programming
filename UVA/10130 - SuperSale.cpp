// Top-Down solution
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1010;
const int MAX_W = 40;

int N, V[MAX_N], W[MAX_N], memo[MAX_N][MAX_W];

int dp(int id, int remW){
  if((id == N) || (remW == 0))
    return 0;
  int &ans = memo[id][remW];
  if(ans != -1)
    return ans;  // computed before
  if(W[id] > remW)
    return ans = dp(id+1, remW); // find another one
  return ans = max(dp(id+1, remW), V[id] + dp(id+1, remW-W[id]));
}

int main(){

  int T; scanf("%d", &T);
  while(T--){
    memset(memo, -1, sizeof memo);
    scanf("%d", &N);
    for(int i=0; i<N; i++)
      scanf("%d %d", &V[i], &W[i]);
    int ans = 0;
    int G; scanf("%d", &G);
    while(G--){
      int MW; scanf("%d", &MW);
      ans += dp(0, MW);
    }
    printf("%d\n", ans);
  }

  return 0;
}

/* Bottom-Up solution
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1010;
const int MAX_W = 40;

int N, V[MAX_N], W[MAX_N], C[MAX_N][MAX_W];

int main(){

  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    for(int i=1; i<=n; i++)
      cin >> V[i] >> W[i];
    int ans = 0;
    int g; cin >> g;
    while(g--){
      int mw; cin >> mw;
      for(int i=0; i<=n; i++) C[i][0] = 0;
      for(int w=0; w<=mw; w++) C[0][w] = 0;
      for(int i=1; i<=n; i++)
        for(int w=1; w<=mw; w++){
          if(W[i] > w) C[i][w] = C[i-1][w];
          else         C[i][w] = max(C[i-1][w], V[i]+C[i-1][w-W[i]]);
        }
        ans += C[n][mw];
    }
    cout << ans << endl;
  }

  return 0;
}
*/
