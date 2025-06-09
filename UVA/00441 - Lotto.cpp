#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  bool first = true;
  int k;
  while(scanf("%d", &k), k){
    if(!first) printf("\n");
    first = false;
    int s[16];
    for(int i=0; i<k; i++) scanf("%d", &s[i]);
    for(int a=0; a<k-5; a++)
      for(int b=a+1; b<k-4; b++)
        for(int c=b+1; c<k-3; c++)
          for(int d=c+1; d<k-2; d++)
            for(int e=d+1; e<k-1; e++)
              for(int f=e+1; f<k; f++)
                printf("%d %d %d %d %d %d\n", s[a], s[b], s[c], s[d], s[e], s[f]);
  }

  return 0;
}
