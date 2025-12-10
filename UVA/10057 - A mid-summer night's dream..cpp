#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
using namespace std;

int main(){

  speedBoost;
  int n;
  while(cin >> n){

    vector<int> nums(n);
    for(int i=0; i<n; i++)
      cin >> nums[i];

    sort(nums.begin(), nums.end());

    int med_idx1 = (n-1)/2, med_idx2 = n/2;
    int med1 = nums[med_idx1];
    int med2 = nums[med_idx2];

    int min_val = med1;

    int ctt = 0;
    for(auto x : nums)
      if(x == med1 || x == med2)
        ctt++;

    int possible = (med1 == med2) ? 1 : (med2 - med1 + 1);

    cout << min_val << " " << ctt << " " << possible << endl;
  }

  return 0;
}
