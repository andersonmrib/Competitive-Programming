#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  int n, testCases = 0;
  double avg_con;
  bool first = true;

  while((cin >> n), n){

    vector<int> consumption(201, 0);

    if(testCases) cout << endl;

    int totalx = 0, totaly = 0;
    while(n--){
      int x, y;
      cin >> x >> y;
      totalx += x;
      totaly += y;
      consumption[y/x] += x;
    }

    printf("Cidade# %d:\n", ++testCases);
    for(int i=0; i<201; i++){
      if(consumption[i] > 0){
        if(first) first = false;
        else      cout << ' ';
        cout << consumption[i] << "-" << i;
      }
    }

    avg_con = floor(100.0*totaly/totalx)/100.0;
    printf("\nConsumo medio: %.2lf m3.\n", avg_con);
  }

  return 0;
}

