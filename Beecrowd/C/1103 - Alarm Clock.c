#include <stdio.h>

int main(){

  int h1, m1, h2, m2;
  while(scanf("%d %d %d %d", &h1, &m1, &h2, &m2), (h1||m1||h2||m2)){

    int initTime = h1*60 + m1;
    int finalTime = h2*60 + m2;

    if(finalTime < initTime) finalTime += 1440;

    int remainingTime = finalTime - initTime;
    printf("%d\n", remainingTime);
  }

  return 0;
}
