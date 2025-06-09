#include <stdio.h>

int main(){

  int vec[3];
  while(scanf("%d %d %d", &vec[0], &vec[1], &vec[2]) != EOF){

    for (int i=0;i<3;i++){   //Sort the numbers in ascending order.
      for (int j=i+1;j<3;j++){
        if (vec[i] > vec[j])
        {
          int temp = vec[i];
          vec[i] = vec[j];
          vec[j] = temp;
        }
      }
    }

    if (vec[2] * vec[2] == (vec[0] * vec[0] + vec[1] * vec[1]))
    {
       int gcd = 1;
       for(int div=2; div<=vec[0]; div++)
       {
           if ((vec[0]%div == 0) && (vec[1]%div == 0) && (vec[2]%div == 0))
            gcd = div;
       }

       if (gcd == 1) printf ("tripla pitagorica primitiva\n");
       else printf ("tripla pitagorica\n");
    }
    else printf ("tripla\n");
  }

  return 0;
}