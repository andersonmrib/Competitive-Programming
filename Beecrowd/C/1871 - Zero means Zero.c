#include <stdio.h>

int main(){

  long m, n;
  long vector[10];
  while(scanf("%ld %ld", &m, &n), (m || n)){
  long sum = m + n;

  for (int i=0;i<10;i++){
    vector[i] = sum%10;
    sum/=10;
   }

   for (int i=9;i>=0;i--){
    if (vector[i] == 0) continue;
    printf ("%ld", vector[i]);
  }
    printf ("\n");
  }

  return 0;
}
