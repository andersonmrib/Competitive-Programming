#include <stdio.h>

int primeChecker (int n){
  if (n < 2) return 0;
  for(int x = 2; x*x <= n; x++){
    if (n%x == 0) return 0;
   }
    return 1;
}

int main(){

  int n; scanf("%d", &n);
  while(n--){
    int num;
    scanf("%d", &num);
    if(primeChecker(num)) printf ("%d eh primo\n", num);
    else printf("%d nao eh primo\n", num);
  }

  return 0;
}
