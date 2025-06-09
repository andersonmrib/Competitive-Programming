#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int left[100010], right[100010];
  int s, b;

  while((cin >> s >> b), (s || b)){

    for(int i=1; i<=s; i++){
      left[i] = i - 1;
      right[i] = i + 1;
    }

    for(int i=0; i<b; i++){
      int l, r; cin >> l >> r;
      if(left[l] < 1) cout << "*";
      else            cout << left[l];

      if(right[r] > s) cout << " *\n";
      else             cout << " " << right[r] << "\n";

      left[right[r]] = left[l];
      right[left[l]] = right[r];
    }
    cout << "-\n";
  }

  return 0;
}
