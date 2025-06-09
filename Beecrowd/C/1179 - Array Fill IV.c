#include <stdio.h>

int main(){

  int loop = 15;
  int evenArr[5], oddArr[5];
  int even = 0, odd = 0;

  while(loop--){

    int number; scanf("%d", &number);

    if(number%2 == 0)
    {
        evenArr[even] = number;
        even++;
        if(even == 5)
        {
            for(int i=0; i<5; i++)
                printf("par[%d] = %d\n", i, evenArr[i]);
            even = 0;
        }
    }
    else
    {
        oddArr[odd] = number;
        odd++;
        if(odd == 5)
        {
            for(int i=0; i<5; i++)
                printf("impar[%d] = %d\n", i, oddArr[i]);
            odd = 0;
        }
    }
  }
    for(int i=0; i<odd; i++)
        printf("impar[%d] = %d\n", i, oddArr[i]);

    for(int i=0; i<even; i++)
        printf("par[%d] = %d\n", i, evenArr[i]);

  return 0;
}
