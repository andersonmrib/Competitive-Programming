#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

vector<string> fib;

string add(const string a, const string b){
  string newNumber = "";
  int i = a.size() - 1, j = b.size() - 1;
  int carry = 0, dig1, dig2, sum, add;
  while(i >= 0 || j >= 0 || carry){

    dig1 = (i >= 0) ? a[i--] - '0' : 0;
    dig2 = (j >= 0) ? b[j--] - '0' : 0;
    sum = dig1 + dig2 + carry;
    carry = sum / 10;
    add = sum % 10;
    newNumber.push_back(add + '0');
  }
  reverse(newNumber.begin(), newNumber.end());
  return newNumber;
}

void build(){
  string a = "0", b = "1";
  fib.push_back("0"), fib.push_back("1");

  while(fib.back().size() <= 1000){
    string next = add(a, b);
    a = b;
    b = next;
    fib.push_back(next);
  }
}

int main(){

  speedBoost;
  build();

  int n;
  while(cin >> n){
    cout << fib[n] << "\n";
  }

  return 0;
}
