#include <stdio.h>

int comp(const void *x, const void *y){
  return *(int *)y - *(int *)x;
}

int main(){

  int n, m; scanf("%d", &n);

  while(n--){
    scanf("%d", &m);
    int arr[m], arrCopy[m];
    int ans = 0;
    for(int i=0; i<m; i++)
    {
        scanf("%d", &arr[i]);
        arrCopy[i] = arr[i];
    }

    qsort(arr, m, sizeof(int), comp); //Sorts the original array

    for(int i=0; i<m; i++)
        if(arr[i] == arrCopy[i]) ans++;

    printf("%d\n", ans);
  }

  return 0;
}
