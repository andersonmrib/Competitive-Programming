#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

unordered_map<char, char> umap;
void prepare(){
  string normal = "AEHIJLMOSTUVWXYZ12358";
  string revs  = "A3HILJMO2TUVWXY51SEZ8";
  for(int i=0; i<normal.size(); i++)
    umap[normal[i]] = revs[i];
}

bool is_palindrome(string s){
  string tmp = s;
  reverse(tmp.begin(), tmp.end());
  return s == tmp;
}

bool is_mirrored(string s){
  string tmp = "";
  for(int i=s.size()-1; i>=0; i--){
    if(umap.count(s[i]))
      tmp += umap[s[i]];
    else
      return false;
  }
  return s == tmp;
}

int32_t main(){

  speedBoost;
  prepare();
  string s;
  while(cin >> s){

    bool p = is_palindrome(s);
    bool m = is_mirrored(s);

    cout << s << " -- is ";
    if (!p && !m) cout << "not a palindrome.";
    else if (p && !m) cout << "a regular palindrome.";
    else if (m && !p) cout << "a mirrored string.";
    else cout << "a mirrored palindrome.";
    cout << endl << endl;
  }

  return 0;
}
