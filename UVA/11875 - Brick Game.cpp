#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

 speedBoost;
 int T; cin >> T;
 int numCases = 0;
 while(T--){
   int N; cin >> N;
   vector<int> vec(N);
   for(int i=0; i<N; i++)
     cin >> vec[i];

   sort(vec.begin(), vec.end());
   printf("Case %d: %d\n", ++numCases, vec[N/2]);
 }

  return 0;
}
