#include <stdio.h>

int main(){

  char name[110];
  double ans = 0, count = 0, number;

  while(scanf("%[^\n]", name) != EOF){
    scanf("%lf", &number);
    getchar();
    ans += number;
    count++;
  }
  printf("%.1lf\n", ans/count);

  return 0;
}
