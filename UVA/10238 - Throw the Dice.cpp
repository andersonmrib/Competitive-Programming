#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp> // !
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
using boost::multiprecision::cpp_int; // !

int f, n, s;
cpp_int memo[51][4001];
bool vis[51][4001];

cpp_int dp(int dice_left, int score){
  if(dice_left == 0) return score == 0 ? 1 : 0;
  if(score < 0) return 0;

  if(vis[dice_left][score]) return memo[dice_left][score];
  vis[dice_left][score] = true;

  cpp_int ans = 0;
  for(int i=1; i<=f; i++)
    ans += dp(dice_left - 1, score - i);

  return memo[dice_left][score] = ans;
}

// For some reason, at this date 10/23/2025 UVa and VJudge
// are accepting the usage of the library Boost.
// Gotta check this exercise in the future since my
// python code is way too slow and the creation of pure hand made BigInteger
// functions in C++ looks too dense and time consuming.

int main(){

  speedBoost;
  while (cin >> f >> n >> s){
    memset(vis, 0, sizeof(vis));

    cpp_int num = dp(n, s);
    cpp_int den = 1;

    for (int i=0; i<n; i++)
        den *= f;

    cout << num << "/" << den << "\n";
  }

  return 0;
}
