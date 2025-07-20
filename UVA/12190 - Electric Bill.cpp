#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
using namespace std;

int getPrice(int x){
  int sum = 0;
  if(x > 1000000) sum += (x - 1000000) * 7, x = 1000000;
  if(x > 10000)   sum += (x - 10000) * 5, x = 10000;
  if(x > 100)     sum += (x - 100) * 3, x = 100;
  if(x > 0)       sum += x * 2;
  return sum;
}

int32_t main(){

  speedBoost;
  int A, B;
  while((cin >> A >> B), (A || B)){

    int l = 0, h = 2e9, totalConsumption = -1;
    while(l <= h){
      int mid = (l+h)/2;
      int p = getPrice(mid);
      if(p < A)
        l = mid + 1;
      else if(p > A)
        h = mid - 1;
      else{
        totalConsumption = mid;
        break;
      }
    }

    l = 0, h = totalConsumption;
    int ans = -1;
    while(l <= h){
      int mid = (l+h)/2;
      int c1 = getPrice(mid), c2 = getPrice(totalConsumption - mid);
      int diff = abs(c1 - c2);

      if(diff < B)
        l = mid + 1;
      else if(diff > B)
        h = mid - 1;
      else{
        ans = min(c1, c2);
        break;
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
