#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  int n, previous, next;
  int samples[10005];
  int peaks;
  while(cin >> n){
    if(!n) break;

    peaks = 0;
    for(int i=0; i<n; i++)
        cin >> samples[i];

    for(int i=0; i<n; i++){
    previous = samples[((i-1)+n)%n];
    next     = samples[(i+1)%n];

    if(samples[i] < previous && samples[i] < next ||
       samples[i] > previous && samples[i] > next) peaks++;
    }


   cout << peaks << endl;
  }
  return 0;
}
