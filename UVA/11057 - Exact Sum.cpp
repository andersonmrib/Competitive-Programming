#include <bits/stdc++.h>
using namespace std;
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef vector<int> vi;

int main(){
  // speedBoost;
  int n, p, m;
  string dummy;
  int p1, p2;
  while(cin >> n){
    vi vec(n);
    for(int i=0; i<n; i++){
     cin >> vec[i];
    }

    cin >> m;
    cin.ignore();
    sort(vec.begin(), vec.end());

    auto l = vec.begin(), h = prev(vec.end());
    while(l < h){
      int sum = *l + *h;
      if(sum == m){//
        p1 = *l, p2 = *h;
        l++, h--;
      }
      if(sum > m) h--;
      else        l++;
    }
  printf("Peter should buy books whose prices are %d and %d.\n\n", p1, p2);
  }

    return 0;
}
