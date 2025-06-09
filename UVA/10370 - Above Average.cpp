#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  int C; cin >> C;
  while(C--){

    int N; cin >> N;
    int vec[N];
    double average = 0;
    for(int i=0; i<N; i++){
      cin >> vec[i];
      average += vec[i];
    }
    average = average/N;
    double ans = 0;
    for(int i=0; i<N; i++){
      if(vec[i] > average)
        ans++;
    }
    printf("%.3lf%\n", ans/N * 100);
  }

  return 0;
}
