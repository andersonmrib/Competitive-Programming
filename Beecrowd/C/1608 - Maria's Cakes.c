#include <stdio.h>
#include <stdlib.h>

int sort(const void *x, const void *y){
    int a = *((int*)x);
    int b = *((int*)y);

    return a - b;
}

int main(){

  int T, D, I, B; scanf("%d", &T);
  while(T--){
    scanf("%d %d %d", &D, &I, &B);
    int ingredients[I];
    int costs[B];

    for(int c=0; c<B; c++)
        costs[c] = 0;

    for(int i=0; i<I; i++)
        scanf("%d", &ingredients[i]);

    for(int j=0; j<B; j++){
        int Q; scanf("%d", &Q);
        for(int k=0; k<Q; k++){
            int index, quantity;
            scanf("%d %d", &index, &quantity);
            costs[j] += ingredients[index] * quantity;
        }
    }

    qsort(costs, B, sizeof(int), sort);
    printf("%d\n", D/costs[0]);
  }
  return 0;
}
