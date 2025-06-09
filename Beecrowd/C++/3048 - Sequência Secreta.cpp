#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 510
using namespace std;

int main(){

  int n; cin >> n;
  int arr[MAX];
  int ans = 0;

  for(int i=0; i<n; i++) cin >> arr[i];
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        int current = 0;
        int last = 0;
        for(int k=0; k<n; k++){
            if((arr[k] == arr[i] || arr[k] == arr[j]) && arr[k] != last){
                current++;
                last = arr[k];
            }
        ans = max(current, ans);
  }
        }
    }
  cout << ans << endl;

  return 0;
}
