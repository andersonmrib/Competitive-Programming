#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

typedef vector<int> vi;

int main(){

  speedBoost;
  int n;
  string line, dummy;
  vi idx;
  while(getline(cin, line)){

    if(line.size() == 1 || line.size() == 2){
        n = stoi(line, nullptr, 10);

        getline(cin, line);
        int x;
        stringstream ss(line);
        idx.assign(n, 0);
        for(int i=0; i<n; i++){
          ss >> x;
          idx[x-1] = i;
        }
    }

    else{

      vi query(n);
      int x;
      stringstream ss(line);
      for(int i=0; i<n; i++){
        ss >> x;
        query[x-1] = i;
      }

      vi A(n);
      for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          if(idx[j] == query[i]){
            A[i] = j;
            break;
          }
        }
      }

      int k = 0;
      vi L(n);
      for(int i=0; i<n; i++){

        int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
        L[pos] = A[i];
        if(k == pos)
          k++;
      }

      cout << k << endl;
    }
  }

  return 0;
}
