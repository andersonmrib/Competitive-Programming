#include <bits/stdc++.h>
using namespace std;

int main(){

  char puzzle[4][4], correctGrid[4][4] = {
       {'A', 'B', 'C', 'D'},
       {'E', 'F', 'G', 'H'},
       {'I', 'J', 'K', 'L'},
       {'M', 'N', 'O', 'P'}
       };

  for(int i=0; i<4; i++)
    for(int j=0; j<4; j++)
      cin >> puzzle[i][j];

  int scatter = 0;
  for(int i=0; i<4; i++)  // i and j runs through the given puzzle layout
    for(int j=0; j<4; j++)
      for(int k=0; k<4; k++) // k and l runs through the correct layout
        for(int l=0; l<4; l++)
          if(puzzle[i][j] == correctGrid[k][l] && puzzle[i][j] != '.')
            scatter += abs(i-k) + abs(j-l);

  cout << scatter << endl;

  return 0;
}
