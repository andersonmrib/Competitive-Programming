#include <bits/stdc++.h>
#define speedBoost ios_sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){
    
  char a[300], b[300], op;
  while(cin >> a >> op >> b){
    cout << a << " " << op << " " << b << "\n"; 
    double sum1 = atof(a), sum2 = atof(b);
    if(sum1 > INT_MAX) cout << "first number too big\n";
    if(sum2 > INT_MAX) cout << "second number too big\n";
    if(op == '+' && sum1 + sum2 > INT_MAX
    || op == '*' && sum1 * sum2 > INT_MAX)
      cout << "result too big\n";
  }
    
  return 0;    
}