#include <stdio.h>

int main() {

  float n1, n2, n3, n4;
  float med;

  scanf ("%f %f %f %f", &n1, &n2, &n3, &n4);

  med = (2*n1 + 3*n2 + 4*n3 + n4)/10.0;

  if (med >= 7.0)
  {
      printf ("Media: %.1f\n", med);
      printf ("Aluno aprovado.\n");
  }
  if (med < 5.0)
  {
      printf ("Media: %.1f\n", med);
      printf ("Aluno reprovado.\n");
  }
  if (med >= 5.0 && med <= 6.9)
  {
      float exam, newMed;

      printf ("Media: %.1f\n", med);
      printf ("Aluno em exame.\n");

      scanf ("%f", &exam);

      printf ("Nota do exame: %.1f\n", exam);

      newMed = (med + exam)/2.0;

      if (newMed >= 5.0)
      {
          printf ("Aluno aprovado.\n");
          printf ("Media final: %.1f\n", newMed);
      }
      else
      {
          printf ("Aluno reprovado.\n");
          printf ("Media final: %.1f\n", newMed);
      }
  }

  return 0;
}
