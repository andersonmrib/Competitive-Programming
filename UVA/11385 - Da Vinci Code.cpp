#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

int32_t main(){

  speedBoost;

  unordered_map<int, int> idx;
  idx[1] = 1, idx[2] = 2;
  int v1 = 1, v2 = 2;
  for(int i=3; i<=45; i++){
    int next = v1 + v2;
    idx[next] = i;
    v1 = v2, v2 = next;
  }

  int t; cin >> t;
  while(t--){

    int n; cin >> n;
    vi key(n);
    for(int i=0; i<n; i++)
      cin >> key[i];

    string line; getline(cin >> ws, line);

    unordered_map<int, char> decoded_map;
    int max_len = 0, ptr = 0;
    for(auto c : line){
      if(isupper(c) && ptr < n){
        int pos = idx[key[ptr]];
        decoded_map[pos] = c;
        max_len = max(max_len, pos);
        ptr++;
      }
    }

    string ans = "";
    for(int i=1; i<=max_len; i++){
      if(decoded_map.count(i))
        ans += decoded_map[i];
      else
        ans += " ";
    }

    cout << ans << endl;
  }

  return 0;
}
