#include <stdio.h>

int main(){

  int n; scanf("%d", &n);
  while(n--){
    float x; scanf("%f", &x);
    int days = 0;
    while(x > 1.0){
      x /= 2.0;
      days++;
    }
    printf("%d dias\n", days);
  }

 return 0;
}
