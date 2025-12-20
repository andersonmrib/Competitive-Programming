#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

typedef vector<int> vi;


int main(){

  speedBoost;
  int t; cin >> t;
  int NC = 1;
  while(t--){

    int n; cin >> n;

    vi heights(n), weigths(n);
    for(int i=0; i<n; i++)
      cin >> heights[i];
    for(int i=0; i<n; i++)
      cin >> weigths[i];

    vi dp_inc(n), dp_dec(n);
    int max_inc = 0, max_dec = 0;
    for(int i=0; i<n; i++){

      dp_inc[i] = weigths[i];
      dp_dec[i] = weigths[i];

      for(int j=0; j<i; j++){
        if(heights[i] > heights[j])
          dp_inc[i] = max(dp_inc[i], dp_inc[j] + weigths[i]);

        if(heights[i] < heights[j])
          dp_dec[i] = max(dp_dec[i], dp_dec[j] + weigths[i]);
      }

      max_inc = max(max_inc, dp_inc[i]);
      max_dec = max(max_dec, dp_dec[i]);
    }

    cout << "Case " << NC++ << ". ";
      if(max_inc >= max_dec){
        cout << "Increasing (" << max_inc << "). ";
        cout << "Decreasing (" << max_dec << ").\n";
      }
      else{
        cout << "Decreasing (" << max_dec << "). ";
        cout << "Increasing (" << max_inc << ").\n";
      }
  }

  return 0;
}
