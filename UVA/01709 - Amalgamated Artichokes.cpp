#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

/*

Note:
sin(X + Y) = sin(X) * Cos(Y) + sin(Y) * cos(X)
cos(X + Y) = cos(X) * cos(Y) - sin(X) * cos(Y)

If you can get sin(a*k + b), you can get sin(a*(k+1) + b) for k = 2, k = 3...
Just try to write on paper to see the relation...

*/

int main(){

  speedBoost;
  int p, a, b, c, d, n;
  while(cin >> p >> a >> b >> c >> d >> n){

    double sin_a = sin(a);
    double cos_a = cos(a);
    double sin_c = sin(c);
    double cos_c = cos(c);

    double cur_sin_val = sin(a + b);
    double cos_sin_update = cos(a + b);
    double cur_cos_val = cos(c + d);
    double sin_cos_update = sin(c + d);

    double max_price_so_far = p * (cur_sin_val + cur_cos_val + 2.0);
    double max_decline = 0.0;

    for(int k=2; k<=n; k++){
      double next_sin_val = cur_sin_val * cos_a + cos_sin_update * sin_a;
      double next_cos_sin_update = cos_sin_update * cos_a - cur_sin_val * sin_a;
      cur_sin_val = next_sin_val, cos_sin_update = next_cos_sin_update;

      double next_cos_val = cur_cos_val * cos_c - sin_cos_update * sin_c;
      double next_sin_cos_update = sin_cos_update * cos_c + sin_c * cur_cos_val;
      cur_cos_val = next_cos_val, sin_cos_update = next_sin_cos_update;

      double cur_price = p * (cur_sin_val + cur_cos_val + 2.0);
      double diff = max_price_so_far - cur_price;

      if(diff > max_decline) max_decline = diff;

      if(cur_price > max_price_so_far) max_price_so_far = cur_price;
    }

    cout << fixed << setprecision(8);
    cout << max_decline << endl;
  }

  return 0;
}

/*

Naïve implementation
Runs horribly in ~ 1.5 seconds

#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

float price(int p, int a, int b, int c, int d, int k){
  return p * (sin(a * k + b) + cos(c * k + d) + 2);
}

int main(){

  speedBoost;
  int p, a, b, c, d, n;
  while(cin >> p >> a >> b >> c >> d >> n){

    double max_so_far = price(p, a, b, c, d, 1);
    double ans = 0.0;

    for(int k=2; k<=n; k++){

      double curr = price(p, a, b, c, d, k);
      double diff = max_so_far - curr;

      // Always picks the highest point
      if(curr > max_so_far)
        max_so_far = curr;

      // Always picks the highest difference
      if(diff > ans)
        ans = diff;
    }

    cout << fixed << setprecision(8);
    cout << ans << endl;
  }

  return 0;
}

*/
