#include <bits/stdc++.h>
using namespace std;

float calculate(int num){
  switch(num){
    case 1001:
     return 1.50;
   case 1002:
     return 2.50;
   case 1003:
     return 3.50;
   case 1004:
     return 4.50;
   case 1005:
     return 5.50;
   default:
     return 0.0;
  }
}

int main(){

  int p; cin >> p;
  float ans = 0;
  while(p--){
    int id, quantity; cin >> id >> quantity;
    ans += quantity * calculate(id);
  }
  printf("%.2f\n", ans);

  return 0;
}
