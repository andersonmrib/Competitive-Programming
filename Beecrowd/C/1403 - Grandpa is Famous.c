#include <stdio.h>
#include <string.h>
#define MAX 10010
int vec[MAX];

int main(){

  int n, m;
  while(scanf("%d %d", &n, &m), n|m){

      memset(vec, 0, sizeof(vec));
      for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int x; scanf("%d", &x);
            vec[x]++;
        }
      }

      int firstMax = 0, secondMax = 0;
      for(int i=0; i<MAX; i++){    // simple algorithm for checking
        if(vec[i] > firstMax){     // the best and all of "second"
            secondMax = firstMax;  // best players
            firstMax = vec[i];
        }
        else if(vec[i] > secondMax)
            secondMax = vec[i];
      }

      for(int i=0; i<MAX; i++){
        if(vec[i] == secondMax)
            printf("%d ", i);
      }
      printf("\n");
  }






  return 0;
}
