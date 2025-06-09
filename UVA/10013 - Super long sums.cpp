#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

string getSum(string a, string b){
  string ans = "";
  int carry = 0;
  int i = a.size() - 1, j = b.size() - 1;
  while(i >= 0 || j >= 0 || carry){
    int dig1 = (i >= 0 ? a[i--] - '0' : 0);
    int dig2 = (j >= 0 ? b[j--] - '0' : 0);
    int sum = dig1 + dig2 + carry;
    carry = sum/10;
    ans.push_back((sum%10) + '0');
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    string s1 = "", s2 = "";
    int m; cin >> m;
    for(int i=0; i<m; i++){
      char a, b; cin >> a >> b;
      s1.push_back(a), s2.push_back(b);
    }

    string ans = getSum(s1, s2);
    cout << ans << "\n";

    if(t) cout << "\n";

  }

  return 0;
}
