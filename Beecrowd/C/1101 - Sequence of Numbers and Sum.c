#include <stdio.h>

int main (){

  int m, n;
  while (scanf("%d %d", &m, &n)){

    if (m<=0 || n<=0) break;
                              /* ----------- */
    int smallest, biggest;    /* Simple swap */
                              /* ----------- */
    if (m > n) {
        biggest = m;
        smallest = n;
        }
    else {
        biggest = n;
        smallest = m;
        }

    int sum = 0;

    for (int i=smallest;i<=biggest;i++){
        printf ("%d ", i);
        sum += i;
    }
        printf ("Sum=%d\n", sum);
  }

  return 0;
}
