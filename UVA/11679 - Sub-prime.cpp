#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;

  int B, N;
  while((cin >> B >> N), (B || N)){

      int bankReserve[B];
      for(int i=0; i<B; i++)
        cin >> bankReserve[i];

      for(int i=0; i<N; i++){
        int D, C, V; cin >> D >> C >> V;
        D--, C--;

        bankReserve[D] -= V;
        bankReserve[C] += V;
      }

      bool hasSolution = true;
      for(int i=0; i<B; i++)
        if(bankReserve[i] < 0)
          hasSolution = false;

      hasSolution ? cout << "S" : cout << "N";
      cout << "\n";
  }

  return 0;
}
