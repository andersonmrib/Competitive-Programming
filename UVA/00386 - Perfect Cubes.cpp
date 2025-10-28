#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  int cube[201];
  for(int i=1; i<=200; i++)
    cube[i] = i * i * i;

  for(int a=2; a<=200; a++){
    for(int b=2; b<a; b++){
      for(int c=b; c<a; c++){
        for(int d=c; d<a; d++){
          if(cube[a] == (cube[b] + cube[c] + cube[d]))
            printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
        }
      }
    }
  }

  return 0;
}
