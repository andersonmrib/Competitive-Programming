#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  int n, quantity;
  float value;
  string str;

  cin >> n;
  while(n--){
    unordered_map<string, float> product;
    float ans = 0;

    int m; cin >> m;

    for(int i=0; i<m; i++){
        cin >> str >> value;
        product[str] = value;
    }

    int p; cin >> p;
    for(int i=0; i<p; i++){
        cin >> str >> quantity;
        ans += quantity * product[str];
    }

    printf("R$ %.2f\n", ans);
  }

  return 0;
}
