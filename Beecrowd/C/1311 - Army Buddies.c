#include <stdio.h>

int main(){

  int left[100010], right[100010];
  int s, b, l, r;

  while(scanf("%d %d", &s, &b), s){
    for(int i=1; i<=s; i++){
      left[i]  = i - 1;
      right[i] = i + 1;
    }

    for(int i=0; i<b; i++){
      scanf("%d %d", &l, &r);
      if(left[l] < 1) printf("*");          // checks the inferior limit
      else            printf("%d", left[l]);

      if(right[r] > s) printf(" *\n");      // checks the superior limit
      else             printf(" %d\n", right[r]);

      left[right[r]] = left[l];             // simply updates the range of the soldiers
      right[left[l]] = right[r];
    }
    printf("-\n");
  }

  return 0;
}
