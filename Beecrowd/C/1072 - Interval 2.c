#include <stdio.h>
#include <stdlib.h>

int main() {

  unsigned int n;
  unsigned int i;
  int inside = 0, outside = 0;
  scanf ("%u", &n);

 int *ptr = (int*)malloc(n * sizeof(int));

  for (i=0;i<n;i++)
  {
    scanf ("%d", &ptr[i]);
  }
    for (i=0;i<n;i++)
    {
        if (ptr[i] >= 10 && ptr[i] <= 20)
        inside++;
        else outside++;
    }

    printf ("%d in\n", inside);
    printf ("%d out\n", outside);

    free(ptr);

  return 0;
}
