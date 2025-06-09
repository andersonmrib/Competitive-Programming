#include <bits/stdc++.h>
using namespace std;

int main(){

  int n, goodOnes = 0;
  cin >> n;
  int total = n;
  set<string> names;
  while(n--){
    char behavior; string name;

    cin >> behavior >> name;

    if(behavior == '+') goodOnes++;
    names.insert(name);
  }

  for(auto n : names) cout << n << endl;
  printf("Se comportaram: %d | Nao se comportaram: %d\n", goodOnes, total-goodOnes);

  return 0;
}
