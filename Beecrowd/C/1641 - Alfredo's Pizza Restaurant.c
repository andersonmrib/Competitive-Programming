#include <stdio.h>
#include <math.h>

int main(){

  int R, W, L;
  int countt = 0;
  float hypotenuse;
  while(scanf("%d", &R), R){
    scanf("%d %d", &W, &L);

    hypotenuse = sqrt(W*W + L*L);

    if(R*2 < hypotenuse) printf("Pizza %d does not fit on the table.\n", ++countt);
    else                 printf("Pizza %d fits on the table.\n", ++countt);




  }




  return 0;
}
