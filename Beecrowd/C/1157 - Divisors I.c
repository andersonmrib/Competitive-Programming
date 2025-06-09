#include <stdio.h>

int main(){

  int n; scanf("%d", &n);

  for(int x=1; x<=n; x++)
    if(!(n%x)) printf("%d\n", x);

  return 0;
}
