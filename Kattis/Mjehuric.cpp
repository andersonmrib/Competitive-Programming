#include <bits/stdc++.h>
using namespace std;

void change(int* x, int* y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

void bubbleSort(int A[], int len){
  int i, j;
  bool flag = true;
  for(int i=0; i<len-1; i++){
    flag = true;
    for(int j=0; j<len-i-1; j++){
      if(A[j] > A[j+1]){
        change(&A[j], &A[j+1]);
        cout << A[0];
        for(int h=1; h<len; h++)
          cout << " " << A[h];
        cout << endl;
        flag = false;
      }
    }
  }
}

int main(){

  int arr[5];

  for(int i=0; i<5; i++)
    cin >> arr[i];

  bubbleSort(arr, 5);

  return 0;
}
