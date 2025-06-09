#include <stdio.h>

int main(){

  int n;
  while(scanf("%d", &n) != EOF){
    int repunit = 1;                        // the lowest number we can get
    int length = 1;                         // is 1, with length 1

    while(repunit % n != 0){
        repunit = (repunit * 10 + 1) % n;   // and using modular arithmetic we
        length++;                           // can compute if the number is
    }                                       // divisible by n

    printf("%d\n", length);
  }

  return 0;
}
