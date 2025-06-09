#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MOD 1000000007
using namespace std;

int main(){

  speedBoost;
  int t, coun = 0; cin >> t;
  while(t--){

    string A, S = ""; cin >> A;
    int len = A.size();
    int start = len % 2;      // can be even of odd

    int mid1 = len/2 - 1, mid2 = len/2;
    for(int i=0; i<len; i++){
      if(!start){
        if(A[mid2] > A[mid1])
          S += A[mid2++];
        else
          S += A[mid1--];
      }
      else{
        if(len - mid2 > mid1) // checks if we should use the bit from the right
           S += A[mid2++];
        else
          S += A[mid1--];     // or the bit from the left
      }
      start = !start;
    }

    int ans = 0;
    for(auto c : S)
      ans = (ans * 2 + (c - '0')) % MOD;

    cout << "Case #" << ++coun << ": " << ans << "\n";
  }

  return 0;
}
