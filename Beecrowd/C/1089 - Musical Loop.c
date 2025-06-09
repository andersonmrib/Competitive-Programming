#include <stdio.h>

int main(){

  int samples[10005];
  int n, previous, next, peaks;
  while(scanf("%d", &n), n){
    for(int i=0; i<n; i++)
      scanf("%d", &samples[i]);

    peaks = 0;
    for(int i=0; i<n; i++){
        previous = samples[((i - 1) + n)%n]; //Circular array
        next     = samples[(i + 1)%n];

        if(samples[i] < previous && samples[i] < next ||
           samples[i] > previous && samples[i] > next) peaks++;
    }
    printf("%d\n", peaks);
  }
  return 0;
}
