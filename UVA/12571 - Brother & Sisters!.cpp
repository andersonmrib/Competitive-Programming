#include <bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  while(t--){

    vector<int> vec;
    int n, q, numberN, numberQ;
    cin >> n >> q;

    for(int i=0; i<n; i++){
        cin >> numberN;
        vec.push_back(numberN);
    }

    sort(vec.rbegin(), vec.rend()); //The sorting can give us a little bit of speed

    while(q--){
        int bigger = 0, result;
        cin >> numberQ;

        for(int i=0; i<n; i++){
        result = ((vec[i]) & (numberQ));

        if(result > bigger) bigger = result;

        if(result == numberQ) break; //***** IMPORTANT: Not using this break condition will cause the cod to get TLE. The maximum value a&b can get is the result of the lowest value. So, if a = 5000 and b = 10, the maximum value of a&b can be 10, due to the binary representation *****//
    }
        cout << bigger << endl;
  }
 }
  return 0;
}
