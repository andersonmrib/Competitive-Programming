#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

string multiply(const string a, const string b){

  int n = a.size() - 1, m = b.size() - 1;
  vector<int> res(n + m + 2, 0);
  for(int i=n; i>=0; i--){
    for(int j=m; j>=0; j--){

      int mult = (a[i] - '0') * (b[j] - '0');
      int sum = mult + res[i+j+1];

      res[i+j+1] = sum % 10;
      res[i+j]  += sum / 10;
    }
  }

  string ans = "";
  bool leading = true;
  for(auto d : res){
    if(leading && d == 0) continue;
    leading = false;
    ans += d + '0';
  }

  return ans.empty() ? "0" : ans;
}

int main(){

  speedBoost;
  string a, b;
  while(cin >> a >> b){

    string ans = multiply(a, b);
    cout << ans << endl;
  }

  return 0;
}


