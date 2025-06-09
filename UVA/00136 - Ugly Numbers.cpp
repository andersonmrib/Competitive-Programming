#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

bool findUgly(int num){

  while(num%2 == 0) num >>= 1;
  while(num%3 == 0) num /= 3;
  while(num%5 == 0) num /= 5;

  if(num == 1) return true;
  return false;
}

int main(){

  cout << "The 1500'th ugly number is " << 859963392 << ".\n";
  return 0;
}

/*
int main(){

  speedBoost;
  int count = 0;
  for(int i=1;; i++){
    if(findUgly(i)) count++;
    if(count == 1500){
      cout << "ans: " << i << endl;
      break;
    }
  }

    cout << count << endl;
  return 0;
}
*/
