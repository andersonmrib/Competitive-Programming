#include <stdio.h>
#include <stdlib.h>

int main() {

  int n;
  int i;
  int *vec;

  scanf ("%d", &n);

  vec = (int *)malloc(n * sizeof(int));

  for (i=0;i<n;i++)
    scanf ("%d", &vec[i]);

 for (i=0;i<n;i++)
 {
     if (vec[i] == 0)
       printf ("NULL\n");
     else if (vec[i]%2 == 0 && vec[i] > 0)
       printf ("EVEN POSITIVE\n");
     else if (vec[i]%2 == 0 && vec[i] < 0)
       printf ("EVEN NEGATIVE\n");
     else if (vec[i] != 0 && vec[i] > 0)
       printf ("ODD POSITIVE\n");
     else if (vec[i] != 0 && vec[i] < 0)
       printf ("ODD NEGATIVE\n");
 }

 free (vec);

    return 0;
}
