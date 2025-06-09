#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
using namespace std;

int MOD;
const int MAX_N = 2;

struct Matrix { int mat[MAX_N][MAX_N]; };
int mod(int a, int m) { return ((a%m)+m)%m; }

Matrix matMul(Matrix a, Matrix b){
  Matrix ans;
  for(int i=0; i<MAX_N; i++)
    for(int j=0; j<MAX_N; j++)
      ans.mat[i][j] = 0;
  for(int i=0; i<MAX_N; i++)
    for(int k=0; k<MAX_N; k++){
      if(a.mat[i][k] == 0) continue;
      for(int j=0; j<MAX_N; j++){
        ans.mat[i][j] += mod(a.mat[i][k], MOD) * mod(b.mat[k][j], MOD);
        ans.mat[i][j] = mod(ans.mat[i][j], MOD);
      }
    }
    return ans;
}

Matrix matPow(Matrix base, int p){
  Matrix ans;
  for(int i=0; i<MAX_N; i++)
    for(int j=0; j<MAX_N; j++)
      ans.mat[i][j] = (i == j);
  while(p){
    if(p&1) ans = matMul(ans, base);
    base = matMul(base, base);
    p >>= 1;
  }
  return ans;
}

int32_t main(){

  speedBoost;
  int n, m;
  while(cin >> n >> m){

    Matrix ans;
    ans.mat[0][0] = 1; ans.mat[0][1] = 1;
    ans.mat[1][0] = 1; ans.mat[1][1] = 0;
    MOD = 1;
    for(int i=0; i<m; i++)
      MOD *= 2;
    ans = matPow(ans, n);
    cout << ans.mat[0][1] << "\n";
  }


  return 0;
}
