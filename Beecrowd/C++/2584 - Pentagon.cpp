#include <bits/stdc++.h>
using namespace std;

int main(){

  int n; cin >> n;
  while(n--){
    int L; cin >> L;
    double aphotem = L/(2*tan(36*M_PI/180));
    double area = (5*L*aphotem)/2;
    printf("%.3lf\n", area);
  }

  return 0;
}
