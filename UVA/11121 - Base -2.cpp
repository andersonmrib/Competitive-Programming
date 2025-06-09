#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

string convert(int n){   // Check the end of the file for
  string str = "";       // there's an algorithm for getting
  if(n == 0) return "0"; // positive mod numbers
  while(n){              // Try to study it
    int remainder = n % -2;
    n /= -2;
    if(remainder < 0){
      remainder += 2;
      n++;
    }
    str += remainder + '0';
  }
  reverse(str.begin(), str.end());
  return str;
}

int main(){

  speedBoost;
  int N; cin >> N;
  int cases = 0;
  while(N--){

    int num; cin >> num;
    string ans = convert(num);

    printf("Case #%d: %s\n", ++cases, ans.c_str());
  }

  return 0;
}

/*

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(){

    int a, b; cin >> a >> b;
    int q, r;
    q = a/b, r = a%b;

    if(r < 0){
      if(b > 0){
        r += b;
        q -= 1;
      }
      else{
        r -= b;
        q += 1;
      }
    }
    cout << q << " " << r << "\n";

    return 0;
}

*/