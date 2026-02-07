#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

int32_t main(){

  speedBoost;
  int n, k; cin >> n >> k;

  vi a(n);
  for(int i=0; i<n; i++)
    cin >> a[i];

  unordered_map<int, int> freq;
  int ans = 0, l = 0;
  for(int r=0; r<n; r++){

    freq[a[r]]++;
    while((int)freq.size() > k){
      freq[a[l]]--;
      if(freq[a[l]] == 0)
        freq.erase(a[l]);
      l++;
    }

    ans += (r - l + 1);
  }

  cout << ans << endl;

  return 0;
}
