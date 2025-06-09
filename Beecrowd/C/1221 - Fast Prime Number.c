#include <stdio.h>

int isPrime(int num){ //0 for Not Prime and 1 for Prime
  if (num < 2) return 0; 
  for (int x=2; x*x <= num; x++)
    if (num%x == 0) return 0;
  return 1;
}

int main(){

  int n; scanf("%d", &n);
  while(n--){
    int number; scanf("%d", &number);
    if (isPrime(number)) printf("Prime\n");
    else printf("Not Prime\n");
  }
  return 0;
}
