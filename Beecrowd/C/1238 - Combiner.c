#include <stdio.h>
#include <string.h>

int main() {

  int n;
  char str1[51], str2[51];

  scanf ("%d", &n);

  for (int i=0;i<n;i++)
  {
      scanf (" %s %s", &str1, &str2);

      int size1, size2;
      int biggerSize;

      size1 = strlen(str1);
      size2 = strlen(str2);

      if (size1 >= size2) biggerSize = size1;
      else biggerSize = size2;

      for (int j=0;j<biggerSize;j++)
      {
        if (j<size1) printf ("%c", str1[j]);
        if (j<size2) printf ("%c", str2[j]);
      }
      printf ("\n");

  }

  return 0;
}
