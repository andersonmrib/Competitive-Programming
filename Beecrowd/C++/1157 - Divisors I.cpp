#include <bits/stdc++.h>
using namespace std;

int main(){

  int n; cin >> n;

  for(int x=1; x<=n; x++)
    if(!(n%x)) cout << x << endl;

  return 0;
}
