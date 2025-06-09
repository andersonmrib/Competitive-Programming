#include <stdio.h>
#include <stdlib.h>

int compare(const void *num1, const void *num2){
  int a = *((int*)num1);
  int b = *((int*)num2);

  return a - b;
}

int main(){                                  // this code uses a simple linear search
                                             // for solving the problem
  int n, q;                                  // be aware that with big arrays, a binary search may be needed
  int numCases = 0;
  while(scanf("%d %d", &n, &q), n, q){

    int value, querie;
    int marbles[n];

    for(int i=0; i<n; i++)
      scanf("%d", &marbles[i]);

    qsort(marbles, n, sizeof(int), compare);
    printf("CASE# %d:\n", ++numCases);

    for(int i=0; i<q; i++){
      scanf("%d", &querie);

    int position = -1;
      for(int j=0; j<n; j++){
        if(marbles[j] == querie){
          position = j+1;
          break;
        }
      }

      if(position != -1) printf("%d found at %d\n", querie, position);
      else               printf("%d not found\n", querie);
    }
  }

  return 0;
}
