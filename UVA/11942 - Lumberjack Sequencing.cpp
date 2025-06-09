#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int N; cin >> N;

  cout << "Lumberjacks:\n";
  while(N--){

    int arr[10];
    for(int i=0; i<10; i++)
      cin >> arr[i];

    bool inc = false, dec = false;

    for(int i=1; i<10; i++){
      if(arr[i] > arr[i-1])      inc = true;
      else if(arr[i] < arr[i-1]) dec = true;

      if(inc && dec){
        cout << "Unordered\n";
        break;
      }
    }

    if(!(inc && dec))
      cout << "Ordered\n";
  }

  return 0;
}
