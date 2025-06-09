#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  int n;
  while(scanf("%d", &n), n){

    vector<int> vec(n);
    for(int i=0; i<n; i++)
      scanf("%d", &vec[i]);

    sort(vec.begin(), vec.end());

    for(int i=0; i<n; i++){
      if(i == 0) printf("%d", vec[i]);
      else printf(" %d", vec[i]);
    }
    printf("\n");
  }

  return 0;
}
