#include <stdio.h>
#include <stdlib.h>

int main() {

  int c; //Number of test case;
  int i, j;

  scanf ("%d", &c);

  for (i=0;i<c;i++)
  {
      unsigned int n; //Number of students in the class (local variable).
      float gradeSum = 0.0, med = 0;
      int count = 0;

      scanf ("%d", &n);

      float *grade = (float*)malloc(n * sizeof(float));

      for (j=0;j<n;j++) //Makes the sum of the grades and calculates the media after the end of the loop.
      {
          scanf ("%f", &grade[j]);
          gradeSum +=  grade[j];
      }
      med = gradeSum/n;

      for (j=0;j<n;j++) // Checks how many students have got more than the media calculated.
      {
          if (grade[j] > med)
            count++;
      }

      printf ("%.3f%%\n", 1.0*100*count/n);

      free(grade);
  }

  return 0;
}
