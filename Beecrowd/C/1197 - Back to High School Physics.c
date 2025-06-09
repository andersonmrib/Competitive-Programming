#include <stdio.h>

int main(){

  int v, t;
  while(scanf("%d %d", &v, &t) != EOF)
  printf("%d\n", v*t*2); //finalPosition = initialPosition + velocity * time
                         //finalPosition = 0 + velocity * time
                         //finalPosition = velocity * time * 2 (problem asks for the position after the double of the time)
  return 0;
}
