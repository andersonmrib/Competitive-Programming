#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
using namespace std;

const int MAX = 51;
int memo[MAX][MAX];

void precompute(){
  memo[0][0] = 1;
  for(int i=1; i<MAX; i++){
    memo[i][0] = memo[i][i] = 1;
    for(int j=1; j<i; j++)
      memo[i][j] = memo[i-1][j-1] + memo[i-1][j];
  }
}

int32_t main(){

  speedBoost;
  memset(memo, -1, sizeof memo);
  precompute();

  int t; cin >> t; cin.ignore();
  int NC = 0;
  while(t--){

    string line, a, b;
    int n;
    getline(cin, line);

    for(auto &c : line)
      if(!isalpha(c) && !isdigit(c)) c = ' ';

    stringstream ss(line);
    ss >> a >> b >> n;

    cout << "Case " << ++NC << ": ";
    for(int k=0; k<=n; k++){
      int coefficient = memo[n][k];
      if(coefficient > 1) cout << coefficient << "*";

      if(n - k > 0) cout << a;
      if(n - k > 1) cout << "^" << (n - k);

      if((n - k > 0) && (k > 0)) cout << "*";

      if(k > 0) cout << b;
      if(k > 1) cout << "^" << k;

      if(k < n) cout << "+";
    }
    cout << "\n";
  }

  return 0;
}
