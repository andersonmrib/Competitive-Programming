#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main(){

  int n;
  ull k;
  cin >> n >> k;

  vector<ull> a(n), b(n);
  for(int i=0; i<n; i++)
    cin >> a[i] >> b[i];

  ull low = 1, high = 2e18, ans = high;

  while(low <= high){
    ull mid = low + (high - low)/2;

    ull totalViews = 0;
    for(int i=0; i<n; i++){
       if(mid >= a[i])
         totalViews += (mid - a[i]) / b[i] + 1;
    }

    if(totalViews >= k){
       ans = mid;
       high = mid - 1;
    }
    else
       low = mid + 1;
  }

  cout << ans << endl;

    return 0;
}
