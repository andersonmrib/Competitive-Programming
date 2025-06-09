#include <stdio.h>

int main(){

  int r, l; scanf("%d %d", &r, &l);

  float volume = (4.0/3.0) * 3.1415 * r * r * r;
  float ans = l/volume;

  printf("%d\n", (int)ans);

  return 0;
}
