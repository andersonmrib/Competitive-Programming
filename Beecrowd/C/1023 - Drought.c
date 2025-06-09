#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){

  int n, first, testCases = 0, residenceConsumption[201];
  double average_consumption;
  while(scanf("%d", &n), n){

    if(testCases)printf("\n");
    memset(residenceConsumption, 0, sizeof(residenceConsumption));

    int totalx = 0, totaly = 0;
    while(n--){
      int x, y;
      scanf("%d %d", &x, &y);
      totalx += x;
      totaly += y;
      residenceConsumption[y/x] += x;
    }

    printf("Cidade# %d:\n", ++testCases);
    first = 1;
    for(int i=0; i<201; i++){
      if(residenceConsumption[i] > 0){
        if(first) first = 0;
        else printf(" ");
        printf("%d-%d", residenceConsumption[i], i);
      }
    }

    average_consumption = floor((100.0*totaly/totalx))/100.0;      // careful with precision
    printf("\nConsumo medio: %.2lf m3.\n", average_consumption);   // use floor for avoiding
  }                                                                // possible errors

  return 0;
}
