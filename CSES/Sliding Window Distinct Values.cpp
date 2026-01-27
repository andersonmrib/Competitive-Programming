#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

struct custom_hash{
  static uint64_t splitmix64(uint64_t x){
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const{
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
      return splitmix64(x + FIXED_RANDOM);
  }
};

int32_t main(){

  speedBoost;
  int n, k; cin >> n >> k;

  vi vec(n);
  for(int i=0; i<n; i++)
    cin >> vec[i];

  unordered_map<int, int, custom_hash> freq;
  int dist = 0;

  for(int i=0; i<k; i++){
    if(freq[vec[i]] == 0) dist++;
    freq[vec[i]]++;
  }

  cout << dist;
  for(int i=1; i<n-k+1; i++){

    int leaving  = vec[i-1];
    int entering = vec[i+k-1];

    freq[leaving]--;
    if(freq[leaving] == 0) dist--;

    if(freq[entering] == 0) dist++;
    freq[entering]++;

    cout << " " << dist;
  }

  cout << endl;

  return 0;
}
