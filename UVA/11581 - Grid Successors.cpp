#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int mtr[3][3];
int auxMtr[3][3];

bool isPossible(){
  int numZeros = 0;
  for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
      if(mtr[i][j] == 0)
        numZeros++;
  if(numZeros == 9)
    return false;
  return true;
}

int main(){

  int t; cin >> t;
  while(t--){

    memset(mtr, 0, sizeof mtr);
    memset(auxMtr, 0, sizeof auxMtr);

    for(int i=0; i<3; i++)
      for(int j=0; j<3; j++)
        scanf("%1d", &mtr[i][j]);

    int ans = 0;
    while(isPossible()){
      auxMtr[0][0] = (mtr[0][1] + mtr[1][0])%2;
      auxMtr[0][1] = (mtr[0][0] + mtr[1][1] + mtr[0][2])%2;
      auxMtr[0][2] = (mtr[1][2] + mtr[0][1])%2;
      auxMtr[1][0] = (mtr[0][0] + mtr[1][1] + mtr[2][0])%2;
      auxMtr[1][1] = (mtr[1][0] + mtr[0][1] + mtr[1][2] + mtr[2][1])%2;
      auxMtr[1][2] = (mtr[0][2] + mtr[1][1] + mtr[2][2])%2;
      auxMtr[2][0] = (mtr[1][0] + mtr[2][1])%2;
      auxMtr[2][1] = (mtr[2][0] + mtr[1][1] + mtr[2][2])%2;
      auxMtr[2][2] = (mtr[2][1] + mtr[1][2])%2;

      for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
          mtr[i][j] = auxMtr[i][j];
      memset(auxMtr, 0, sizeof auxMtr);
      ans++;
    }
    cout << ans - 1 << "\n";
  }

  return 0;
}
