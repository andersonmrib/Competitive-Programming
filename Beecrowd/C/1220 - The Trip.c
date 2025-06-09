#include <stdio.h>

int main(){

  int n;
  int student[1001];
  while(scanf("%d", &n), n){

    int integerValue, decimalValue;
    double average = 0.0;
    for(int i=0; i<n; i++){
        scanf("%d.%d", &integerValue, &decimalValue);
        student[i] = integerValue*100 + decimalValue;
        average += student[i];
    }

    average = (double)average/n;
    double aboveAverage = 0, belowAverage = 0;

    for(int i=0; i<n; i++){
        if(student[i] < average) belowAverage += (int)(average - student[i]);
        else                     aboveAverage += (int)(student[i] - average);
    }

    if(belowAverage > aboveAverage) printf("$%.2lf\n", belowAverage/100.0);
    else                            printf("$%.2lf\n", aboveAverage/100.0);
  }

 return 0;
}
