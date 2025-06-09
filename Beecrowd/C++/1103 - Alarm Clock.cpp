#include <bits/stdc++.h>
using namespace std;

int main(){

  int h1, m1, h2, m2;
  while((cin >> h1 >> m1 >> h2 >> m2), (h1||m1||h2||m2)){
    int initTime = h1*60 + m1;
    int finalTime = h2*60 + m2;
    if(finalTime <= initTime) finalTime += 1440;

    int remainingTime = finalTime - initTime;
    cout << remainingTime << endl;
  }

  return 0;
}
