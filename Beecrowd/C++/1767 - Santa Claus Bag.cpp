#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int MAX_N = 110;
const int MAX_W = 60;

int pac, toys[MAX_N], W[MAX_N], memo[MAX_N][MAX_W];

int dp(int id, int remW){
  if((id == pac) || (remW == 0)) return 0;
  int &ans = memo[id][remW];
  if(ans != -1) return ans;
  if(W[id] > remW) return ans = dp(id+1, remW);
  return ans = max(dp(id+1, remW), toys[id]+dp(id+1, remW-W[id]));
}

int main(){

  int N; scanf("%d", &N);
  while(N--){
    scanf("%d", &pac);

    memset(memo, -1, sizeof memo);
    for(int i=0; i<pac; i++)
      scanf("%d %d", &toys[i], &W[i]);

    int ans = dp(0, 50);

    printf("%d brinquedos\n", ans);

    vector<int> items;
    int remaining = 50;

    // catch selected items
    for(int i=0; i<pac && remaining > 0; i++){

      if(i < pac-1){
        if(memo[i][remaining] != memo[i+1][remaining]){
          items.push_back(i);
          remaining -= W[i];
        }
      }
      else{    // careful with the last row in the table
        if(memo[i][remaining] != 0)
          items.push_back(i);
      }
    }

    int wei = 0;
    for(auto x : items) wei += W[x];

    printf("Peso: %d kg\n", wei);
    printf("sobra(m) %d pacote(s)\n\n", pac-items.size());

  }

  return 0;
}
