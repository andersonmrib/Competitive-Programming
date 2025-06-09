#include <bits/stdc++.h>
using namespace std;

int main(){

  int bigger = 0;
  int candidate;
  int mtr[5][4];
  for(int i=0; i<5; i++){
    int sum = 0;
    for(int j=0; j<4; j++){
      cin >> mtr[i][j];
      sum += mtr[i][j];
    }
   if(sum > bigger){
     bigger = sum;
     candidate = i+1;
   }
  }

  cout << candidate << " " << bigger << endl;

  return 0;
}
