#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  string number;
  int base;
  while(cin >> number){

    if(number[1] == 'x') base = 16;
    else                 base = 10;

    int aux = stoi(number, nullptr, base);

    if(aux < 0) break;
    if(base == 16) printf("%d\n", aux);
    else           printf("0x%X\n", aux);
  }

  return 0;
}
