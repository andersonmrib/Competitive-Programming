#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

char grid[20][20];
char grid2[20][20];
int N;

bool isSame(){
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++){
      if(grid[i][j] != grid2[i][j])
        return false;
    }
    return true;
}

void rotate90(){
  char temp[20][20];
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      temp[j][N-i-1] = grid[i][j];

  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      grid[i][j] = temp[i][j];
}

void reflect(){
  char temp[20][20];
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      temp[i][j] = grid[N-i-1][j];

  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      grid[i][j] = temp[i][j];
}

int main(){

  speedBoost;
  int numCases = 0;
  while(cin >> N){

    for(int i=0; i<N; i++)
      cin >> grid[i] >> grid2[i];

    if(isSame()){
      cout << "Pattern " << ++numCases << " was preserved.\n";
      continue;
    }

    rotate90();
    if(isSame()){
      cout << "Pattern " << ++numCases << " was rotated 90 degrees.\n";
      continue;
    }

    rotate90();
    if(isSame()){
      cout << "Pattern " << ++numCases << " was rotated 180 degrees.\n";
      continue;
    }

    rotate90();
    if(isSame()){
      cout << "Pattern " << ++numCases << " was rotated 270 degrees.\n";
      continue;
    }

    rotate90();
    reflect();
    if(isSame()){
      cout << "Pattern " << ++numCases << " was reflected vertically.\n";
      continue;
    }

    rotate90();
    if(isSame()){
      cout << "Pattern " << ++numCases << " was reflected vertically and rotated 90 degrees.\n";
      continue;
    }

    rotate90();
    if(isSame()){
      cout << "Pattern " << ++numCases << " was reflected vertically and rotated 180 degrees.\n";
      continue;
    }

    rotate90();
    if(isSame()){
      cout << "Pattern " << ++numCases << " was reflected vertically and rotated 270 degrees.\n";
      continue;
    }

    else
      cout << "Pattern " << ++numCases << " was improperly transformed.\n";
  }

  return 0;
}
