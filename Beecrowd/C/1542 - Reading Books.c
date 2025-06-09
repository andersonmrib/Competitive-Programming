#include <stdio.h>

int main(){

  int Q, D, P;
  while(scanf("%d %d %d", &Q, &D, &P)){       // we can obtain the formula by just observing the fact that X/Q = X/P + D
    if(!Q) break;                             // X/Q = X/P + D
    int numberOfPages = (P*D*Q) / (P-Q);      // where X equals to the number of pages
    printf("%d pagina", numberOfPages);
    if(numberOfPages > 1) printf("s");
    printf("\n");
  }

  return 0;
}

