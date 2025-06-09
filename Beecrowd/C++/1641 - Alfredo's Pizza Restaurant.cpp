#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  int R, W, L;
  int countt = 0;
  float hypotenuse;
  while(cin >> R, R){
    cin >> W >> L;

    hypotenuse = sqrt(W*W + L*L);
    if(R*2 < hypotenuse) printf("Pizza %d does not fit on the table.\n", ++countt);
    else                 printf("Pizza %d fits on the table.\n", ++countt);
  }

  return 0;
}
