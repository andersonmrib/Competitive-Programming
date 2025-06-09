#include <stdio.h>

int main(){
  int a, b, c, h, l;
  scanf("%d %d %d %d %d", &a, &b, &c, &h, &l);

  if((a <= h && b <= l) || (a <= l && b <= h) ||
     (a <= h && c <= l) || (a <= l && c <= h) ||
     (b <= h && c <= l) || (b <= l && c <= h))
    printf("S\n");
  else
    printf("N\n");

  return 0;
}
