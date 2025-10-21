#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

int main(){

  speedBoost;
  int l = 1, h = 1000, mid;
  string verdict;

  for(int t=0; t<10; t++){
    mid = l + (h - l)/2;
    cout << mid << endl;
    cout.flush();

    cin >> verdict;
    if(verdict[0] == 'c') return 0;
    if(verdict[0] == 'l') h = mid - 1;
    else if(verdict[0] == 'h') l = mid + 1;
  }

  return 0;
}
