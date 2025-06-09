#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  int n; scanf("%d", &n);
  while(n--){
    int A, B, C; scanf("%d %d %d", &A, &B, &C);
    bool hasSolution = false;
    int x, y, z;
    for(x = -22; (x <= 22) && !hasSolution; x++) if (x*x <= C)
       for(y = -100; (y <= 100) && !hasSolution; y++) if((y != x) && (x*x + y*y <= C))
         for(z = -100; (z <= 100) && !hasSolution; z++)
            if ((z != x) && (z != y) && (x + y + z == A) && (x*y*z == B) && (x*x + y*y + z*z == C)){
              printf("%d %d %d\n", x, y, z);
              hasSolution = true;
         }
            if(!hasSolution) printf("No solution.\n");
  }

  return 0;
}
