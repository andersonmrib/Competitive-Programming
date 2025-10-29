#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"
using namespace std;

int32_t main(){

  speedBoost;
  int limit = 2000;
  int million = 1e6;

  cout << fixed << setprecision(2);
  for(int a=1; (a * 4) <= limit; a++){
    for(int b=a; (a + 3 * b) <= limit; b++){

      int prod_ab = a * b;
      int start_c = max(b, (million / prod_ab + 1));
      for(int c=start_c; (a + b + c * 2) <= limit; c++){

        int sum_abc = a + b + c;
        int pro_abc = a * b * c;

        int numerator = sum_abc * million;
        int denominator = pro_abc - million;

        if(numerator % denominator == 0){
          int d = numerator / denominator;
          if(d < c) continue;

          if(sum_abc + d <= limit){
            cout << (double)a / 100.0 << " ";
            cout << (double)b / 100.0 << " ";
            cout << (double)c / 100.0 << " ";
            cout << (double)d / 100.0 << "\n";
          }
        }
      }
    }
  }

  return 0;
}
