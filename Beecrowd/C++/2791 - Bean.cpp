#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  int C[4];

  for(int i=0; i<4; i++)
    cin >> C[i];

  for(int i=0; i<4; i++)
    if(C[i]) cout << i+1 << endl;

  return 0;
}
