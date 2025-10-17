#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

typedef vector<int> vi;

int main(){

  speedBoost;
  vi num(5);
  for(int i=0; i<5; i++)
    cin >> num[i];

   int c = 0, dec = 0;
   for(int i=0; i<4; i++){
    if(num[i] < num[i+1])
      c++;
    else if(num[i] > num[i+1])
      dec++;
   }

   if(c == 4) cout << "C";
   else if(dec == 4) cout << "D";
   else cout << "N";
   cout << endl;

  return 0;
}
