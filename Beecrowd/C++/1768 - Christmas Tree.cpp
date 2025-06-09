#include <bits/stdc++.h>
using namespace std;

int main(){

  int n;
  while(cin >> n){

    int adjust = 0;
    int center = n/2+1;
    for(int i=1; i<n; i+=2){
      string str = "";
      int ctt = i; while(ctt) { str += "*", ctt--; }
      cout << setw(center+adjust) << right << str << endl;
      adjust++;
    }

    for(int i=0; i<n; i++)
      cout << '*';
    cout << endl;

    cout << setw(center) << right << '*' << endl;
    cout << setw(center+1) << right << "***" << endl << endl;
  }



  return 0;
}
