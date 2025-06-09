#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;

const int MAX_N = 2010;
const int MAX_W = 10010;

int N, V[MAX_N], W[MAX_N], memo[MAX_N][MAX_W];

int dp(int id, int remW){
  if((id == N) || (remW == 0)) return 0;
  int &ans = memo[id][remW];
  if(ans != -1) return ans;
  if(W[id] > remW) return ans = dp(id+1, remW);
  return ans = max(dp(id+1, remW), V[id]+dp(id+1, remW-W[id]));
}

int main() {

  speedBoost;

  int C;
  while(cin >> C >> N){

    memset(memo, -1, sizeof memo);
    for(int i=0; i<N; i++)
      cin >> V[i] >> W[i];

    dp(0, C);

    vi itemsSelected;
    int remainingCapacity = C;

    for(int i=0; i<N && remainingCapacity > 0; i++){

      if(i < N-1){
        if(memo[i][remainingCapacity] != memo[i+1][remainingCapacity]){
          itemsSelected.push_back(i);
          remainingCapacity -= W[i];
        }
      }
      else{
        if(memo[i][remainingCapacity] != 0)
          itemsSelected.push_back(i);
      }
    }

    cout << itemsSelected.size() << "\n";
    for(auto x : itemsSelected) cout << x << " ";
    cout << "\n";
  }

    return 0;
}

