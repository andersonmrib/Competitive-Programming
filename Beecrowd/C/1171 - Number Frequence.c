#include <stdio.h>

int main(){

  int n; scanf("%d", &n);
  int array[n];

  for (int i=0;i<n;i++)
    scanf("%d", &array[i]);

  for (int i=0;i<n;i++){ //Sort the numbers in ascending order.
    for (int j=i+1;j<n;j++){
        if (array[i] > array[j])
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
      }
    }
    int count = 1;
    for (int i=0;i<n;i++){
      if (i == n - 1 || array[i] != array[i+1]){
        printf("%d aparece %d vez(es)\n", array[i], count);
        count = 1;
      }
        else count++;
    }

  return 0;
}
