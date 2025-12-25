#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

int32_t main(){

  speedBoost;
  int n; cin >> n;

  int sum = n * (n + 1) / 2;
  if(sum % 2 != 0){
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";
  vi s1, s2;
  int target = sum / 2;
  for(int i=n; i>=1; i--){
    if(target >= i){
      target -= i;
      s1.push_back(i);
    }
    else
      s2.push_back(i);
  }

  cout << s1.size() << endl;
  for(int i=0; i<(int)s1.size(); i++){
    if(i > 0) cout << " ";
    cout << s1[i];
  }

  cout << endl;

  cout << s2.size() << endl;
  for(int i=0; i<(int)s2.size(); i++){
    if(i > 0) cout << " ";
    cout << s2[i];
  }

  cout << endl;

  return 0;
}
