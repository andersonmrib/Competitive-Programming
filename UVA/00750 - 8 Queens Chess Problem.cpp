#include <bits/stdc++.h>
using namespace std;

int row[8], a, b, lineCounter;

bool canPlace(int r, int c){
  for(int prev=0; prev<c; prev++)  // going to check previous queens
    if((row[prev] == r) || (abs(row[prev]-r) == abs(prev-c)))
      return false;                // there's a queen in the same diagonal or row/column
  return true;
}

void backtrack(int c){
  if((c == 8) && row[b] == a){     // a candidate solution
    printf("%2d      %d", ++lineCounter, row[0]+1);
    for(int j=1; j<8; j++) printf(" %d", row[j]+1);
    printf("\n");
    return;
  }
  for(int r=0; r<8; r++){
    if((c == b) && (r != a)) continue;
    if(canPlace(r, c))
      row[c] = r, backtrack(c+1);
  }
}

int main(){

  int t; cin >> t;
  while(t--){
    cin >> a >> b; a--; b--;       // going to work with index 0
    memset(row, 0, sizeof row); lineCounter = 0;
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    backtrack(0);
    if(t) cout << endl;
  }
    return 0;
}
