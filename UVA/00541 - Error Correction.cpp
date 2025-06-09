#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n;
  while((cin >> n), n){

    int mtr[n][n];
    vector<int> rowSum(n), columnSum(n);
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        cin >> mtr[i][j];
        rowSum[i] += mtr[i][j];
        columnSum[j] += mtr[i][j];
      }
    }

    int numOddRows = 0, numOddColumns = 0;
    int x = 0, y = 0;
    for(int i=0; i<n; i++){
      if((rowSum[i]&1) == 1)    { numOddRows++, x = i; }
      if((columnSum[i]&1) == 1) { numOddColumns++, y = i; }
    }

    if(!numOddRows && !numOddColumns)
      cout << "OK\n";
    else if(numOddRows == 1 && numOddColumns == 1)
      cout << "Change bit (" << ++x << "," << ++y << ")\n";
    else
      cout << "Corrupt\n";
  }

  return 0;
}
