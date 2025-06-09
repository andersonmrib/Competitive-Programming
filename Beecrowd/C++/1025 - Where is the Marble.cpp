#include <bits/stdc++.h>
using namespace std;

int main(){

  vector<int> marbles;
  int n, q;
  int numCases = 0;
  while((cin >> n >> q), n, q){

    int value, querie;
    marbles.clear();
    for(int i=0; i<n; i++)
      cin >> value, marbles.push_back(value);

    sort(marbles.begin(), marbles.end());

    printf("CASE# %d:\n", ++numCases);

    while(q--){
      cin >> querie;
      auto it = lower_bound(marbles.begin(), marbles.end(), querie);  // simply binary search

      if((*it != querie) || (it == marbles.end())) printf("%d not found\n", querie);
      else                                         printf("%d found at %d\n", querie, (it - marbles.begin()) + 1); // index position can be obtained like this
    }
  }
    return 0;
}
