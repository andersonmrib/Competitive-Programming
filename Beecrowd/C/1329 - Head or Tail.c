#include <stdio.h>

int main (){

  int n;
  while(scanf("%d", &n), n){
    int John = 0, Mary = 0;
    int winner;

    for(int i=0; i<n; i++){
     scanf("%d", &winner);
     if(winner) John++;
     else       Mary++;
    }
    printf("Mary won %d times and John won %d times\n", Mary, John);
  }

  return 0;
}
