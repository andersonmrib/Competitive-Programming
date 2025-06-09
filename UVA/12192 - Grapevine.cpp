#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
using namespace std;

int mtr[501][501];

int main(){

  speedBoost;
  int N, M;
  while((cin >> N >> M), (N || M)){

    for(int i=0; i<N; i++)
      for(int j=0; j<M; j++)
        cin >> mtr[i][j];

    int Q; cin >> Q;
    while(Q--){

      int L, U; cin >> L >> U;
      int ans = 0;
      for(int i=0; i<N; i++){
        // gives us the initial column's index where we
        // are going to start expanding
        int left = lower_bound(mtr[i], mtr[i] + M, L) - mtr[i];
        if(left >= M) continue;

        for(int j=ans; j<N; j++){
          int newRow = i+j, newCol = left+j;
          if(newRow >= N || newCol >= M || mtr[newRow][newCol] > U)
            break;
          ans = j+1;
        }
      }
        cout << ans << "\n";
    }
    cout << "-\n";
  }

  return 0;
}
