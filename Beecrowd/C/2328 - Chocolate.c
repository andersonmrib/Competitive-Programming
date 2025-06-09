#include <stdio.h>
#include <math.h>

int main(){

  int n; scanf("%d", &n);
  int remainingPieces = 0;
  while(n--){
    int parts; scanf("%d", &parts);
    remainingPieces += parts - 1;
  }
    printf("%d\n", remainingPieces);

  return 0;
}
