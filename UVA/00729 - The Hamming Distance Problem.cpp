#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

void backtrack(string &str, int numOfOnes, int i, int h){
  if(numOfOnes == h){
    cout << str << "\n";
    return;
  }
  if(i >= str.size()) return;
  backtrack(str, numOfOnes, i+1, h);
  str[i] = '1';
  backtrack(str, numOfOnes+1, i+1, h);
  str[i] = '0';
}

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n, h; cin >> n >> h;
    string str(n, '0');
    backtrack(str, 0, 0, h);

    if(t) cout << "\n";
  }

  return 0;
}

/*

Another way for solving the problem without recursion

#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;


int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n, h; cin >> n >> h;

    string s = "";
    for(int i=0; i<h; i++)
      s += "1";           // right 1 indexed
    for(int i=0; i<n-h; i++)
      s += "0";

    reverse(s.begin(), s.end());
    do{
      cout << s << "\n";
    } while(next_permutation(s.begin(), s.end()));

    if(t) cout << "\n";

  }

  return 0;
}

*/
