#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n;
  while((cin >> n), n){

    int arr[n];
    for(int i=0; i<n; i++)
      cin >> arr[i];

    int ans = 0, sum = 0;
    for(int i=0; i<n; i++){
      sum += arr[i];
      ans = max(ans, sum);
      if(sum < 0) sum = 0;
    }

    if(ans) printf("The maximum winning streak is %d.\n", ans);
    else    printf("Losing streak.\n");
  }

  return 0;
}
