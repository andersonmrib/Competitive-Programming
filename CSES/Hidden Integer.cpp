#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
using namespace std;

int main(){

  int l = 1, h = 1e9;
  int mid;
  string judge;
  for(int i=0; i<30; i++){
    mid = (l + h)/2;
    cout << "? " << mid << endl;
    cout.flush();

    cin >> judge;
    if(judge == "YES")
      l = mid + 1;
    else
      h = mid;
  }

  cout << "! " << l << endl;
  cout.flush();

  return 0;
}
