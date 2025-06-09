#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979310

int main(){

  int n; scanf("%d", &n);
  while(n--){
    int L; scanf("%d", &L);
    double aphotem = L/(2*tan(36*PI/180));
    double area = (5*L*aphotem)/2;
    printf("%.3lf\n", area);
  }

  return 0;
}
