#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int mtr[9][9];

bool checkLine(int idx){
  unordered_set<int> nums;
  for(int i=0; i<9; i++)
    nums.insert(mtr[idx][i]);
  return nums.size() == 9;
}

bool checkColumn(int idx){
  unordered_set<int> nums;
  for(int i=0; i<9; i++)
    nums.insert(mtr[i][idx]);
  return nums.size() == 9;
}

bool checkSquare(int idx){
  unordered_set<int> nums;
  int r = (idx/3) * 3, c = (idx%3) * 3;
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      nums.insert(mtr[i+r][j+c]);
    }
  }
  return nums.size() == 9;
}

int main(){

  speedBoost;
  int t; cin >> t;
  int NC = 0;
  while(t--){

    for(int i=0; i<9; i++)
      for(int j=0; j<9; j++)
        cin >> mtr[i][j];

    bool hasSolution = true;
    for(int i=0; i<9; i++){
      if(!checkLine(i) || !checkColumn(i) || !checkSquare(i)){
        hasSolution = false;
        break;
      }
    }

    cout << "Instancia " << ++NC << "\n";
    if(!hasSolution) cout << "NAO\n\n";
    else             cout << "SIM\n\n";
  }

  return 0;
}
