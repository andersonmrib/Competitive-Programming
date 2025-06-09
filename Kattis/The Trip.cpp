#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n;
  while((cin >> n), n){

    vector<double> st(n);
    double total = 0;
    for(int i=0; i<n; i++){
      cin >> st[i];
      total += st[i];
    }

    double avg = total/n;
    double positiveDiff = 0, negativeDiff = 0;

    for(int i=0; i<n; i++){
      double diff = (double)(int)((st[i] - avg)*100.0)/100.0;
      if(diff > 0)
        positiveDiff += diff;
      else
        negativeDiff -= diff;
    }

    printf("$%.2lf\n", max(positiveDiff, negativeDiff));
  }

  return 0;
}
