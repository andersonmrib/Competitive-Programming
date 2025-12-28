#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define F(i, L, R) for(int i=L; i<R; i++)
#define FR(i, R, L) for(int i=R; i>0; i--)
#define endl "\n"

using namespace std;

const int INF = 1e9;

typedef vector<int> vi;
vector<vi> moves;
int left, middle, right;

// From left to right, using middle
// Time complexity: O(2^n), Auxiliary Space: O(n)
void moveDisks(int n, int left, int right, int middle){

  if(n == 1){
    moves.push_back({left, right});
    return;
  }

  moveDisks(n - 1, left, middle, right);
  moves.push_back({left, right});
  moveDisks(n-1, middle, right, left);
}

int main(){

  speedBoost;
  int  n; cin >> n;
  int left = 1, middle = 2, right = 3;
  moveDisks(n, left, right, middle);

  cout << moves.size() << endl;
  for(auto m : moves)
    cout << m[0] << " " << m[1] << endl;

  return 0;
}

